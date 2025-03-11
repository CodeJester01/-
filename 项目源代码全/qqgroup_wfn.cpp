#include "qqgroup_wfn.h"
int qqgroup_wfn::qqGroupNumber = 0;
int qqgroup_wfn::sonGroupNumber = 0;
qqgroup_wfn::qqgroup_wfn()
{
    qqGroupNumber++;
    fatherGroupId = 0;
}

qqgroup_wfn::~qqgroup_wfn() {}

//设置群信息
int qqgroup_wfn::set_group(int QQid) {
    groupOwnerId = QQid;
    adminId.push_back(QQid);
    cout << "    请输入群账号：";
    cout << "    ";
    cin >> groupId;
    memberId.push_back(groupOwnerId);
    //cout<<"请设置群的种类："<<endl;
    //cin>>groupType;
    return groupId;
}
//设置管理员
void qqgroup_wfn::set_admin() {
    int adminid;
    int i;
    cout << "    请输入想要设置成管理员的账号：";
    cin >> adminid;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == adminid) {
            adminId.push_back(adminid);
            cout << "    设置成功！" << endl;
            return;
        }
        else
            cout << "    群中并无此人！";
    }
}
//展示群信息
void qqgroup_wfn::show_group_infor() {
    int i;
    cout << "    群主账号：" << groupOwnerId << endl;
    if (adminId.empty()) {
        cout << "    该群未设置管理员！" << endl;
    }
    else {
        cout << "    群管理员账号：" << endl;
        for (i = 0; i < adminId.size(); i++) {
            cout << "    " << adminId[i] << endl;
        }
    }
    cout << "    " << "所有群成员账号：" << endl;
    for (i = 0; i < memberId.size(); i++) {
        cout << "    " << memberId[i] << endl;
    }
    if (sonGroupId.empty());
    else {
        cout << "    " << "所有临时讨论组账号：" << endl;
        for (int i = 0; i < sonGroupId.size(); i++) {
            cout << "    " << sonGroupId[i] << endl;
        }
    }
}
//踢人
int qqgroup_wfn::delete_member() {
    int temp;
    int i;
    cout << "    请输入想要踢出群的QQ账号：" << "    ";
    cin >> temp;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == temp) {
            memberId.erase(memberId.begin() + i);
            cout << "\t恭喜您！删除成功！" << endl;
            for (int k = 0; k < adminId.size(); k++) {
                if (adminId[k] == temp)
                    adminId.erase(adminId.begin() + k);
            }
            return temp;
        }
    }
    cout << "    该群中查无此人！" << endl;
    return 0;
}
//踢人
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
//取消管理员
void qqgroup_wfn::delete_admin() {
    int adminid;
    int i;
    cout << "    请输入想要取消管理员的账号：" << "    ";
    cin >> adminid;
    for (i = 0; i < adminId.size(); i++) {
        if (adminId[i] == adminid) {
            cout << "    取消成功！" << endl;
            adminId.erase(adminId.begin() + i);
        }
        else
            cout << "    该成员并不是管理员！";
    }
}
//展示临时讨论组信息
void qqgroup_wfn::show_son_group_infor() {
    cout << "    主群：" << fatherGroupId << endl;
    cout << "    临时讨论组成员：" << endl;
    for (int i = 0; i < memberId.size(); i++) {
        cout << "    " << memberId[i] << endl;
    }
}
//获取主群
int qqgroup_wfn::get_father_group_id() {
    return fatherGroupId;
}
//获取临时讨论组
vector<int> qqgroup_wfn::get_son_group_id() {
    return sonGroupId;
}
//设置主群群号
void qqgroup_wfn::set_father_group_id(int pid) {
    fatherGroupId = pid;
}
//隐式添加管理员
void qqgroup_wfn::no_output_set_admin(int pid) {
    adminId.push_back(pid);
}
//获取管理员id
vector<int> qqgroup_wfn::get_admin_id() {
    return adminId;
}