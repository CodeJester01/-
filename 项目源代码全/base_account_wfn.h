#ifndef BASE_ACCOUNT_WFN_H
#define BASE_ACCOUNT_WFN_H
#pragma once

#include <string>
#include <vector>
#include "date.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <fstream>

using namespace std;

class base_account_wfn {
protected:
    long long ID;//账号
    string password;//密码
    int islogin;//表示是否登录
    string name;//用户昵称
    date registrate_date;//注册时间 
    date birthday;//生日
    string location;//所在地
    int friend_num;//好友数量
    int qun_num;//群数量
    vector<int> friend_list;//好友列表
    vector<int> group_list;//群列表

public:
    base_account_wfn();//构造函数
    ~base_account_wfn();//析构函数
    void login(string);//登录
    void no_output_login();//隐式登录
    void change_information();//修改信息
    virtual void show_information() = 0;//展示信息，为虚函数

    int add_friend(int);//添加好友
    int no_output_add_friend(int);
    int delete_friend(int);//删除好友
    int no_output_delete_friend(int);

    int enter_group(int);//加群
    void no_output_enter_group(int);
    int exit_group(int);//退群
    int no_output_exit_group(int);

    //获取信息
    int get_id();
    date get_birthday();
    date get_registrate_date();
    string get_name();
    string get_location();
    vector<int> get_friendlist();
    vector<int> get_grouplist();
    string get_password();
    int get_islogin();

    //设置信息
    void set_id(int);
    void set_name(string);
    void set_birthday(int, int, int);
    void set_settime(int, int, int);
    void set_location(string);
    void set_password(string);
};

#endif


