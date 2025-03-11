#include "base_group_wfn.h"

base_group_wfn::base_group_wfn() {}

base_group_wfn::~base_group_wfn() {}

//邀请入群
int base_group_wfn::add_member() {
    int temp;
    int i;
    std::cout << "    请输入想要拉入群的账号：" << "    ";
    cin >> temp;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == temp) {
            cout << "    此人已在群中！" << endl;
            return 0;
        }
    }
    memberId.push_back(temp);
    cout << "    已成功拉入群中！" << endl;
    return temp;
}
//入群
void base_group_wfn::add_member(int pid) {
    memberId.push_back(pid);
}

//进群
void base_group_wfn::enter_group(int id) {
    int i;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == id) {
            cout << "    你已经在这个群中！" << endl;
            return;
        }
    }
    memberId.push_back(id);
}

//展示群成员id
void base_group_wfn::output_member_id() {
    for (int i = 0; i < memberId.size(); i++) {
        cout << memberId[i] << endl;
    }
}
//设置群id
void base_group_wfn::set_group_id(int pid) {
    groupId = pid;
}
//设置群主
void base_group_wfn::set_groupowner_id(int pid) {
    groupOwnerId = pid;
}
//隐式入群
void base_group_wfn::no_output_add_member(int pid) {
    memberId.push_back(pid);
}
//获取群id
int base_group_wfn::get_group_id() {
    return groupId;
}
//获取群主id
int base_group_wfn::get_groupowner_id() {
    return groupOwnerId;
}
//获取群成员id
vector<int> base_group_wfn::get_member_id() {
    return memberId;
}

