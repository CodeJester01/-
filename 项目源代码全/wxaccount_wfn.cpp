#include "wxaccount_wfn.h"
int wxaccount_wfn::wxnumber = 0;
//设置微信账号
void wxaccount_wfn::set_wx() {
    string str1;
    long long pid;
    cout << "    请输入微信id:" << "    "; cin >> pid; set_id(pid);
    cout << "    " << "请输入密码:" << "    ";
    cin >> str1;	 password = str1;
    cout << "    " << "请输入微信用户名:" << "    ";
    cin >> name;
    cout << "    " << "请输入所在地:" << "    ";
    cin >> location;
    int a;
    cout << "    " << "请输入生日年份：" << "    ";
    cin >> a;
    birthday.change_year(a);
    cout << "    " << "请输入生日月份：" << "    ";
    cin >> a;
    birthday.change_month(a);
    cout << "    " << "请输入生日日期：" << "    ";
    cin >> a;
    birthday.change_day(a);
    struct tm t;
    time_t now;
    time(&now);
    localtime_s(&t, &now);
    int c = 1900 + t.tm_year;
    registrate_date.change_year(c);
    c = t.tm_mon;
    registrate_date.change_month(c);
    c = t.tm_mday;
    registrate_date.change_day(c);
}
//展示账号信息
void wxaccount_wfn::show_information() {
    cout << "    账号：" << ID << endl;
    cout << "    昵称：" << name << endl;
    cout << "    生日：" << birthday.get_month() << "月" << birthday.get_day() << "日" << endl;
    cout << "    创建时间：" << registrate_date.get_year() << "年" << registrate_date.get_month() << "月" << registrate_date.get_day() << "日" << endl;
    //base_account_wfn::cal_registrate_time();
    //cout<<"    注册天数："<<registrate_time<<"天"<<endl;
    cout << "    居住地：" << location << endl;
    if (qqid == 0)
        cout << "    该用户现在还没绑定QQ!";
    else
        cout << "    该用户绑定的QQ的账号为：" << qqid << endl;
    if (friend_list.empty())
        cout << "    你还没有任何好友！" << endl;
    else {
        cout << "    好友列表：" << endl;
        for (int i = 0; i < friend_list.size(); i++)
            cout << friend_list[i] << endl;
    }
    if (group_list.empty())
        cout << "    你还没有加入任何微信群！" << endl;
    else {
        cout << "微信群列表:" << endl;
        for (int i = 0; i < group_list.size(); i++)
            cout << "    " << group_list[i] << endl;
    }
    cout << endl;
}
//获取qqid
int wxaccount_wfn::get_qqid() {
    return qqid;
}
//设置qqid
void wxaccount_wfn::set_qqid(int pid) {
    qqid = pid;
}

