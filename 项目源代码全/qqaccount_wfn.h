#ifndef QQACCOUNT_WFN_H
#define QQACCOUNT_WFN_H

#include "base_account_wfn.h"
#include "wbaccount_wfn.h"
using namespace std;

class qqaccount_wfn :public base_account_wfn {
private:
    int is_setwb;
    int wxid;
public:
    static int qqNumber;
    qqaccount_wfn();
    virtual ~qqaccount_wfn();
    void set_qq();
    virtual void show_information();
    void set_connect_weibo();
    void set_weibo_id(int);
    void set_wxid(int);
    int get_weibo_id();
    int get_wxid();
};

#endif
