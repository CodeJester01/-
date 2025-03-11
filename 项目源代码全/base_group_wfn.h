#ifndef BASE_GROUP_CDY_H
#define BASE_GROUP_WFN_H
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

class base_group_wfn {
public:
	base_group_wfn();
	virtual ~base_group_wfn();
	vector<int>memberId;

	virtual int set_group(int) = 0;
	virtual void show_group_infor() = 0;

	int add_member();
	void add_member(int);//������Ⱥ
	//��ʽ��Ⱥ
	void no_output_add_member(int);
	void enter_group(int);//��Ⱥ
	//��ȡ��ֵ
	int get_group_id();
	vector<int> get_member_id();
	int get_groupowner_id();
	//����
	virtual int delete_member() = 0;
	virtual void delete_member(int) = 0;

	void output_member_id();//չʾȺ��Աid
	//������ֵ
	void set_group_id(int);
	void set_groupowner_id(int);
protected:
	int groupId;//Ⱥ�˺�
	int groupOwnerId;//Ⱥ���˺�
};
#endif
