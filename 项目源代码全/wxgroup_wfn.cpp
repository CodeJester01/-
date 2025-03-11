#include "wxgroup_wfn.h"
int wxgroup_wfn::wxgroupNumber = 0;
wxgroup_wfn::wxgroup_wfn()
{
    wxgroupNumber++;
}

wxgroup_wfn::~wxgroup_wfn() {}

//展示群信息
void wxgroup_wfn::show_group_infor() {
    int i;
    cout << "    " << "群主账号：" << groupOwnerId << endl;
    cout << "    " << "所有群成员账号：" << endl;
    for (i = 0; i < memberId.size(); i++) {
        cout << "    " << memberId[i] << endl;
    }
}
//踢人
int wxgroup_wfn::delete_member() {
    int temp;
    int i;
    cout << "    " << "请输入想要踢出群的账号：" << endl;
    cin >> temp;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == temp) {
            memberId.erase(memberId.begin() + i);
            cout << "\t恭喜您！删除成功！" << endl;
            return temp;
        }
    }
    cout << "    " << "该群中查无此人！" << endl;
    return 0;
}
//踢人
void wxgroup_wfn::delete_member(int id) {
    for (int i = 0; i < memberId.size(); i++) {
        if (memberId[i] == id) {
            memberId.erase(memberId.begin() + i);
            cout << "\t恭喜您！删除成功！" << endl;
            return;
        }
    }
}
//设置群id
int wxgroup_wfn::set_group(int id) {
    groupOwnerId = id;
    memberId.push_back(id);
    cout << "    " << "请输入群id:" << "    ";
    cin >> groupId;
    return groupId;
}


