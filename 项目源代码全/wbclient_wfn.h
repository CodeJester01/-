#ifndef WBCLIENT_WFN_H
#define WBCLIENT_WFN_H
#include<iostream>
#include<fstream>               //�ļ�д��ͷ�ļ�
#include<string>                //�ַ�������ͷ�ļ�
#include<vector>                //����ʹ��ͷ�ļ�
#include<cstdlib>               //�����������йص�ͷ�ļ�
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
    void initialise_weibo(int);//��ʼ��
    void show_weibo_infor(int);
    void change_weibo_infor(int);
    void chaxun_friend(int);
protected:

private:
};

#endif 
