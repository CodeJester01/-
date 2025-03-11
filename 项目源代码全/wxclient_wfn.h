#pragma once
#ifndef WXCLIENT_WFN_H
#define WXCLIENT_WFN_H
#include<iostream>
#include<fstream>               //�ļ�д��ͷ�ļ�
#include<string>                //�ַ�������ͷ�ļ�
#include<vector>                //����ʹ��ͷ�ļ�
#include<cstdlib>               //�����������йص�ͷ�ļ�
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

    void initialise_weixin(int);//��ʼ��
    void initialise_weixin_group(int);
};

#endif 
