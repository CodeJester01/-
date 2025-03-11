#include"base_account_wfn.h"

using namespace std;
#include <stdlib.h>
int date_cal(int s_year, int s_month, int s_day, int e_year, int e_month, int e_day);

base_account_wfn::base_account_wfn() {}

base_account_wfn::~base_account_wfn() {}

//�޸���Ϣ 
void base_account_wfn::change_information() {
    int ch;
    string pname, pcity;
    cout << "    ��������Ҫ�޸ĵ���Ϣ��" << endl;
    cout << "    1���ǳơ�2�����ڳ��С�" << endl;
    cout << "    ";
    cin >> ch;
    if (ch == 1) {
        cout << "    ��������Ҫ�µ��ǳƣ�" << "    ";
        cin >> pname;
        name = pname;
    }
    if (ch == 2) {
        cout << "    ��������Ҫ�µ����ڵأ�" << "    ";
        cin >> pcity;
        location = pcity;
    }
}

//��ȡ��Ϣ
int base_account_wfn::get_islogin() {
    return islogin;
}
int base_account_wfn::get_id() {
    return ID;
}
date base_account_wfn::get_birthday() {
    return birthday;
}
date base_account_wfn::get_registrate_date() {
    return registrate_date;
}
string base_account_wfn::get_name() {
    return name;
}
string base_account_wfn::get_location() {
    return location;
}
vector<int> base_account_wfn::get_friendlist() {
    return friend_list;
}
vector<int> base_account_wfn::get_grouplist() {
    return group_list;
}
string base_account_wfn::get_password() {
    return password;
}

//������Ϣ		
void base_account_wfn::set_id(int pid) {
    ID = pid;
}
void base_account_wfn::set_name(string pname) {
    name = pname;
}
void base_account_wfn::set_birthday(int y, int m, int d) {
    birthday.change_year(y);
    birthday.change_month(m);
    birthday.change_day(d);
}
void base_account_wfn::set_settime(int y, int m, int d) {
    registrate_date.change_year(y);
    registrate_date.change_month(m);
    registrate_date.change_day(d);
}
void base_account_wfn::set_location(string pcity) {
    location = pcity;
}
void base_account_wfn::set_password(string str) {
    password = str;
}

//��¼ 
void base_account_wfn::login(string str) {
    int flag = 1;
    if (str == password)
        islogin = 1;
    else {
        while (str != password && flag <= 6) {
            cout << "    �����������������(��ʣ" << 6 - flag << "�λ���)��" << endl;
            cin >> str;
        }
        if (flag == 6) return;
        islogin = 1;
    }
}
//��ʽ��¼
void base_account_wfn::no_output_login() {
    islogin = 1;
}
//��Ӻ���
int base_account_wfn::add_friend(int number) {
    for (int i = 0; i < friend_list.size(); i++) {
        if (friend_list[i] == number) {
            cout << "    �Ѿ������ĺ�����!" << endl;
            return 0;
        }
    }
    friend_list.push_back(number);
    cout << "\t��ϲ��!������ӳɹ�!" << endl;
    return 1;
}
//��ʽ��Ӻ���
int base_account_wfn::no_output_add_friend(int number) {
    friend_list.push_back(number);
    return 1;
}
//ɾ������
int base_account_wfn::delete_friend(int number) {
    for (int i = 0; i < friend_list.size(); i++) {
        if (friend_list[i] == number) {
            friend_list.erase(friend_list.begin() + i);
            cout << "    ��ϲ��!����ɾ���ɹ�!" << endl;
            return 1;
        }
    }
    return 0;
}
//��ʽɾ������
int base_account_wfn::no_output_delete_friend(int number) {
    for (int i = 0; i < friend_list.size(); i++) {
        if (friend_list[i] == number) {
            friend_list.erase(friend_list.begin() + i);
            return 1;
        }
    }
    return 0;
}

//��Ⱥ
int base_account_wfn::enter_group(int groupNumber) {
    for (int i = 0; i < group_list.size(); i++) {
        if (group_list[i] == groupNumber) {
            cout << "\t�Ѿ��� " << groupNumber << " Ⱥ����!" << endl;
            return 0;
        }
    }
    group_list.push_back(groupNumber);
    cout << "\t��ϲ������Ⱥ�ɹ���" << endl;
    return 1;
}
//͵͵��Ⱥ
void base_account_wfn::no_output_enter_group(int groupid) {
    group_list.push_back(groupid);
}
//��Ⱥ
int base_account_wfn::exit_group(int groupNumber) {
    for (int i = 0; i < group_list.size(); i++) {
        if (group_list[i] == groupNumber) {
            group_list.erase(group_list.begin() + i);
            cout << "\t��ϲ��!��Ⱥ�ɹ�!" << endl;
            return 1;
        }
    }
    cout << "\t��Ⱥʧ��!��ȷ�����Ƿ���Ľ�������Ⱥ!" << endl;
    return 0;
}
//͵͵��Ⱥ
int base_account_wfn::no_output_exit_group(int groupNumber) {
    for (int i = 0; i < group_list.size(); i++) {
        if (group_list[i] == groupNumber) {
            group_list.erase(group_list.begin() + i);
            return 1;
        }
    }
    return 0;
}

//��������
int date_cal(int s_year, int s_month, int s_day, int e_year, int e_month, int e_day) {
    int s_sum = 0;
    static int days = 0;
    static int day = 0;
    int e_sum = 0;
    static int leap = 0;
    int tmp, tmp1, tmp2;

    if (s_year > e_year) //�ж��ĸ���ݴ������ʼʱ����ڽ���ʱ�䣬�򻥻�ֵ
    {
        tmp = s_year;
        s_year = e_year;
        e_year = tmp;
        tmp1 = s_month;
        s_month = e_month;
        e_month = tmp1;
        tmp2 = s_day;
        s_day = e_day;
        e_day = tmp2;
    }

    while (s_year < e_year)
    {
        if (e_year % 400 == 0 || (e_year % 4 == 0 && e_year % 100 != 0)) //�ж��Ƿ�Ϊ����
        {
            days = days + 366; //����
        }
        else
        {
            days = days + 365; //ƽ��
        }
        e_year--;
    }

    switch (s_month)
    {
    case 1:s_sum = 0;
        break;
    case 2:s_sum = 31;
        break;
    case 3:s_sum = 31 + 28;
        break;
    case 4:s_sum = 31 + 28 + 31;
        break;
    case 5:s_sum = 31 + 28 + 31 + 30;
        break;
    case 6:s_sum = 31 + 28 + 31 + 30 + 31;
        break;
    case 7:s_sum = 31 + 28 + 31 + 30 + 31 + 30;
        break;
    case 8:s_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31;
        break;
    case 9:s_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
    case 10:s_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
    case 11:s_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
    case 12:s_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    }

    s_sum = s_sum + s_day; //������ʼ��������

    switch (e_month)
    {
    case 1:e_sum = 0;
        break;
    case 2:e_sum = 31;
        break;
    case 3:e_sum = 31 + 28;
        break;
    case 4:e_sum = 31 + 28 + 31;
        break;
    case 5:e_sum = 31 + 28 + 31 + 30;
        break;
    case 6:e_sum = 31 + 28 + 31 + 30 + 31;
        break;
    case 7:e_sum = 31 + 28 + 31 + 30 + 31 + 30;
        break;
    case 8:e_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31;
        break;
    case 9:e_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
    case 10:e_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
    case 11:e_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
    case 12:e_sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    }


    if (s_year % 400 == 0 || (s_year % 4 == 0 && s_year % 100 != 0))
    {
        if (e_month > 2)
        {
            day++;
        }
    }

    e_sum = e_sum + e_day; //���������������
    days = days - s_sum + e_sum + day; //��������
    return days;
}

