#include"qqaccount_wfn.h"

using namespace std;

int qqaccount_wfn::qqNumber = 0;
qqaccount_wfn::qqaccount_wfn() {
    qqNumber++;
    islogin = 0;
    is_setwb = 0;
    wxid = 0;
}
qqaccount_wfn::~qqaccount_wfn() {}

void qqaccount_wfn::set_qq() {
    int pid;
    string str1, str2;
    cout << "    请输入QQid:" << "    "; cin >> pid; set_id(pid);
    cout << "    请输入密码:" << "    ";
    cin >> str1; password = str1;
    cout << "    请输入QQ用户名:" << "    ";
    cin >> name;
    cout << "    请输入所在地:" << "    ";
    cin >> location;
    int a;
    cout << "    请输入生日年份：" << "    ";
    cin >> a;
    birthday.change_year(a);
    cout << "    请输入生日月份：" << "    ";
    cin >> a;
    birthday.change_month(a);
    cout << "    请输入生日日期：" << "    ";
    cin >> a;
    birthday.change_day(a);

    struct tm ltm;
    time_t now;
    time(&now);
    localtime_s(&ltm, &now);
    int c = 1900 + ltm.tm_year;
    registrate_date.change_year(c);
    c = ltm.tm_mon + 1;
    registrate_date.change_month(c);
    c = ltm.tm_mday;
    registrate_date.change_day(c);
}
void qqaccount_wfn::show_information() {
    cout << "    账号：" << ID << endl;
    cout << "    昵称：" << name << endl;
    cout << "    生日：" << birthday.get_month() << "月" << birthday.get_day() << "日" << endl;
    cout << "    创建时间：" << registrate_date.get_year() << "年" << registrate_date.get_month() << "月" << registrate_date.get_day() << "日" << endl;
    //base_account_wfn::cal_registrate_time();
    //cout<<"    注册天数："<<registrate_time<<"天"<<endl;
    cout << "    居住地：" << location << endl;
    if (wxid == 0)
        cout << "    该用户现在还没绑定微信!" << endl;
    else
        cout << "    该用户绑定的微信的账号为：" << wxid << endl;
    if (is_setwb == 0)
        cout << "    该用户现在还没绑定微博!" << endl;
    else
        cout << "    该用户绑定的微博的账号为：" << is_setwb << endl;
    if (friend_list.empty())
        cout << "    你还没有任何好友！" << endl;
    else {
        cout << "    好友列表：" << endl;
        for (int i = 0; i < friend_list.size(); i++) {
            cout << "    " << friend_list[i] << endl;
        }
    }
    if (group_list.empty())
        cout << "    你还没有加入任何QQ群!" << endl;
    else {
        cout << "    QQ群列表:" << endl;
        for (int i = 0; i < group_list.size(); i++)
            cout << "    " << group_list[i] << endl;
    }
    cout << endl;
}
int qqaccount_wfn::get_weibo_id() {
    return is_setwb;
}
int qqaccount_wfn::get_wxid() {
    return wxid;
}
void qqaccount_wfn::set_weibo_id(int pid) {
    is_setwb = pid;
}
void qqaccount_wfn::set_wxid(int pid) {
    wxid = pid;
}
void qqaccount_wfn::set_connect_weibo() {
    wbaccount_wfn newWb;
    newWb.set_id(ID);
}
