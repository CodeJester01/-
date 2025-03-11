#ifndef WBACCOUNT_WFN_H
#define WBACCOUNT_WFN_H
#include "base_account_wfn.h"
#pragma once

class wbaccount_wfn : public base_account_wfn {
public:
    wbaccount_wfn();
    virtual ~wbaccount_wfn();
    void show_information();
    void set_wb();
    static int wbnumber;
    int get_qqid();
    void set_qqid(int);
private:
    int qqid;
};
#endif

