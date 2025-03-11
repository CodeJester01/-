#pragma once
#ifndef WXGROUP_WFN_H
#define WXGROUP_WFN_H

#include "base_group_wfn.h"


class wxgroup_wfn : public base_group_wfn {
public:
    wxgroup_wfn();
    virtual ~wxgroup_wfn();
    static int wxgroupNumber;
    int set_group(int);
    void show_group_infor();
    int delete_member();
    void delete_member(int);
protected:

private:
};

#endif 
