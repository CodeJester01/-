#include "wxgroup_wfn.h"
int wxgroup_wfn::wxgroupNumber = 0;
wxgroup_wfn::wxgroup_wfn()
{
    wxgroupNumber++;
}

wxgroup_wfn::~wxgroup_wfn() {}

//չʾȺ��Ϣ
void wxgroup_wfn::show_group_infor() {
    int i;
    cout << "    " << "Ⱥ���˺ţ�" << groupOwnerId << endl;
    cout << "    " << "����Ⱥ��Ա�˺ţ�" << endl;
    for (i = 0; i < memberId.size(); i++) {
        cout << "    " << memberId[i] << endl;
    }
}
//����
int wxgroup_wfn::delete_member() {
    int temp;
    int i;
    cout << "    " << "��������Ҫ�߳�Ⱥ���˺ţ�" << endl;
    cin >> temp;
    for (i = 0; i < memberId.size(); i++) {
        if (memberId[i] == temp) {
            memberId.erase(memberId.begin() + i);
            cout << "\t��ϲ����ɾ���ɹ���" << endl;
            return temp;
        }
    }
    cout << "    " << "��Ⱥ�в��޴��ˣ�" << endl;
    return 0;
}
//����
void wxgroup_wfn::delete_member(int id) {
    for (int i = 0; i < memberId.size(); i++) {
        if (memberId[i] == id) {
            memberId.erase(memberId.begin() + i);
            cout << "\t��ϲ����ɾ���ɹ���" << endl;
            return;
        }
    }
}
//����Ⱥid
int wxgroup_wfn::set_group(int id) {
    groupOwnerId = id;
    memberId.push_back(id);
    cout << "    " << "������Ⱥid:" << "    ";
    cin >> groupId;
    return groupId;
}


