#ifndef WBCLIENT_WFN_H
#define WBCLIENT_WFN_H
#include<iostream>
#include<fstream>               //文件写入头文件
#include<string>                //字符串处理头文件
#include<vector>                //向量使用头文件
#include<cstdlib>               //与清屏函数有关的头文件
using namespace std;
#include"wbaccount_wfn.h"

class wbclient_wfn
{
public:
    wbclient_wfn();
    virtual ~wbclient_wfn();
    vector<wbaccount_wfn>wbClient;
    static int wbnumber;
    void add_friend(int);
    void delete_friend(int);
    void set_new_weibo_account();
    void initialise_weibo(int);//初始化
    void show_weibo_infor(int);
    void change_weibo_infor(int);
    void chaxun_friend(int);
protected:

private:
};

#endif 
