#pragma once
#ifndef QQGROUP_WFN_H
#define QQGROUP_WFN_H
#include<string>                //�ַ�������ͷ�ļ�
#include<vector>                //����ʹ��ͷ�ļ�
#include<cstdlib>               //�����������йص�ͷ�ļ�
using namespace std;
#include "base_group_wfn.h"


class qqgroup_wfn : public base_group_wfn
{
public:
    qqgroup_wfn();
    virtual ~qqgroup_wfn();

    static int qqGroupNumber;//Ⱥ����
    static int sonGroupNumber;//��Ⱥ����ʱ�����飩����

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

