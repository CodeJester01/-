#include"wbaccount_wfn.h"
using namespace std;

int wbaccount_wfn::wbnumber = 0;

wbaccount_wfn::wbaccount_wfn() {
    wbnumber++;
    islogin = 0;
    qqid = 0;
};
wbaccount_wfn::~wbaccount_wfn() {};
//����΢���˺�
void wbaccount_wfn::set_wb() {
    long long pid;
    string str1;
    cout << "    ������΢��id:" << "    "; cin >> pid; set_id(pid);
    cout << "    ����������:" << "    ";
    cin >> str1; password = str1;
    cout << "    ������΢���û���:" << "    ";
    cin >> name;
    cout << "    ���������ڵ�:" << "    ";
    cin >> location;
    int a;
    cout << "    " << "������������ݣ�" << "    ";
    cin >> a;
    birthday.change_year(a);
    cout << "    " << "�����������·ݣ�" << "    ";
    cin >> a;
    birthday.change_month(a);
    cout << "    " << "�������������ڣ�" << "    ";
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
//չʾ��Ϣ
void wbaccount_wfn::show_information() {
    cout << "    �˺ţ�" << ID << endl;
    cout << "    �ǳƣ�" << name << endl;
    cout << "    ���գ�" << birthday.get_month() << "��" << birthday.get_day() << "��" << endl;
    cout << "    ����ʱ�䣺" << registrate_date.get_year() << "��" << registrate_date.get_month() << "��" << registrate_date.get_day() << "��" << endl;
    //base_account_wfn::cal_registrate_time();
    //cout<<"    ע��������"<<registrate_time<<"��"<<endl;
    cout << "    ��ס�أ�" << location << endl;
    if (qqid != 0) cout << "    �󶨵�QQ�˺�:" << qqid << endl;
    if (friend_list.empty())
        cout << "    �㻹û���κκ��ѣ�" << endl;
    else {
        cout << "    �����б�" << endl;
        for (int i = 0; i < friend_list.size(); i++)
            cout << "    " << friend_list[i] << endl;
    }
}
//����qqid
void wbaccount_wfn::set_qqid(int pid) {
    qqid = pid;
}
//��ȡqqid
int wbaccount_wfn::get_qqid() {
    return qqid;
}

