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
            //cout<<"测试“："<<QQvector[i].getQQgroupList().at(0)<<"完成"<<endl;
            cout << "    创建群成功！" << endl;
            qqgroup.push_back(newgroup);
            return;
        }
    }
    cout << "    该用户不存在！！" << endl;
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
    cout << "    该用户不存在！！" << endl;
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
            cout << "    请输入想要加为好友的qq账号：" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < qqvector.size(); j++) {
                if (qqvector[j].get_id() == number) {
                    if (qqvector[i].add_friend(number))
                        qqvector[j].no_output_add_friend(QQid);
                    else
                        cout << "    添加好友失败！" << endl;
                    return;
                }
            }
            cout << "    该用户不存在!" << endl;
            return;
        }
    }
}

void qqclient_wfn::delete_friend(int QQid) {
    int i, j, number;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    请输入想要删除好友的qq账号：" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < qqvector.size(); j++) {
                if (qqvector[j].get_id() == number) {
                    if (qqvector[i].delete_friend(number)) {
                        qqvector[j].no_output_delete_friend(QQid);
                        return;
                    }
                    else {
                        cout << "    删除好友失败！" << endl;
                        return;
                    }
                }
            }
            cout << "    该用户不存在!" << endl;
            return;
        }
    }
}

void qqclient_wfn::enter_group(int QQid) {
    int i, groupNumber, j, temp;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    请输入要加入群的账号：" << "    ";
            cin >> groupNumber;
            for (j = 0; j < qqgroup.size(); j++) {
                if (qqgroup[j].get_group_id() == groupNumber) {
                    if (qqvector[i].enter_group(groupNumber)) {
                        qqgroup[j].add_member(QQid);
                        //temp=QQgroup[j].getMemberid()[1];
                        //cout<<temp;
                        //cout<<QQgroup[j].getMemberid().at(1);
                        //cout << "    入群成功！" << endl;
                        return;
                    }
                }
                return;
            }
            cout << "    查无此群！" << endl;
            return;
        }
    }
    cout << "    该用户不存在！！" << endl;
}


void qqclient_wfn::exit_group(int QQid) {
    int i, groupNumber, j;
    for (i = 0; i < qqvector.size(); i++) {
        if (qqvector[i].get_id() == QQid) {
            cout << "    请输入要退出群的账号：" << "    ";
            cin >> groupNumber;
            for (j = 0; j < qqgroup.size(); j++) {
                if (qqgroup[j].get_group_id() == groupNumber) {
                    if (qqvector[i].exit_group(groupNumber)) {
                        //cout << "    测试2222" << endl;
                        qqgroup[j].delete_member(QQid);
                        return;
                    }
                }
            }
            cout << "    查无此群！" << endl;
            return;
        }
    }
    cout << "    该用户不存在！！" << endl;
}

void qqclient_wfn::show_group_infor(int groupid) {
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_group_id() == groupid) {
            qqgroup[i].show_group_infor();
            return;
        }
    }
    cout << "    该群不存在！" << endl;
}

void qqclient_wfn::show_son_group_infor(int groupid) {
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_father_group_id() == groupid) {
            qqgroup[i].show_son_group_infor();
            return;
        }
    }
    cout << "    该群不存在！" << endl;
}

void qqclient_wfn::set_admin(int groupid) {
    for (int i = 0; i < qqgroup.size(); i++) {
        if (qqgroup[i].get_group_id() == groupid) {
            qqgroup[i].set_admin();
            return;
        }
    }
    cout << "    该群不存在！" << endl;
}

int qqclient_wfn::judge_groupid_exist(int id) {
    int flag = 1;
    int number = id;
    while (flag) {
        flag = 0;
        for (int j = 0; j < qqgroup.size(); j++) {
            if (qqgroup[j].get_group_id() == number) {
                cout << "    该群账号已存在,请重新输入！" << endl;
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
            cout << "    选择你的查询方式：1.按账号查询   2.按用户名关键词查询" << endl << "    ";
            cin >> choose;
            if (choose == 1) {
                cout << "    请输入想要查找的好友的qq账号：" << "    ";
                cin >> number;
                setbuf(stdin, NULL);
                for (j = 0; j < qqvector.size(); j++) {
                    if (qqvector[j].get_id() == number) {
                        cout << "    " << qqvector[j].get_name() << "        " << qqvector[j].get_id() << endl;
                    }
                    return;
                }
                cout << "    该用户不存在!" << endl;
                return;
            }
            if (choose == 2) {
                cout << "    请输入想要查找的好友的qq用户名关键词：" << "    ";
                cin >> str;
                cnt = 0;
                for (j = 0; j < qqvector.size(); j++) {
                    if (kmp(qqvector[j].get_name(), str)) {
                        cout << "    " << qqvector[j].get_name() << "        " << qqvector[j].get_id() << endl;
                        cnt++;
                    }
                }
                if (cnt == 0) {
                    cout << "    该用户不存在!" << endl;
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
            cout << "    请输入临时讨论组账号：" << endl;
            cin >> songroupid;
            songroupid = judge_groupid_exist(songroupid);//判断群账号是否已经存在，如果存在则重新输入。
            set_new_son_group(groupid, songroupid);//创建一个子群
            qqgroup[i].get_son_group_id().push_back(songroupid);
            while (flag) {
                cout << "    请输入想要拉入临时讨论组的账号：" << endl;
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
                cout << "0、结束。\n1、继续拉人。\n" << endl;
                cin >> flag;
                //分别对群组和qq进行进群操作。
            }
            return;
        }
    }
    cout << "    该群不存在！" << endl;
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
