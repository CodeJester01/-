#include"wbaccount_wfn.h"
using namespace std;

int wbaccount_wfn::wbnumber = 0;

wbaccount_wfn::wbaccount_wfn() {
    wbnumber++;
    islogin = 0;
    qqid = 0;
};
wbaccount_wfn::~wbaccount_wfn() {};
//设置微博账号
void wbaccount_wfn::set_wb() {
    long long pid;
    string str1;
    cout << "    请输入微博id:" << "    "; cin >> pid; set_id(pid);
    cout << "    请输入密码:" << "    ";
    cin >> str1; password = str1;
    cout << "    请输入微博用户名:" << "    ";
    cin >> name;
    cout << "    请输入所在地:" << "    ";
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
//展示信息
void wbaccount_wfn::show_information() {
    cout << "    账号：" << ID << endl;
    cout << "    昵称：" << name << endl;
    cout << "    生日：" << birthday.get_month() << "月" << birthday.get_day() << "日" << endl;
    cout << "    创建时间：" << registrate_date.get_year() << "年" << registrate_date.get_month() << "月" << registrate_date.get_day() << "日" << endl;
    //base_account_wfn::cal_registrate_time();
    //cout<<"    注册天数："<<registrate_time<<"天"<<endl;
    cout << "    居住地：" << location << endl;
    if (qqid != 0) cout << "    绑定的QQ账号:" << qqid << endl;
    if (friend_list.empty())
        cout << "    你还没有任何好友！" << endl;
    else {
        cout << "    好友列表：" << endl;
        for (int i = 0; i < friend_list.size(); i++)
            cout << "    " << friend_list[i] << endl;
    }
}
//设置qqid
void wbaccount_wfn::set_qqid(int pid) {
    qqid = pid;
}
//获取qqid
int wbaccount_wfn::get_qqid() {
    return qqid;
}

