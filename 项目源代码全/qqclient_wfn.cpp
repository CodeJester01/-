#define _CRT_SECURE_NO_WARNINGS
#include "qqclient_wfn.h"

int kmp(string str1, string str2);
qqclient_wfn::qqclient_wfn() {}

qqclient_wfn::~qqclient_wfn() {}

void qqclient_wfn::initialise_QQ(int qqNumber) {
    for (int i = 0; i < qqNumber; i++) {
        qqaccount_wfn temp;
        qqvector.push_back(temp);
    }
}

void qqclient_wfn::initialise_qq_group(int qqGroupNumber) {
    for (int i = 0; i < qqGroupNumber; i++) {
        qqgroup_wfn temp;
        qqgroup.push_back(temp);
    }
}


void qqclient_wfn::set_new_QQ_account() {
    qqaccount_wfn newQQ;
    newQQ.set_qq();
    qqvector.push_back(newQQ);
}

void qqclient_wfn::set_new_QQ_group(int QQid) {
    int i;
    qqgroup_wfn newgroup;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            qqvector[i].no_output_enter_group(newgroup.set_group(QQid));
            //cout<<"���ԡ���"<<QQvector[i].getQQgroupList().at(0)<<"���"<<endl;
            cout << "    ����Ⱥ�ɹ���" << endl;
            qqgroup.push_back(newgroup);
            return;
        }
    }
    cout << "    ���û������ڣ���" << endl;
}

void qqclient_wfn::show_QQ_infor(int QQid) {
    int i;
    for (i = 0; i < qqvector.size(); i++) {
        cout << qqvector[i].get_id() << endl;
        if (qqvector[i].get_id() == QQid) {
            qqvector[i].show_information();
            return;
        }
    }
    cout << "    ���û������ڣ���" << endl;
}

void qqclient_wfn::change_QQ_infor(int QQid) {
    int i;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            qqvector[i].change_information();
        }
    }
}

void qqclient_wfn::add_friend(int QQid) {
    int i, j, number;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    ��������Ҫ��Ϊ���ѵ�qq�˺ţ�" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < qqvector.size(); j++) {
                if (qqvector[j].get_id() == number) {
                    if (qqvector[i].add_friend(number))
                        qqvector[j].no_output_add_friend(QQid);
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

void qqclient_wfn::delete_friend(int QQid) {
    int i, j, number;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    ��������Ҫɾ�����ѵ�qq�˺ţ�" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < qqvector.size(); j++) {
                if (qqvector[j].get_id() == number) {
                    if (qqvector[i].delete_friend(number)) {
                        qqvector[j].no_output_delete_friend(QQid);
                        return;
                    }
                    else {
                        cout << "    ɾ������ʧ�ܣ�" << endl;
                        return;
                    }
                }
            }
            cout << "    ���û�������!" << endl;
            return;
        }
    }
}

void qqclient_wfn::enter_group(int QQid) {
    int i, groupNumber, j, temp;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    ������Ҫ����Ⱥ���˺ţ�" << "    ";
            cin >> groupNumber;
            for (j = 0; j < qqgroup.size(); j++) {
                if (qqgroup[j].get_group_id() == groupNumber) {
                    if (qqvector[i].enter_group(groupNumber)) {
                        qqgroup[j].add_member(QQid);
                        //temp=QQgroup[j].getMemberid()[1];
                        //cout<<temp;
                        //cout<<QQgroup[j].getMemberid().at(1);
                        //cout << "    ��Ⱥ�ɹ���" << endl;
                        return;
                    }
                }
                return;
            }
            cout << "    ���޴�Ⱥ��" << endl;
            return;
        }
    }
    cout << "    ���û������ڣ���" << endl;
}


void qqclient_wfn::exit_group(int QQid) {
    int i, groupNumber, j;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    ������Ҫ�˳�Ⱥ���˺ţ�" << "    ";
            cin >> groupNumber;
            for (j = 0; j < qqgroup.size(); j++) {
                if (qqgroup[j].get_group_id() == groupNumber) {
                    if (qqvector[i].exit_group(groupNumber)) {
                        //cout << "    ����2222" << endl;
                        qqgroup[j].delete_member(QQid);
                        return;
                    }
                }
            }
            cout << "    ���޴�Ⱥ��" << endl;
            return;
        }
    }
    cout << "    ���û������ڣ���" << endl;
}

void qqclient_wfn::show_group_infor(int groupid) {
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_group_id() == groupid) {
            qqgroup[i].show_group_infor();
            return;
        }
    }
    cout << "    ��Ⱥ�����ڣ�" << endl;
}

void qqclient_wfn::show_son_group_infor(int groupid) {
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_father_group_id() == groupid) {
            qqgroup[i].show_son_group_infor();
            return;
        }
    }
    cout << "    ��Ⱥ�����ڣ�" << endl;
}

void qqclient_wfn::set_admin(int groupid) {
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_group_id() == groupid) {
            qqgroup[i].set_admin();
            return;
        }
    }
    cout << "    ��Ⱥ�����ڣ�" << endl;
}

int qqclient_wfn::judge_groupid_exist(int id) {
    int flag = 1;
    int number = id;
    while (flag) {
        flag = 0;
        for (int j = 0; j < qqgroup.size(); j++) {
            if (qqgroup[j].get_group_id() == number) {
                cout << "    ��Ⱥ�˺��Ѵ���,���������룡" << endl;
                cin >> number;
                flag = 1;
            }
        }
    }
    return number;
}

void qqclient_wfn::chaxun_friend(int QQid) {
    int i, j, number, choose, cnt;
    string str;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    ѡ����Ĳ�ѯ��ʽ��1.���˺Ų�ѯ   2.���û����ؼ��ʲ�ѯ" << endl << "    ";
            cin >> choose;
            if (choose == 1) {
                cout << "    ��������Ҫ���ҵĺ��ѵ�qq�˺ţ�" << "    ";
                cin >> number;
                setbuf(stdin, NULL);
                for (j = 0; j < qqvector.size(); j++) {
                    if (qqvector[j].get_id() == number) {
                        cout << "    " << qqvector[j].get_name() << "        " << qqvector[j].get_id() << endl;
                    }
                    return;
                }
                cout << "    ���û�������!" << endl;
                return;
            }
            if (choose == 2) {
                cout << "    ��������Ҫ���ҵĺ��ѵ�qq�û����ؼ��ʣ�" << "    ";
                cin >> str;
                cnt = 0;
                for (j = 0; j < qqvector.size(); j++) {
                    if (kmp(qqvector[j].get_name(), str)) {
                        cout << "    " << qqvector[j].get_name() << "        " << qqvector[j].get_id() << endl;
                        cnt++;
                    }
                }
                if (cnt == 0) {
                    cout << "    ���û�������!" << endl;
                }
                return;
            }
        }
    }
}


void qqclient_wfn::set_son_group(int groupid) {
    int number, flag = 1, songroupid;
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_group_id() == groupid) {
            cout << "    ��������ʱ�������˺ţ�" << endl;
            cin >> songroupid;
            songroupid = judge_groupid_exist(songroupid);//�ж�Ⱥ�˺��Ƿ��Ѿ����ڣ�����������������롣
            set_new_son_group(groupid, songroupid);//����һ����Ⱥ
            qqgroup[i].get_son_group_id().push_back(songroupid);
            while (flag) {
                cout << "    ��������Ҫ������ʱ��������˺ţ�" << endl;
                for (int k = 0; k < qqgroup[i].get_member_id().size(); k++) {
                    cout << qqgroup[i].get_member_id()[k] << endl;
                }
                cin >> number;
                for (int j = 0; j < qqgroup.size(); j++) {
                    if (qqgroup[j].get_group_id() == songroupid) {
                        qqgroup[j].add_member(number);
                    }
                }
                for (int j = 0; j < qqvector.size(); j++) {
                    if (qqvector[j].get_id() == number) {
                        qqvector[j].enter_group(songroupid);
                    }
                }
                cout << "0��������\n1���������ˡ�\n" << endl;
                cin >> flag;
                //�ֱ��Ⱥ���qq���н�Ⱥ������
            }
            return;
        }
    }
    cout << "    ��Ⱥ�����ڣ�" << endl;
}

void qqclient_wfn::set_new_son_group(int groupid, int number) {
    qqgroup_wfn songroup;
    songroup.set_group_id(number);
    songroup.set_father_group_id(groupid);
    qqgroup.push_back(songroup);
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_group_id() == groupid) {
            qqgroup[i].get_son_group_id().push_back(number);
        }
    }
    qqgroup_wfn::sonGroupNumber++;
}

int kmp(string str1, string str2) {
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
