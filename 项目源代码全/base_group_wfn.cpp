#include "base_group_wfn.h"

base_group_wfn::base_group_wfn() {}

base_group_wfn::~base_group_wfn() {}

//������Ⱥ
int base_group_wfn::add_member() {
    int temp;
    int i;
    std::cout << "    ��������Ҫ����Ⱥ���˺ţ�" << "    ";
    cin >> temp;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == temp) {
            cout << "    ��������Ⱥ�У�" << endl;
            return 0;
        }
    }
    memberId.push_back(temp);
    cout << "    �ѳɹ�����Ⱥ�У�" << endl;
    return temp;
}
//��Ⱥ
void base_group_wfn::add_member(int pid) {
    memberId.push_back(pid);
}

//��Ⱥ
void base_group_wfn::enter_group(int id) {
    int i;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == id) {
            cout << "    ���Ѿ������Ⱥ�У�" << endl;
            return;
        }
    }
    memberId.push_back(id);
}

//չʾȺ��Աid
void base_group_wfn::output_member_id() {
    for (int i = 0; i < memberId.size(); i++) {
        cout << memberId[i] << endl;
    }
}
//����Ⱥid
void base_group_wfn::set_group_id(int pid) {
    groupId = pid;
}
//����Ⱥ��
void base_group_wfn::set_groupowner_id(int pid) {
    groupOwnerId = pid;
}
//��ʽ��Ⱥ
void base_group_wfn::no_output_add_member(int pid) {
    memberId.push_back(pid);
}
//��ȡȺid
int base_group_wfn::get_group_id() {
    return groupId;
}
//��ȡȺ��id
int base_group_wfn::get_groupowner_id() {
    return groupOwnerId;
}
//��ȡȺ��Աid
vector<int> base_group_wfn::get_member_id() {
    return memberId;
}

