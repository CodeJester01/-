#include "wxaccount_wfn.h"
int wxaccount_wfn::wxnumber = 0;
//����΢���˺�
void wxaccount_wfn::set_wx() {
    string str1;
    long long pid;
    cout << "    ������΢��id:" << "    "; cin >> pid; set_id(pid);
    cout << "    " << "����������:" << "    ";
    cin >> str1;	 password = str1;
    cout << "    " << "������΢���û���:" << "    ";
    cin >> name;
    cout << "    " << "���������ڵ�:" << "    ";
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
//չʾ�˺���Ϣ
void wxaccount_wfn::show_information() {
    cout << "    �˺ţ�" << ID << endl;
    cout << "    �ǳƣ�" << name << endl;
    cout << "    ���գ�" << birthday.get_month() << "��" << birthday.get_day() << "��" << endl;
    cout << "    ����ʱ�䣺" << registrate_date.get_year() << "��" << registrate_date.get_month() << "��" << registrate_date.get_day() << "��" << endl;
    //base_account_wfn::cal_registrate_time();
    //cout<<"    ע��������"<<registrate_time<<"��"<<endl;
    cout << "    ��ס�أ�" << location << endl;
    if (qqid == 0)
        cout << "    ���û����ڻ�û��QQ!";
    else
        cout << "    ���û��󶨵�QQ���˺�Ϊ��" << qqid << endl;
    if (friend_list.empty())
        cout << "    �㻹û���κκ��ѣ�" << endl;
    else {
        cout << "    �����б�" << endl;
        for (int i = 0; i < friend_list.size(); i++)
            cout << friend_list[i] << endl;
    }
    if (group_list.empty())
        cout << "    �㻹û�м����κ�΢��Ⱥ��" << endl;
    else {
        cout << "΢��Ⱥ�б�:" << endl;
        for (int i = 0; i < group_list.size(); i++)
            cout << "    " << group_list[i] << endl;
    }
    cout << endl;
}
//��ȡqqid
int wxaccount_wfn::get_qqid() {
    return qqid;
}
//����qqid
void wxaccount_wfn::set_qqid(int pid) {
    qqid = pid;
}

