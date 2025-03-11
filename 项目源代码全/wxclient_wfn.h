#pragma once
#ifndef WXCLIENT_WFN_H
#define WXCLIENT_WFN_H
#include<iostream>
#include<fstream>               //文件写入头文件
#include<string>                //字符串处理头文件
#include<vector>                //向量使用头文件
#include<cstdlib>               //与清屏函数有关的头文件
using namespace std;
#include"wxaccount_wfn.h"
#include"wxgroup_wfn.h"


class wxclient_wfn {
public:
    wxclient_wfn();
    virtual ~wxclient_wfn();

    vector<wxaccount_wfn>weixinClient;
    vector<wxgroup_wfn>weixinGroup;

    void set_new_weixin_group(int);
    void set_new_weixin_account();

    void show_weixin_infor(int);
    void show_group_infor(int);
    void chaxun_friend(int);

    void change_weixin_infor(int);

    void add_friend(int);
    void delete_friend(int);
    void enter_group(int);
    void exit_group(int);

    int judge_groupid_exist(int id);

    void initialise_weixin(int);//初始化
    void initialise_weixin_group(int);
};

#endif 
