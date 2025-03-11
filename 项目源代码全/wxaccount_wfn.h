#ifndef WXACCOUNT_WFN_H
#define WXACCOUNT_WFN_H
#include "base_account_wfn.h"
#pragma once

using namespace std;
class wxaccount_wfn :public base_account_wfn {
private:
	int qqid;
public:
	wxaccount_wfn() {
		wxnumber++;
		islogin = 0;
		qqid = 0;
	};
	virtual ~wxaccount_wfn() {
	};
	static int wxnumber;
	void set_wx();
	void show_information();
	int get_qqid();
	void set_qqid(int);
};

#endif

