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
//创建账号
void wxclient_wfn::set_new_weixin_account() {
    wxaccount_wfn newWeixin;
    newWeixin.set_wx();
    weixinClient.push_back(newWeixin);
}
//建群
void wxclient_wfn::set_new_weixin_group(int weixinId) {
    int i;
    wxgroup_wfn newgroup;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == weixinId) {
            weixinClient[i].no_output_enter_group(newgroup.set_group(weixinId));
            //cout<<"测试“："<<weixinClient[i].getQQgroupList().at(0)<<"完成"<<endl;
            cout << "    创建群成功！" << endl;
            weixinGroup.push_back(newgroup);
            return;
        }
    }
    cout << "    该用户不存在！！" << endl;
}
//展示wx用户信息
void wxclient_wfn::show_weixin_infor(int weixinId) {
    int i;
    for (i = 0; i < weixinClient.size(); i++) {
        cout << weixinClient[i].get_id() << endl;
        if (weixinClient[i].get_id() == weixinId) {
            weixinClient[i].show_information();
            return;
        }
    }
    cout << "该用户不存在！！" << endl;
}

//展示群信息
void wxclient_wfn::show_group_infor(int groupid) {
    for (int i = 0; i < weixinGroup.size(); i++) {
        if (weixinGroup[i].get_group_id() == groupid) {
            weixinGroup[i].show_group_infor();
            return;
        }
    }
    cout << "该群不存在！" << endl;
}
//修改wx信息
void wxclient_wfn::change_weixin_infor(int id) {
    int i;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            weixinClient[i].change_information();
            return;
        }
    }
    cout << "该用户不存在！" << endl;
}
//添加好友
void wxclient_wfn::add_friend(int id) {
    int i, j, number;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    请输入想要加为好友的微信账号：" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < weixinClient.size(); j++) {
                //cout<<"测试:"<<weixinClient[j].getQQid()<<endl;
                if (weixinClient[j].get_id() == number) {
                    if (weixinClient[i].add_friend(number))
                        weixinClient[j].no_output_add_friend(id);
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
//删除好友
void wxclient_wfn::delete_friend(int id) {
    int i, j, number;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    " << "请输入想要删除好友的微信账号：" << "    ";
            cin >> number;
            setbuf(stdin, NULL);
            for (j = 0; j < weixinClient.size(); j++) {
                if (weixinClient[j].get_id() == number) {
                    if (weixinClient[i].delete_friend(number)) {
                        weixinClient[j].no_output_delete_friend(id);
                        return;
                    }
                    else {
                        cout << "删除好友失败！" << endl;
                        return;
                    }
                }
            }
            cout << "该用户不存在!" << endl;
            return;
        }
    }
}
void wxclient_wfn::chaxun_friend(int QQid) {
    int i, j, number, choose, cnt;
    string str;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == QQid) {
            cout << "    选择你的查询方式：1.按账号查询   2.按用户名关键词查询" << endl << "    ";
            cin >> choose;
            if (choose == 1) {
                cout << "    请输入想要查找的好友的微信账号：" << "    ";
                cin >> number;
                setbuf(stdin, NULL);
                for (j = 0; j < weixinClient.size(); j++) {
                    if (weixinClient[j].get_id() == number) {
                        cout << "    " << weixinClient[j].get_name() << "        " << weixinClient[j].get_id() << endl;
                    }
                    return;
                }
                cout << "    该用户不存在!" << endl;
                return;
            }
            if (choose == 2) {
                cout << "    请输入想要查找的好友的微信用户名关键词：" << "    ";
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
                    cout << "    " << "该用户不存在!" << endl;
                }
                return;
            }
        }
    }
}

//加群
void wxclient_wfn::enter_group(int id) {
    int i, groupNumber, j, temp;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    " << "请输入要加入群的账号：" << endl;
            cin >> groupNumber;
            for (j = 0; j < weixinGroup.size(); j++) {
                if (weixinGroup[j].get_group_id() == groupNumber) {
                    if (weixinClient[i].enter_group(groupNumber)) {
                        weixinGroup[j].add_member(id);
                        //temp=weixinGroup[j].getMemberid()[1];
                        //cout<<temp;
                        //cout<<weixinGroup[j].getMemberid().at(1);
                        cout << "    " << "入群成功！" << endl;
                        return;
                    }
                }
            }
            cout << "    " << "查无此群！" << endl;
            return;
        }
    }
    cout << "    " << "该用户不存在！！" << endl;
}
//退群
void wxclient_wfn::exit_group(int id) {
    int i, groupNumber, j;
    for (i = 0; i < weixinClient.size(); i++) {
        if (weixinClient[i].get_id() == id) {
            cout << "    " << "请输入要退出群的账号：" << "    ";
            cin >> groupNumber;
            for (j = 0; j < weixinGroup.size(); j++) {
                if (weixinGroup[j].get_group_id() == groupNumber) {
                    if (weixinClient[i].exit_group(groupNumber)) {
                        //cout << "    " << "测试2222" << endl;
                        weixinGroup[j].delete_member(id);
                        return;
                    }
                }
            }
            cout << "    " << "查无此群！" << endl;
            return;
        }
    }
    cout << "    " << "该用户不存在！！" << endl;
}
//判断群是否存在
int wxclient_wfn::judge_groupid_exist(int id) {
    int flag = 1;
    int number = id;
    while (flag) {
        flag = 0;
        for (int j = 0; j < weixinGroup.size(); j++) {
            if (weixinGroup[j].get_group_id() == number) {
                cout << "    " << "该群账号已存在,请重新输入！" << endl;
                cin >> number;
                flag = 1;
            }
        }
    }
    return number;
}

//初始化wx账号
void wxclient_wfn::initialise_weixin(int weixinNumber) {
    for (int i = 0; i < weixinNumber; i++) {
        wxaccount_wfn temp;
        weixinClient.push_back(temp);
    }
}
//初始化wx群
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

