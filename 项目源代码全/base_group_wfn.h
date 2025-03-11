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
	void add_member(int);//邀请入群
	//隐式入群
	void no_output_add_member(int);
	void enter_group(int);//进群
	//获取数值
	int get_group_id();
	vector<int> get_member_id();
	int get_groupowner_id();
	//踢人
	virtual int delete_member() = 0;
	virtual void delete_member(int) = 0;

	void output_member_id();//展示群成员id
	//设置数值
	void set_group_id(int);
	void set_groupowner_id(int);
protected:
	int groupId;//群账号
	int groupOwnerId;//群主账号
};
#endif
