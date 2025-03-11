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
    long long ID;//�˺�
    string password;//����
    int islogin;//��ʾ�Ƿ��¼
    string name;//�û��ǳ�
    date registrate_date;//ע��ʱ�� 
    date birthday;//����
    string location;//���ڵ�
    int friend_num;//��������
    int qun_num;//Ⱥ����
    vector<int> friend_list;//�����б�
    vector<int> group_list;//Ⱥ�б�

public:
    base_account_wfn();//���캯��
    ~base_account_wfn();//��������
    void login(string);//��¼
    void no_output_login();//��ʽ��¼
    void change_information();//�޸���Ϣ
    virtual void show_information() = 0;//չʾ��Ϣ��Ϊ�麯��

    int add_friend(int);//��Ӻ���
    int no_output_add_friend(int);
    int delete_friend(int);//ɾ������
    int no_output_delete_friend(int);

    int enter_group(int);//��Ⱥ
    void no_output_enter_group(int);
    int exit_group(int);//��Ⱥ
    int no_output_exit_group(int);

    //��ȡ��Ϣ
    int get_id();
    date get_birthday();
    date get_registrate_date();
    string get_name();
    string get_location();
    vector<int> get_friendlist();
    vector<int> get_grouplist();
    string get_password();
    int get_islogin();

    //������Ϣ
    void set_id(int);
    void set_name(string);
    void set_birthday(int, int, int);
    void set_settime(int, int, int);
    void set_location(string);
    void set_password(string);
};

#endif


