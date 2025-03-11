#define _CRT_SECURE_NO_WARNINGS
#include "wbclient_wfn.h"

int kmp2(string str1, string str2);

int wbclient_wfn::wbnumber = 0;

wbclient_wfn::wbclient_wfn()
{
    //ctor
}

wbclient_wfn::~wbclient_wfn()
{
    //dtor
}
//创建新微博账号
void wbclient_wfn::set_new_weibo_account() {
    wbaccount_wfn newWeibo;
    newWeibo.set_wb();
    wbClient.push_back(newWeibo);
}
//展示微博用户信息
void wbclient_wfn::show_weibo_infor(int weiboId) {
    int i;
    for (i = 0; i < wbClient.size(); i++) {
        cout << wbClient[i].get_id() << endl;
        if (wbClient[i].get_id() == weiboId) {
            wbClient[i].show_information();
            return;
        }
    }
    cout << "    该用户不存在！！" << endl;
}
//修改微博账号信息
void wbclient_wfn::change_weibo_infor(int id) {
    int i;
    for (i = 0; i < wbClient.size(); i++) {
        if (wbClient[i].get_id() == id) {
            wbClient[i].change_information();
            return;
        }
    }
    cout << "    该用户不存在！" << endl;
}
//添加好友
void wbclient_wfn::add_friend(int id) {
    int i, j, number;
    for (i = 0; i < wbClient.size(); i++) {
        if (wbClient[i].get_id() == id) {
            cout << "    请输入想要加为好友的微博账号：" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < wbClient.size(); j++) {
                //cout<<"测试:"<<weixinClient[j].getQQid()<<endl;
                if (wbClient[j].get_id() == number) {
                    if (wbClient[i].add_friend(number))
                        wbClient[j].no_output_add_friend(id);
                    else
                        cout << "    添加好友失败！" << endl;
                    return;
                }
            }
            cout << "    该用户不存在!" << endl;
            return;
        }
    }
}
//删除好友
void wbclient_wfn::delete_friend(int id) {
    int i, j, number;
    for (i = 0; i < wbClient.size(); i++) {
        if (wbClient[i].get_id() == id) {
            cout << "    请输入想要删除好友的微博账号：" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < wbClient.size(); j++) {
                if (wbClient[j].get_id() == number) {
                    if (wbClient[i].delete_friend(number)) {
                        wbClient[j].no_output_delete_friend(id);
                        return;
                    }
                    else {
                        cout << "    删除好友失败！" << endl;
                        return;
                    }
                }
            }
            cout << "    该用户不存在!" << endl;
            return;
        }
    }
}
void wbclient_wfn::chaxun_friend(int QQid) {
    int i, j, number, choose, cnt;
    string str;
    for (i = 0; i < wbClient.size(); i++) {
        if (wbClient[i].get_id() == QQid) {
            cout << "    选择你的查询方式：1.按账号查询   2.按用户名关键词查询" << endl << "    ";
            cin >> choose;
            if (choose == 1) {
                cout << "    请输入想要查找的好友的微博账号：" << "    ";
                cin >> number;
                setbuf(stdin, NULL);
                for (j = 0; j < wbClient.size(); j++) {
                    if (wbClient[j].get_id() == number) {
                        cout << "    " << wbClient[j].get_name() << "        " << wbClient[j].get_id() << endl;
                    }
                    return;
                }
                cout << "    该用户不存在!" << endl;
                return;
            }
            if (choose == 2) {
                cout << "    请输入想要查找的好友的qq用户名关键词：" << "    ";
                cin >> str;
                cnt = 0;
                for (j = 0; j < wbClient.size(); j++) {
                    if (kmp2(wbClient[j].get_name(), str)) {
                        cout << wbClient[j].get_name() << "        " << wbClient[j].get_id() << endl;
                        cnt++;
                    }
                }
                if (cnt == 0) {
                    cout << "    该用户不存在!" << endl;
                }
                return;
            }
        }
    }
}

//初始化
void wbclient_wfn::initialise_weibo(int weiboNumber) {
    for (int i = 0; i < weiboNumber; i++) {
        wbaccount_wfn temp;
        wbClient.push_back(temp);
    }
}

int kmp2(string str1, string str2) {
    int i = 0, j = 0;
    int* p = new int[str2.size()];
    int k, m;
    m = str2.length();
    p[0] = -1;
    for (j = 1; j < m; j++) {
        k = p[j - 1];
        while (str1[j] != str1[k + 1] && k >= 0) {
            k = p[k];
        }
        if (str1[j] == str1[k + 1]) p[j] = k + 1;
        else p[j] = -1;
    }
    j = 0;
    while (i < str1.length() && j < str2.length()) {
        if (str1[i] == str2[j]) {
            i++; j++;
        }
        else {
            if (j == 0) i++;
            else j = p[j - 1] + 1;
        }
    }
    if (j < str2.length()) {
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}

