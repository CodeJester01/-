#define _CRT_SECURE_NO_WARNINGS
#include "wxclient_wfn.h"

int kmp1(string str1, string str2);

wxclient_wfn::wxclient_wfn()
{
    //ctor
}

wxclient_wfn::~wxclient_wfn()
{
    //dtor
}
//�����˺�
void wxclient_wfn::set_new_weixin_account() {
    wxaccount_wfn newWeixin;
    newWeixin.set_wx();
    weixinClient.push_back(newWeixin);
}
//��Ⱥ
void wxclient_wfn::set_new_weixin_group(int weixinId) {
    int i;
    wxgroup_wfn newgroup;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == weixinId) {
            weixinClient[i].no_output_enter_group(newgroup.set_group(weixinId));
            //cout<<"���ԡ���"<<weixinClient[i].getQQgroupList().at(0)<<"���"<<endl;
            cout << "    ����Ⱥ�ɹ���" << endl;
            weixinGroup.push_back(newgroup);
            return;
        }
    }
    cout << "    ���û������ڣ���" << endl;
}
//չʾwx�û���Ϣ
void wxclient_wfn::show_weixin_infor(int weixinId) {
    int i;
    for (i = 0; i < weixinClient.size(); i++) {
        cout << weixinClient[i].get_id() << endl;
        if (weixinClient[i].get_id() == weixinId) {
            weixinClient[i].show_information();
            return;
        }
    }
    cout << "���û������ڣ���" << endl;
}

//չʾȺ��Ϣ
void wxclient_wfn::show_group_infor(int groupid) {
    for (int i = 0; i < weixinGroup.size(); i++) {
        if (weixinGroup[i].get_group_id() == groupid) {
            weixinGroup[i].show_group_infor();
            return;
        }
    }
    cout << "��Ⱥ�����ڣ�" << endl;
}
//�޸�wx��Ϣ
void wxclient_wfn::change_weixin_infor(int id) {
    int i;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            weixinClient[i].change_information();
            return;
        }
    }
    cout << "���û������ڣ�" << endl;
}
//��Ӻ���
void wxclient_wfn::add_friend(int id) {
    int i, j, number;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    ��������Ҫ��Ϊ���ѵ�΢���˺ţ�" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < weixinClient.size(); j++) {
                //cout<<"����:"<<weixinClient[j].getQQid()<<endl;
                if (weixinClient[j].get_id() == number) {
                    if (weixinClient[i].add_friend(number))
                        weixinClient[j].no_output_add_friend(id);
                    else
                        cout << "    ��Ӻ���ʧ�ܣ�" << endl;
                    return;
                }
            }
            cout << "    ���û�������!" << endl;
            return;
        }
    }
}
//ɾ������
void wxclient_wfn::delete_friend(int id) {
    int i, j, number;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    " << "��������Ҫɾ�����ѵ�΢���˺ţ�" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < weixinClient.size(); j++) {
                if (weixinClient[j].get_id() == number) {
                    if (weixinClient[i].delete_friend(number)) {
                        weixinClient[j].no_output_delete_friend(id);
                        return;
                    }
                    else {
                        cout << "ɾ������ʧ�ܣ�" << endl;
                        return;
                    }
                }
            }
            cout << "���û�������!" << endl;
            return;
        }
    }
}
void wxclient_wfn::chaxun_friend(int QQid) {
    int i, j, number, choose, cnt;
    string str;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == QQid) {
            cout << "    ѡ����Ĳ�ѯ��ʽ��1.���˺Ų�ѯ   2.���û����ؼ��ʲ�ѯ" << endl << "    ";
            cin >> choose;
            if (choose == 1) {
                cout << "    ��������Ҫ���ҵĺ��ѵ�΢���˺ţ�" << "    ";
                cin >> number;
                setbuf(stdin, NULL);
                for (j = 0; j < weixinClient.size(); j++) {
                    if (weixinClient[j].get_id() == number) {
                        cout << "    " << weixinClient[j].get_name() << "        " << weixinClient[j].get_id() << endl;
                    }
                    return;
                }
                cout << "    ���û�������!" << endl;
                return;
            }
            if (choose == 2) {
                cout << "    ��������Ҫ���ҵĺ��ѵ�΢���û����ؼ��ʣ�" << "    ";
                cin >> str;
                cnt = 0;
                for (j = 0; j < weixinClient.size(); j++) {
                    if (kmp1
                    (weixinClient[j].get_name(), str)) {
                        cout << weixinClient[j].get_name() << "        " << weixinClient[j].get_id() << endl;
                        cnt++;
                    }
                }
                if (cnt == 0) {
                    cout << "    " << "���û�������!" << endl;
                }
                return;
            }
        }
    }
}

//��Ⱥ
void wxclient_wfn::enter_group(int id) {
    int i, groupNumber, j, temp;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    " << "������Ҫ����Ⱥ���˺ţ�" << endl;
            cin >> groupNumber;
            for (j = 0; j < weixinGroup.size(); j++) {
                if (weixinGroup[j].get_group_id() == groupNumber) {
                    if (weixinClient[i].enter_group(groupNumber)) {
                        weixinGroup[j].add_member(id);
                        //temp=weixinGroup[j].getMemberid()[1];
                        //cout<<temp;
                        //cout<<weixinGroup[j].getMemberid().at(1);
                        cout << "    " << "��Ⱥ�ɹ���" << endl;
                        return;
                    }
                }
            }
            cout << "    " << "���޴�Ⱥ��" << endl;
            return;
        }
    }
    cout << "    " << "���û������ڣ���" << endl;
}
//��Ⱥ
void wxclient_wfn::exit_group(int id) {
    int i, groupNumber, j;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    " << "������Ҫ�˳�Ⱥ���˺ţ�" << "    ";
            cin >> groupNumber;
            for (j = 0; j < weixinGroup.size(); j++) {
                if (weixinGroup[j].get_group_id() == groupNumber) {
                    if (weixinClient[i].exit_group(groupNumber)) {
                        //cout << "    " << "����2222" << endl;
                        weixinGroup[j].delete_member(id);
                        return;
                    }
                }
            }
            cout << "    " << "���޴�Ⱥ��" << endl;
            return;
        }
    }
    cout << "    " << "���û������ڣ���" << endl;
}
//�ж�Ⱥ�Ƿ����
int wxclient_wfn::judge_groupid_exist(int id) {
    int flag = 1;
    int number = id;
    while (flag) {
        flag = 0;
        for (int j = 0; j < weixinGroup.size(); j++) {
            if (weixinGroup[j].get_group_id() == number) {
                cout << "    " << "��Ⱥ�˺��Ѵ���,���������룡" << endl;
                cin >> number;
                flag = 1;
            }
        }
    }
    return number;
}

//��ʼ��wx�˺�
void wxclient_wfn::initialise_weixin(int weixinNumber) {
    for (int i = 0; i < weixinNumber; i++) {
        wxaccount_wfn temp;
        weixinClient.push_back(temp);
    }
}
//��ʼ��wxȺ
void wxclient_wfn::initialise_weixin_group(int weixinGroupNumber) {
    for (int i = 0; i < weixinGroupNumber; i++) {
        wxgroup_wfn temp;
        weixinGroup.push_back(temp);
    }
}


int kmp1(string str1, string str2) {
    int i = 0, j = 0;
    int* p = new int[str2.size()];
    int k, m;
    m = str2.length();
    p[0] = -1;
    for (j = 1; j < m; j++) {
        k = p[j - 1];
        while (str1[j] != str1[k + 1] && k >= 0) {
            k = p[k];
        }
        if (str1[j] == str1[k + 1]) p[j] = k + 1;
        else p[j] = -1;
    }
    j = 0;
    while (i < str1.length() && j < str2.length()) {
        if (str1[i] == str2[j]) {
            i++; j++;
        }
        else {
            if (j == 0) i++;
            else j = p[j - 1] + 1;
        }
    }
    if (j < str2.length()) {
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}

