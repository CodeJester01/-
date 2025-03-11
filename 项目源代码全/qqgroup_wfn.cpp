#include "qqgroup_wfn.h"
int qqgroup_wfn::qqGroupNumber = 0;
int qqgroup_wfn::sonGroupNumber = 0;
qqgroup_wfn::qqgroup_wfn()
{
    qqGroupNumber++;
    fatherGroupId = 0;
}

qqgroup_wfn::~qqgroup_wfn() {}

//����Ⱥ��Ϣ
int qqgroup_wfn::set_group(int QQid) {
    groupOwnerId = QQid;
    adminId.push_back(QQid);
    cout << "    ������Ⱥ�˺ţ�";
    cout << "    ";
    cin >> groupId;
    memberId.push_back(groupOwnerId);
    //cout<<"������Ⱥ�����ࣺ"<<endl;
    //cin>>groupType;
    return groupId;
}
//���ù���Ա
void qqgroup_wfn::set_admin() {
    int adminid;
    int i;
    cout << "    ��������Ҫ���óɹ���Ա���˺ţ�";
    cin >> adminid;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == adminid) {
            adminId.push_back(adminid);
            cout << "    ���óɹ���" << endl;
            return;
        }
        else
            cout << "    Ⱥ�в��޴��ˣ�";
    }
}
//չʾȺ��Ϣ
void qqgroup_wfn::show_group_infor() {
    int i;
    cout << "    Ⱥ���˺ţ�" << groupOwnerId << endl;
    if (adminId.empty()) {
        cout << "    ��Ⱥδ���ù���Ա��" << endl;
    }
    else {
        cout << "    Ⱥ����Ա�˺ţ�" << endl;
        for (i = 0; i < adminId.size(); i++) {
            cout << "    " << adminId[i] << endl;
        }
    }
    cout << "    " << "����Ⱥ��Ա�˺ţ�" << endl;
    for (i = 0; i < memberId.size(); i++) {
        cout << "    " << memberId[i] << endl;
    }
    if (sonGroupId.empty());
    else {
        cout << "    " << "������ʱ�������˺ţ�" << endl;
        for (int i = 0; i < sonGroupId.size(); i++) {
            cout << "    " << sonGroupId[i] << endl;
        }
    }
}
//����
int qqgroup_wfn::delete_member() {
    int temp;
    int i;
    cout << "    ��������Ҫ�߳�Ⱥ��QQ�˺ţ�" << "    ";
    cin >> temp;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == temp) {
            memberId.erase(memberId.begin() + i);
            cout << "\t��ϲ����ɾ���ɹ���" << endl;
            for (int k = 0; k < adminId.size(); k++) {
                if (adminId[k] == temp)
                    adminId.erase(adminId.begin() + k);
            }
            return temp;
        }
    }
    cout << "    ��Ⱥ�в��޴��ˣ�" << endl;
    return 0;
}
//����
void qqgroup_wfn::delete_member(int QQid) {
    for (int i = 0; i < memberId.size(); i++) {
        if (memberId[i] == QQid) {
            memberId.erase(memberId.begin() + i);
        }
    }
    for (int i = 0; i < adminId.size(); i++) {
        if (adminId[i] == QQid)
            adminId.erase(adminId.begin() + i);
    }
}
//ȡ������Ա
void qqgroup_wfn::delete_admin() {
    int adminid;
    int i;
    cout << "    ��������Ҫȡ������Ա���˺ţ�" << "    ";
    cin >> adminid;
    for (i = 0; i < adminId.size(); i++) {
        if (adminId[i] == adminid) {
            cout << "    ȡ���ɹ���" << endl;
            adminId.erase(adminId.begin() + i);
        }
        else
            cout << "    �ó�Ա�����ǹ���Ա��";
    }
}
//չʾ��ʱ��������Ϣ
void qqgroup_wfn::show_son_group_infor() {
    cout << "    ��Ⱥ��" << fatherGroupId << endl;
    cout << "    ��ʱ�������Ա��" << endl;
    for (int i = 0; i < memberId.size(); i++) {
        cout << "    " << memberId[i] << endl;
    }
}
//��ȡ��Ⱥ
int qqgroup_wfn::get_father_group_id() {
    return fatherGroupId;
}
//��ȡ��ʱ������
vector<int> qqgroup_wfn::get_son_group_id() {
    return sonGroupId;
}
//������ȺȺ��
void qqgroup_wfn::set_father_group_id(int pid) {
    fatherGroupId = pid;
}
//��ʽ��ӹ���Ա
void qqgroup_wfn::no_output_set_admin(int pid) {
    adminId.push_back(pid);
}
//��ȡ����Աid
vector<int> qqgroup_wfn::get_admin_id() {
    return adminId;
}