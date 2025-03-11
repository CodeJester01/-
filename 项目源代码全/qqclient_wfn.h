#ifndef QQCLIENT_WFN_H
#define QQCLIENT_WFN_H
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include "date.h"
#include "qqaccount_wfn.h"
#include "qqgroup_wfn.h"
#include "base_account_wfn.h"

using namespace std;

class qqclient_wfn {
public:
    qqclient_wfn();
    virtual ~qqclient_wfn();
    vector<qqaccount_wfn>qqvector;
    vector<qqgroup_wfn>qqgroup;

    void set_new_QQ_group(int);//创建
    void set_new_son_group(int, int);
    void set_new_QQ_account();
    void set_admin(int);
    void set_son_group(int);

    void show_QQ_infor(int);//显示信息
    void show_group_infor(int);
    void show_son_group_infor(int);
    void chaxun_friend(int);

    void change_QQ_infor(int);

    void add_friend(int);//增删朋友，群组
    void delete_friend(int);
    void enter_group(int);
    void exit_group(int);

    int judge_groupid_exist(int id);

    void initialise_QQ(int);//初始化
    void initialise_qq_group(int);
};


#endif

