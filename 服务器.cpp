#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <algorithm>
#include<string>
#include<cstdio>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

// 客户端信息结构体
struct ClientInfo {
    SOCKET socket;
    string ip;
    int port;
    thread receive_thread;
    thread send_thread;                                                       
    atomic<bool> active;

    // 删除拷贝构造函数和拷贝赋值运算符
    ClientInfo(const ClientInfo&) = delete;
    ClientInfo& operator=(const ClientInfo&) = delete;

    // 提供移动构造函数和移动赋值运算符
    ClientInfo(ClientInfo&& other) noexcept
        : socket(other.socket), ip(move(other.ip)), port(other.port),
        receive_thread(move(other.receive_thread)),
        send_thread(move(other.send_thread)),
        active(other.active.load()) {
        other.socket = INVALID_SOCKET;
        other.active = false;
    }

    ClientInfo& operator=(ClientInfo&& other) noexcept {
        if (this != &other) {
            socket = other.socket;
            ip = move(other.ip);
            port = other.port;
            receive_thread = move(other.receive_thread);
            send_thread = move(other.send_thread);
            active = other.active.load();
            other.socket = INVALID_SOCKET;
            other.active = false;
        }
        return *this;
    }

    // 默认构造函数
    ClientInfo(SOCKET sock, string ipAddr, int p)
        : socket(sock), ip(move(ipAddr)), port(p), active(true) {
    }
};

mutex coutMutex;        // 控制台输出锁
mutex clientsMutex;     // 客户端列表锁
vector<ClientInfo> clients; // 客户端列表
atomic<bool> serverRunning{ true }; // 服务器运行标志

// 改进的客户端消息接收处理
void ClientReceiveHandler(ClientInfo& client) {
    char buffer[1024];
    while (client.active.load()) {
        int ret = recv(client.socket, buffer, sizeof(buffer) - 1, 0);
        if (ret > 0) {
            buffer[ret] = '\0';
            lock_guard<mutex> lock(coutMutex);
            cout << "\n[来自 " << client.ip << ":" << client.port << "] " << buffer << endl;
        }
        else if (ret == 0) {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n客户端 " << client.ip << ":" << client.port << " 已断开连接。" << endl;
            client.active = false;
            break;
        }
        else {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n接收消息失败。" << endl;
            client.active = false;
            break;
        }
    }
}
// 统一的服务器控制台输入处理
void ServerInputHandler() {
    string input;
    while (serverRunning.load()) {
        // 显示命令菜单
        {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n[服务器命令] list | send <ID> <msg> | broadcast <msg> | quit : ";
        }

        getline(cin, input);
        if (input.empty()) continue;

        if (input == "quit") {
            serverRunning = false;
            break;
        }
        else if (input == "list") {
            lock_guard<mutex> lock(clientsMutex);
            cout << "\n当前在线客户端 (" << clients.size() << "):\n";
            for (size_t i = 0; i < clients.size(); ++i) {
                cout << "[" << i << "] " << clients[i].ip << ":"
                    << clients[i].port << endl;
            }
        }
        else if (input.find("send ") == 0) {
            size_t space1 = input.find(' ', 5);
            if (space1 != string::npos) {
                int id = stoi(input.substr(5, space1 - 5));
                string msg = input.substr(space1 + 1);

                lock_guard<mutex> lock(clientsMutex);
                if (id >= 0 && id < clients.size() && clients[id].active.load()) {
                    send(clients[id].socket, msg.c_str(), msg.size(), 0);
                }
            }
        }
        else if (input.find("broadcast ") == 0) {
            string msg = input.substr(10);
            lock_guard<mutex> lock(clientsMutex);
            for (auto& c : clients) {
                if (c.active.load()) {
                    send(c.socket, msg.c_str(), msg.size(), 0);
                }
            }
        }
    }
}

void CleanupClients() {
    lock_guard<mutex> lock(clientsMutex);

    // 将需要清理的客户端移到容器末尾
    auto it = partition(clients.begin(), clients.end(), [](const ClientInfo& c) {
        return c.active.load(); // 活跃客户端留在前面
        });

    // 清理非活跃客户端
    for (auto dead = it; dead != clients.end(); ++dead) {
        shutdown(dead->socket, SD_BOTH);
        closesocket(dead->socket);
        if (dead->receive_thread.joinable()) {
            dead->receive_thread.join(); // 正确：dead 是非 const 迭代器
        }
    }

    // 删除非活跃客户端
    clients.erase(it, clients.end());
}
int main() {
    // Winsock初始化
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 创建监听套接字
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, SOMAXCONN);

    // 启动控制台输入线程
    thread inputThread(ServerInputHandler);

    // 主循环
    while (serverRunning.load()) {
        // 非阻塞accept
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(serverSocket, &readSet);
        timeval timeout{ 0, 100000 }; // 100ms

        if (select(0, &readSet, nullptr, nullptr, &timeout) > 0) {
            sockaddr_in clientAddr{};
            int addrLen = sizeof(clientAddr);
            SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &addrLen);

            // 获取客户端信息
            char clientIP[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, sizeof(clientIP));
            int clientPort = ntohs(clientAddr.sin_port);

            // 添加到客户端列表
            lock_guard<mutex> lock(clientsMutex);
            clients.emplace_back(clientSocket, clientIP, clientPort);
            clients.back().receive_thread = thread(ClientReceiveHandler, ref(clients.back()));
            clients.back().receive_thread.detach();
        }

        // 定期清理断开的客户端
        CleanupClients();
    }

    // 清理资源
    serverRunning = false;
    inputThread.join();
    CleanupClients();
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}