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
    cout << "    ������QQid:" << "    "; cin >> pid; set_id(pid);
    cout << "    ����������:" << "    ";
    cin >> str1; password = str1;
    cout << "    ������QQ�û���:" << "    ";
    cin >> name;
    cout << "    ���������ڵ�:" << "    ";
    cin >> location;
    int a;
    cout << "    ������������ݣ�" << "    ";
    cin >> a;
    birthday.change_year(a);
    cout << "    �����������·ݣ�" << "    ";
    cin >> a;
    birthday.change_month(a);
    cout << "    �������������ڣ�" << "    ";
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
    cout << "    �˺ţ�" << ID << endl;
    cout << "    �ǳƣ�" << name << endl;
    cout << "    ���գ�" << birthday.get_month() << "��" << birthday.get_day() << "��" << endl;
    cout << "    ����ʱ�䣺" << registrate_date.get_year() << "��" << registrate_date.get_month() << "��" << registrate_date.get_day() << "��" << endl;
    //base_account_wfn::cal_registrate_time();
    //cout<<"    ע��������"<<registrate_time<<"��"<<endl;
    cout << "    ��ס�أ�" << location << endl;
    if (wxid == 0)
        cout << "    ���û����ڻ�û��΢��!" << endl;
    else
        cout << "    ���û��󶨵�΢�ŵ��˺�Ϊ��" << wxid << endl;
    if (is_setwb == 0)
        cout << "    ���û����ڻ�û��΢��!" << endl;
    else
        cout << "    ���û��󶨵�΢�����˺�Ϊ��" << is_setwb << endl;
    if (friend_list.empty())
        cout << "    �㻹û���κκ��ѣ�" << endl;
    else {
        cout << "    �����б�" << endl;
        for (int i = 0; i < friend_list.size(); i++) {
            cout << "    " << friend_list[i] << endl;
        }
    }
    if (group_list.empty())
        cout << "    �㻹û�м����κ�QQȺ!" << endl;
    else {
        cout << "    QQȺ�б�:" << endl;
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
