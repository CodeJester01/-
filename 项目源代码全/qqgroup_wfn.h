#pragma once
#ifndef QQGROUP_WFN_H
#define QQGROUP_WFN_H
#include<string>                //字符串处理头文件
#include<vector>                //向量使用头文件
#include<cstdlib>               //与清屏函数有关的头文件
using namespace std;
#include "base_group_wfn.h"


class qqgroup_wfn : public base_group_wfn
{
public:
    qqgroup_wfn();
    virtual ~qqgroup_wfn();

    static int qqGroupNumber;//群数量
    static int sonGroupNumber;//子群（临时讨论组）数量

    int set_group(int);
    void set_admin();
    void set_father_group_id(int);
    void no_output_set_admin(int);
    
    void show_group_infor();

    void delete_admin();
    int delete_member();
    void delete_member(int);

    void show_son_group_infor();

    int get_father_group_id();
    vector<int> get_son_group_id();
    vector<int> get_admin_id();
protected:
    vector<int>adminId;
    string groupType;
    vector<int>sonGroupId;
    int fatherGroupId;
private:
};

#endif 

