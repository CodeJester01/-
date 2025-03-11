#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

mutex coutMutex; // 控制台输出锁
atomic<bool> clientRunning{ true }; // 客户端运行标志

// 接收服务器消息的线程函数
void ReceiveHandler(SOCKET socket) {
    char buffer[1024];
    while (clientRunning.load()) {
        int ret = recv(socket, buffer, sizeof(buffer) - 1, 0);
        if (ret > 0) {
            buffer[ret] = '\0';
            lock_guard<mutex> lock(coutMutex);
            cout << "\n[服务器]: " << buffer << endl;
        }
        else if (ret == 0) {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n服务器已断开连接。" << endl;
            clientRunning = false;
            break;
        }
        else {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n接收消息失败。" << endl;
            clientRunning = false;
            break;
        }
    }
}

// 发送消息到服务器的线程函数
void SendHandler(SOCKET socket) {
    string message;
    while (clientRunning.load()) {
        {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n[客户端] 请输入消息（输入 /quit 断开连接）：";
        }
        getline(cin, message);
        if (message == "/quit") {
            clientRunning = false;
            shutdown(socket, SD_BOTH); // 关闭套接字的发送和接收
            closesocket(socket);       // 释放套接字资源
            break;
        }
        if (send(socket, message.c_str(), message.size(), 0) == SOCKET_ERROR) {
            lock_guard<mutex> lock(coutMutex);
            cout << "\n发送消息失败。" << endl;
            clientRunning = false;
            break;
        }
    }
}

int main() {
    // 初始化Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup失败" << endl;
        return 1;
    }

    // 创建客户端套接字
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "套接字创建失败" << endl;
        WSACleanup();
        return 1;
    }

    // 设置服务器地址
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888); // 服务器端口
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // 服务器IP

    // 连接到服务器
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "连接服务器失败" << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "已连接到服务器，可以开始通信。" << endl;

    // 启动接收和发送线程
    thread receiveThread(ReceiveHandler, clientSocket);
    thread sendThread(SendHandler, clientSocket);

    // 等待线程结束
    receiveThread.join();
    sendThread.join();

    // 关闭套接字并清理Winsock
    closesocket(clientSocket);
    WSACleanup();

    cout << "客户端已退出。" << endl;
    return 0;
}