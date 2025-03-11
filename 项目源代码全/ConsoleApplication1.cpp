#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include<iostream>
#include <time.h>
#include<ctime>
#include<windows.h>
#include<fstream>               //文件写入头文件
#include<string>                //字符串处理头文件
#include<vector>                //向量使用头文件
#include<cstdlib>               //与清屏函数有关的头文件
#include "date.h"
#include"qqaccount_wfn.h"
#include"qqgroup_wfn.h"
#include"wxaccount_wfn.h"
#include"qqclient_wfn.h"
#include"wxclient_wfn.h"
#include"wbclient_wfn.h"
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <graphics.h>  
#include <conio.h>
#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll
#define BUF_SIZE 100

//小游戏的宏
# define BlockSize 40 // 小方块的长宽大小
# define RowNum 13 // 游戏画面一共RowNum行小方块
# define ColNum 21 // 游戏画面一共ColNum列小方块
# define ColorTypeNum 9 // 方块彩色颜色的个数
#define BLOCK_SIZE 20 // 每个小格子的长宽大小 
#define HEIGHT 30 // 高度上一共30个小格子
#define WIDTH 40 //  宽度上一共40个小格子 


using namespace std;
//账户管理类实例化
qqclient_wfn qqclient;
wxclient_wfn wxclient;
wbclient_wfn wbclient;

int str_to_num(string s);//字转数

void client();//点对点通讯客户端
void initialization();//套接字初始化

//从文件中读取数据进行初始化
void weixin_initialise();
void qq_initialise();
void weixin_group_initialise();
void qq_group_initialise();
void weibo_initialise();
void initialise();

//把数据写入文件中
void write_in_weixin_client();
void write_in_qq_client();
void write_in_qq_group();
void write_in_weixin_group();
void write_in_weibo_client();
void write_in();

//界面
void main_view();
void user_view();
void user_view();
void QQ_view();
void operate_QQ(int);
void user_operate_QQ_group(int);
void operate_weixin(int);
void operate_weibo(int);
void weibo_view();
void weixin_view();
void game_view();

//小游戏
void tanchishe();
void shizixiaochu();

//函数实现
int str_to_num(string s) {
    int num;
    stringstream ss(s);
    ss >> num;
    return num;
}


void weibo_initialise() {
    int intTemp1, intTemp2, intTemp3;
    string str;
    ifstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\weibo.txt");
    if (!infile) cout << "error" << endl;
    getline(infile, str);//读入微博的个数
    wbaccount_wfn::wbnumber = str_to_num(str);
    intTemp1 = wbaccount_wfn::wbnumber;
    wbclient.initialise_weibo(wbaccount_wfn::wbnumber);
    wbaccount_wfn::wbnumber -= intTemp1;
    //cout<<WeiboAccountZQA::weiboNumber<<endl;

    for (int i = 0; i < wbaccount_wfn::wbnumber; i++) {
        getline(infile, str);//读入账号
        intTemp1 = str_to_num(str);
        wbclient.wbClient[i].set_id(intTemp1);

        getline(infile, str);//读入密码
        wbclient.wbClient[i].set_password(str);

        getline(infile, str);//读入昵称
        wbclient.wbClient[i].set_name(str);

        getline(infile, str);//读入生日
        intTemp1 = str_to_num(str);
        getline(infile, str);
        intTemp2 = str_to_num(str);
        getline(infile, str);
        intTemp3 = str_to_num(str);
        wbclient.wbClient[i].set_birthday(intTemp1, intTemp2, intTemp3);

        getline(infile, str);//读入创建时间
        intTemp1 = str_to_num(str);
        getline(infile, str);
        intTemp2 = str_to_num(str);
        getline(infile, str);
        intTemp3 = str_to_num(str);
        wbclient.wbClient[i].set_settime(intTemp1, intTemp2, intTemp3);

        getline(infile, str);//读入绑定的QQ
        intTemp1 = str_to_num(str);
        wbclient.wbClient[i].set_qqid(intTemp1);

        getline(infile, str);//读入城市
        wbclient.wbClient[i].set_location(str);

        getline(infile, str);//读入好友列表
        while (str != "*") {
            intTemp1 = str_to_num(str);
            wbclient.wbClient[i].no_output_add_friend(intTemp1);
            getline(infile, str);
        }

        //WeiboClient.weiboClient[i].show_infor();
    }
    infile.close();
}
void weixin_initialise() {
    int intTemp1, intTemp2, intTemp3;
    string str;     
    ifstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\wechat_cilent.txt");
    if (!infile) cout << "error" << endl;
    getline(infile, str);//读入微信的个数
    wxaccount_wfn::wxnumber = str_to_num(str);
    intTemp1 = wxaccount_wfn::wxnumber;
    wxclient.initialise_weixin(wxaccount_wfn::wxnumber);
    wxaccount_wfn::wxnumber -= intTemp1;
    //cout<<WeixinAccountZQA::weixinNumber<<endl;

    for (int i = 0; i < wxaccount_wfn::wxnumber; i++) {
        getline(infile, str);//读入账号
        intTemp1 = str_to_num(str);
        wxclient.weixinClient[i].set_id(intTemp1);

        getline(infile, str);//读入昵称
        wxclient.weixinClient[i].set_password(str);

        getline(infile, str);//读入昵称
        wxclient.weixinClient[i].set_name(str);

        getline(infile, str);//读入生日
        intTemp1 = str_to_num(str);
        getline(infile, str);
        intTemp2 = str_to_num(str);
        getline(infile, str);
        intTemp3 = str_to_num(str);
        wxclient.weixinClient[i].set_birthday(intTemp1, intTemp2, intTemp3);

        getline(infile, str);//读入创建时间
        intTemp1 = str_to_num(str);
        getline(infile, str);
        intTemp2 = str_to_num(str);
        getline(infile, str);
        intTemp3 = str_to_num(str);
        wxclient.weixinClient[i].set_settime(intTemp1, intTemp2, intTemp3);

        getline(infile, str);//读入绑定的QQ
        intTemp1 = str_to_num(str);
        wxclient.weixinClient[i].set_qqid(intTemp1);

        getline(infile, str);//读入城市
        wxclient.weixinClient[i].set_location(str);

        getline(infile, str);//读入好友列表
        while (str != "*") {
            intTemp1 = str_to_num(str);
            wxclient.weixinClient[i].no_output_add_friend(intTemp1);
            getline(infile, str);
        }
        getline(infile, str);//读入群组列表
        while (str != "*") {
            intTemp1 = str_to_num(str);
            wxclient.weixinClient[i].no_output_enter_group(intTemp1);
            getline(infile, str);
        }


        //WeixinClient.QQvector[i].show_infor();
    }
    infile.close();

}
void qq_initialise() {//将文件内容输入到类中
    int intTemp1, intTemp2, intTemp3;
    string str;
    ifstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\qq_cilent.txt");
    if (!infile) cout << "error" << endl;
    getline(infile, str);//读入账号
    qqaccount_wfn::qqNumber = str_to_num(str);
    intTemp1 = qqaccount_wfn::qqNumber;
    //cout<<QQAccountZQA::qqNumber<<endl;
    qqclient.initialise_QQ(qqaccount_wfn::qqNumber);
    qqaccount_wfn::qqNumber -= intTemp1;
    //cout<<QQAccountZQA::qqNumber<<endl;
    for (int i = 0; i < qqaccount_wfn::qqNumber; i++) {
        getline(infile, str);//读入账号
        intTemp1 = str_to_num(str);
        qqclient.qqvector[i].set_id(intTemp1);

        getline(infile, str);//读入密码
        qqclient.qqvector[i].set_password(str);

        getline(infile, str);//读入昵称
        qqclient.qqvector[i].set_name(str);

        getline(infile, str);//读入生日
        intTemp1 = str_to_num(str);
        getline(infile, str);
        intTemp2 = str_to_num(str);
        getline(infile, str);
        intTemp3 = str_to_num(str);
        qqclient.qqvector[i].set_birthday(intTemp1, intTemp2, intTemp3);

        getline(infile, str);//读入创建时间
        intTemp1 = str_to_num(str);
        getline(infile, str);
        intTemp2 = str_to_num(str);
        getline(infile, str);
        intTemp3 = str_to_num(str);
        qqclient.qqvector[i].set_settime(intTemp1, intTemp2, intTemp3);

        getline(infile, str);//读入绑定的微信
        intTemp1 = str_to_num(str);
        qqclient.qqvector[i].set_wxid(intTemp1);

        getline(infile, str);//读入绑定的微博
        intTemp1 = str_to_num(str);
        qqclient.qqvector[i].set_weibo_id(intTemp1);

        getline(infile, str);//读入城市
        qqclient.qqvector[i].set_location(str);

        getline(infile, str);
        while (str != "*") {
            intTemp1 = str_to_num(str);
            qqclient.qqvector[i].no_output_add_friend(intTemp1);
            getline(infile, str);
        }
        getline(infile, str);
        while (str != "*") {
            intTemp1 = str_to_num(str);
            qqclient.qqvector[i].no_output_enter_group(intTemp1);
            getline(infile, str);
        }


        //QQClient.QQvector[i].show_infor();
    }
    infile.close();
}
void weixin_group_initialise() {
    int intTemp1, intTemp2;
    string str;
    ifstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\wechat_group.txt");
    if (!infile) cout << "error" << endl;
    getline(infile, str);//已有的微信群个数
    wxgroup_wfn::wxgroupNumber = str_to_num(str);
    intTemp1 = wxgroup_wfn::wxgroupNumber;
    //cout<<WeiXinGroupZQA::weiXinGroupNumber<<endl;
    wxclient.initialise_weixin_group(wxgroup_wfn::wxgroupNumber);//为这些qq群分配空间
    wxgroup_wfn::wxgroupNumber -= intTemp1;//减去构造函数增加的qq群个数

    for (int i = 0; i < wxgroup_wfn::wxgroupNumber; i++) {
        getline(infile, str);//读入群账号
        intTemp1 = str_to_num(str);
        wxclient.weixinGroup[i].set_group_id(intTemp1);

        getline(infile, str);//读入群主账号
        intTemp1 = str_to_num(str);
        wxclient.weixinGroup[i].set_groupowner_id(intTemp1);

        getline(infile, str);//读入群成员
        while (str != "*") {
            intTemp1 = str_to_num(str);
            wxclient.weixinGroup[i].no_output_add_member(intTemp1);
            getline(infile, str);
        }
        //WeixinClient.weixinGroup[i].show_group_infor();
    }
}
void qq_group_initialise() {//对QQ群进行初始化
    int intTemp1, intTemp2;
    string str;
    ifstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\qq_group.txt");
    if (!infile) cout << "error" << endl;
    getline(infile, str);//已有的qq群个数
    qqgroup_wfn::qqGroupNumber = str_to_num(str);
    intTemp1 = qqgroup_wfn::qqGroupNumber;
    //cout<<QQGroupZQA::qqGroupNumber<<endl;
    qqclient.initialise_qq_group(qqgroup_wfn::qqGroupNumber);//为这些qq群分配空间
    qqgroup_wfn::qqGroupNumber -= intTemp1;//减去构造函数增加的qq群个数
    for (int i = 0; i < qqgroup_wfn::qqGroupNumber; i++) {
        getline(infile, str);//读入群账号
        intTemp1 = str_to_num(str);
        qqclient.qqgroup[i].set_group_id(intTemp1);

        getline(infile, str);//读入群主账号
        intTemp1 = str_to_num(str);
        qqclient.qqgroup[i].set_groupowner_id(intTemp1);

        getline(infile, str);//读入群管理员
        while (str != "*") {
            intTemp1 = str_to_num(str);
            qqclient.qqgroup[i].no_output_set_admin(intTemp1);
            getline(infile, str);
        }

        getline(infile, str);//读入群成员
        while (str != "*") {
            intTemp1 = str_to_num(str);
            qqclient.qqgroup[i].no_output_add_member(intTemp1);
            getline(infile, str);
        }
        //QQClient.QQgroup[i].show_group_infor();
    }

}
void initialise() {
    qq_initialise();
    qq_group_initialise();
    weixin_initialise();
    weixin_group_initialise();
    weibo_initialise();

}


void write_in_weibo_client() {//写入文件中
    ofstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\weibo.txt", ios::out);
    //infile<<"1"<<endl;

    //infile<<"2"<<endl;
    infile << wbaccount_wfn::wbnumber << endl;
    for (int i = 0; i < wbaccount_wfn::wbnumber; i++) {
        infile << wbclient.wbClient[i].get_id() << endl;
        infile << wbclient.wbClient[i].get_password() << endl;
        infile << wbclient.wbClient[i].get_name() << endl;
        infile << wbclient.wbClient[i].get_birthday().get_year() << endl;
        infile << wbclient.wbClient[i].get_birthday().get_month() << endl;
        infile << wbclient.wbClient[i].get_birthday().get_day() << endl;
        infile << wbclient.wbClient[i].get_registrate_date().get_year() << endl;
        infile << wbclient.wbClient[i].get_registrate_date().get_month() << endl;
        infile << wbclient.wbClient[i].get_registrate_date().get_day() << endl;
        infile << wbclient.wbClient[i].get_qqid() << endl;
        infile << wbclient.wbClient[i].get_location() << endl;
        //infile<<"测试"<<endl;
        if (!wbclient.wbClient[i].get_friendlist().empty()) {
            for (int j = 0; j < wbclient.wbClient[i].get_friendlist().size(); j++) {
                infile << wbclient.wbClient[i].get_friendlist()[j] << endl;
            }
        }
        infile << "*" << endl;
    }
}
void write_in_weixin_client() {
    ofstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\wechat_cilent.txt", ios::out);
    //infile<<"1"<<endl;

    //infile<<"2"<<endl;
    infile << wxaccount_wfn::wxnumber << endl;
    for (int i = 0; i < wxaccount_wfn::wxnumber; i++) {
        infile << wxclient.weixinClient[i].get_id() << endl;
        infile << wxclient.weixinClient[i].get_password() << endl;
        infile << wxclient.weixinClient[i].get_name() << endl;
        infile << wxclient.weixinClient[i].get_birthday().get_year() << endl;
        infile << wxclient.weixinClient[i].get_birthday().get_month() << endl;
        infile << wxclient.weixinClient[i].get_birthday().get_day() << endl;
        infile << wxclient.weixinClient[i].get_registrate_date().get_year() << endl;
        infile << wxclient.weixinClient[i].get_registrate_date().get_month() << endl;
        infile << wxclient.weixinClient[i].get_registrate_date().get_day() << endl;
        infile << wxclient.weixinClient[i].get_qqid() << endl;
        infile << wxclient.weixinClient[i].get_location() << endl;
        //infile<<"测试"<<endl;
        for (int j = 0; j < wxclient.weixinClient[i].get_friendlist().size(); j++) {
            infile << wxclient.weixinClient[i].get_friendlist()[j] << endl;
        }
        infile << "*" << endl;
        for (int j = 0; j < wxclient.weixinClient[i].get_grouplist().size(); j++) {
            infile << wxclient.weixinClient[i].get_grouplist()[j] << endl;
        }
        infile << "*" << endl;
    }
}
void write_in_qq_client() {
    ofstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\qq_cilent.txt", ios::out);
    //infile<<"1"<<endl;

    //infile<<"2"<<endl;
    infile << qqaccount_wfn::qqNumber << endl;
    for (int i = 0; i < qqaccount_wfn::qqNumber; i++) {
        infile << qqclient.qqvector[i].get_id() << endl;
        infile << qqclient.qqvector[i].get_password() << endl;
        infile << qqclient.qqvector[i].get_name() << endl;
        infile << qqclient.qqvector[i].get_birthday().get_year() << endl;
        infile << qqclient.qqvector[i].get_birthday().get_month() << endl;
        infile << qqclient.qqvector[i].get_birthday().get_day() << endl;
        infile << qqclient.qqvector[i].get_registrate_date().get_year() << endl;
        infile << qqclient.qqvector[i].get_registrate_date().get_month() << endl;
        infile << qqclient.qqvector[i].get_registrate_date().get_day() << endl;
        infile << qqclient.qqvector[i].get_wxid() << endl;
        infile << qqclient.qqvector[i].get_weibo_id() << endl;
        infile << qqclient.qqvector[i].get_location() << endl;
        //infile<<"测试"<<endl;
        for (int j = 0; j < qqclient.qqvector[i].get_friendlist().size(); j++) {
            infile << qqclient.qqvector[i].get_friendlist()[j] << endl;
        }
        infile << "*" << endl;
        for (int j = 0; j < qqclient.qqvector[i].get_grouplist().size(); j++) {
            infile << qqclient.qqvector[i].get_grouplist()[j] << endl;
        }
        infile << "*" << endl;
    }
}
void write_in_weixin_group() {
    ofstream infile;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\wechat_group.txt", ios::out);
    infile << wxgroup_wfn::wxgroupNumber << endl;//写入群的个数
    for (int i = 0; i < wxgroup_wfn::wxgroupNumber; i++) {
        infile << wxclient.weixinGroup[i].get_group_id() << endl;//写入账号
        infile << wxclient.weixinGroup[i].get_groupowner_id() << endl;//写入群主账号
        for (int j = 0; j < wxclient.weixinGroup[i].get_member_id().size(); j++) {//写入成员账号
            infile << wxclient.weixinGroup[i].get_member_id()[j] << endl;
        }
        infile << "*" << endl;
    }
}
void write_in_qq_group() {
    ofstream infile;
    qqgroup_wfn::qqGroupNumber -= qqgroup_wfn::sonGroupNumber;
    infile.open("C:\\Users\\20161\\Desktop\\课设文件\\qq_group.txt", ios::out);
    infile << qqgroup_wfn::qqGroupNumber << endl;//写入群组数量
    for (int i = 0; i < qqgroup_wfn::qqGroupNumber; i++) {
        if (qqclient.qqgroup[i].get_father_group_id() != 0) {
            i--;
            continue;
        }
        infile << qqclient.qqgroup[i].get_group_id() << endl;//群账号
        infile << qqclient.qqgroup[i].get_groupowner_id() << endl;//群主账号

        for (int j = 0; j < qqclient.qqgroup[i].get_admin_id().size(); j++) {
            infile << qqclient.qqgroup[i].get_admin_id()[j] << endl;
        }
        infile << "*" << endl;

        for (int j = 0; j < qqclient.qqgroup[i].get_member_id().size(); j++) {
            infile << qqclient.qqgroup[i].get_member_id()[j] << endl;
        }
        infile << "*" << endl;
    }
}
void write_in() {
    write_in_qq_group();
    write_in_weixin_group();
    write_in_qq_client();
    write_in_weixin_client();
    write_in_weibo_client();
}
int input_QQ_id(int id) {//输入或输出QQ账号
    while (1) {
        for (int i = 0; i < qqclient.qqvector.size(); i++) {
            if (id == qqclient.qqvector[i].get_id())
                return i;
        }
        cout << "该账号不存在，请重新输入:" << endl;
        cin >> id;
    }
}
int input_weixin_id(int id) {
    while (1) {
        for (int i = 0; i < wxclient.weixinClient.size(); i++) {
            if (id == wxclient.weixinClient[i].get_id())
                return i;
        }
        cout << "该账号不存在，请重新输入:" << endl;
        cin >> id;
    }
}
int input_weibo_id(int id) {
    while (1) {
        for (int i = 0; i < wbclient.wbClient.size(); i++) {
            if (id == wbclient.wbClient[i].get_id())
                return i;
        }
        cout << "该账号不存在，请重新输入:" << endl;
        cin >> id;
    }
}


int judge_weixin_id_exist(int id) {
    for (int i = 0; i < wxclient.weixinClient.size(); i++) {
        if (id == wxclient.weixinClient[i].get_id())
            return i;
    }
    return -1;
}
int judge_weibo_id_exist(int id) {
    for (int i = 0; i < wbclient.wbClient.size(); i++) {
        if (id == wbclient.wbClient[i].get_id())
            return i;
    }
    return -1;
}
int judge_QQ_id_exist(int id) {//判断QQ账号是否存在
    for (int i = 0; i < qqclient.qqvector.size(); i++) {
        if (id == qqclient.qqvector[i].get_id())
            return i;
    }
    return -1;
}


int QQ_login() {//登录QQ
    string password;
    int QQtemp, weixinTemp, weiboTemp, number;
    cout << "    请输入QQ账号：" << "    ";
    cin >> number;
    QQtemp = judge_QQ_id_exist(number);
    if (QQtemp != -1) {
        cout << "    请输入密码：" << "    ";
        cin >> password;
        qqclient.qqvector[QQtemp].login(password);
    }
    else {
        cout << "    该账号不存在！" << endl;
        system("pause");
        QQ_view();
    }
    weixinTemp = judge_weixin_id_exist(qqclient.qqvector[QQtemp].get_wxid());
    if (weixinTemp != -1) {
        wxclient.weixinClient[weixinTemp].no_output_login();
    }
    weiboTemp = judge_weibo_id_exist(qqclient.qqvector[QQtemp].get_weibo_id());
    if (weiboTemp != -1) {
        wbclient.wbClient[weiboTemp].no_output_login();
    }
    return QQtemp;
}
int weixin_login() {
    string password;
    int QQtemp, weixinTemp, weiboTemp, number;
    cout << "    请输入微信账号：";
    cout << "    ";
    cin >> number;
    weixinTemp = judge_weixin_id_exist(number);
    if (weixinTemp != -1) {
        cout << "    请输入密码：";
        cout << "    ";
        cin >> password;
        wxclient.weixinClient[weixinTemp].login(password);
    }
    else {
        cout << "    该账号不存在！" << endl;
        system("pause");
        weixin_view();
    }
    QQtemp = judge_QQ_id_exist(wxclient.weixinClient[weixinTemp].get_qqid());
    if (QQtemp != -1) {
        qqclient.qqvector[QQtemp].no_output_login();
        weiboTemp = judge_weibo_id_exist(qqclient.qqvector[QQtemp].get_weibo_id());
        if (weiboTemp != -1) {
            wbclient.wbClient[weiboTemp].no_output_login();
        }
    }
    return weixinTemp;
}
int weibo_login() {
    string password;
    int QQtemp, weixinTemp, weiboTemp, number;
    cout << "    请输入微博账号：";
    cout << "    ";
    cin >> number;
    weiboTemp = judge_weibo_id_exist(number);
    if (weiboTemp != -1) {
        cout << "    请输入密码：";
        cout << "    ";
        cin >> password;
        wbclient.wbClient[weiboTemp].login(password);
    }
    else {
        cout << "    该账号不存在！" << endl;
        system("pause");
        weibo_view();
    }
    QQtemp = judge_QQ_id_exist(wbclient.wbClient[weiboTemp].get_qqid());
    if (QQtemp != -1) {
        qqclient.qqvector[QQtemp].no_output_login();

        weixinTemp = judge_weixin_id_exist(qqclient.qqvector[QQtemp].get_wxid());
        if (weixinTemp != -1) {
            wxclient.weixinClient[weixinTemp].no_output_login();
        }
    }
    return weiboTemp;
}


void user_operate_QQ_group(int site) {//QQ群操作界面
    int flag, choose, number, temp;
    flag = 0;
    cout << "    管理的群：" << endl;
    for (int i = 0; i < qqclient.qqgroup.size(); i++) {
        for (int j = 0; j < qqclient.qqgroup[i].get_admin_id().size(); j++) {
            if (qqclient.qqgroup[i].get_admin_id()[j] == qqclient.qqvector[site].get_id()) {
                cout << "    " << qqclient.qqgroup[i].get_group_id() << endl;
                flag = 1;
            }
        }
    }
    if (!flag) {
        cout << "    你不是任何群的管理员！" << endl;
    }
    else {
        cout << "    请输入要进行操作的群：    ";
        cin >> number;
        for (int i = 0; i < qqclient.qqgroup.size(); i++) {
            if (qqclient.qqgroup[i].get_group_id() == number) {
                cout << "    请输入想要对群进行的操作：" << endl;
                cout << "    1、踢人出群" << endl;
                cout << "    2、拉人进群" << endl;
                cout << "    3、设置他人为管理员" << endl;
                cout << "    4、取消他人的管理员身份" << endl;
                cout << "    5、创建临时讨论组（讨论组并不会保存在文件中）：" << endl;
                cout << "    6、查看由该群创建的临时讨论组:" << endl;
                cout << "    0、返回上一级" << endl;//
                cout << "    ";
                cin >> choose;
                if (choose == 1) {
                    cout << "    请根据下列群组信息踢人。" << endl;
                    qqclient.qqgroup[i].show_group_infor();
                    temp = qqclient.qqgroup[i].delete_member();
                    for (int k = 0; k < qqclient.qqvector.size(); k++) {
                        if (qqclient.qqvector[k].get_id() == temp) {
                            qqclient.qqvector[k].no_output_exit_group(qqclient.qqgroup[i].get_group_id());
                        }
                    }

                }
                if (choose == 2) {
                    cout << "    请根据下列群组信息拉人。" << endl;
                    qqclient.qqgroup[i].show_group_infor();
                    temp = qqclient.qqgroup[i].add_member();
                    for (int k = 0; k < qqclient.qqvector.size(); k++) {
                        if (qqclient.qqvector[k].get_id() == temp) {
                            qqclient.qqvector[k].no_output_enter_group(qqclient.qqgroup[i].get_group_id());
                        }
                    }
                }
                if (choose == 3) {
                    cout << "    请根据下列群组信息设置管理员。" << endl;
                    qqclient.qqgroup[i].show_group_infor();
                    qqclient.qqgroup[i].set_admin();
                }
                if (choose == 4) {
                    cout << "    请根据下列群组信息取消管理员。" << endl;
                    qqclient.qqgroup[i].show_group_infor();
                    qqclient.qqgroup[i].delete_admin();
                }
                if (choose == 5) {
                    cout << "    请根据下列群组信息创建临时讨论组。" << endl;
                    qqclient.qqgroup[i].show_group_infor();
                    qqclient.set_son_group(qqclient.qqgroup[i].get_group_id());
                }
                if (choose == 6) {
                    qqclient.show_son_group_infor(qqclient.qqgroup[i].get_group_id());
                }
                if (choose == 0) {
                    QQ_view();
                    return;
                }
            }
        }
    }
}
void user_operate_weixin_group(int site) {
    int flag, choose, number, temp;
    flag = 0;
    cout << "    管理的群：" << endl;
    for (int i = 0; i < wxclient.weixinGroup.size(); i++) {
        if (wxclient.weixinGroup[i].get_groupowner_id() == wxclient.weixinClient[site].get_id()) {
            cout << "    " << wxclient.weixinGroup[i].get_group_id() << endl;
            flag = 1;
        }
    }
    if (!flag) {
        cout << "    你不是任何群的管理员！" << endl;
    }
    else {
        cout << "    请输入要进行操作的群：" << "    ";
        cin >> number;
        for (int i = 0; i < wxclient.weixinGroup.size(); i++) {
            if (wxclient.weixinGroup[i].get_group_id() == number) {
                cout << "    请输入想要对群进行的操作：" << endl;
                cout << "    1、踢人出群" << endl;
                cout << "    2、拉人进群" << endl;
                cout << "    3、查看群信息" << endl;
                cout << "    0、返回上一级" << endl << "    ";//
                cin >> choose;
                if (choose == 1) {
                    cout << "    请根据下列群组信息踢人。" << endl;
                    wxclient.weixinGroup[i].show_group_infor();
                    temp = wxclient.weixinGroup[i].delete_member();
                    for (int k = 0; k < wxclient.weixinClient.size(); k++) {
                        if (wxclient.weixinClient[k].get_id() == temp) {
                            wxclient.weixinClient[k].no_output_exit_group(wxclient.weixinGroup[i].get_group_id());
                        }
                    }
                }
                if (choose == 2) {
                    cout << "    请根据下列群组信息拉人。" << endl;
                    wxclient.weixinGroup[i].show_group_infor();
                    temp = wxclient.weixinGroup[i].add_member();
                    for (int k = 0; k < wxclient.weixinClient.size(); k++) {
                        if (wxclient.weixinClient[k].get_id() == temp) {
                            wxclient.weixinClient[k].no_output_enter_group(wxclient.weixinGroup[i].get_group_id());
                        }
                    }
                }
                if (choose == 3) {
                    wxclient.weixinGroup[i].show_group_infor();
                }
                if (choose == 0) {
                    weixin_view();
                    return;
                }
                return;
            }
        }
    }
}

void add_recommend_friend(int site) {
    int weixinSite, weiboSite, flag, number;
    if (qqclient.qqvector[site].get_wxid() == 0)
        cout << "    该用户还未绑定微信！" << endl;
    else {
        flag = 0;
        cout << "    微信中可添加的推荐好友为：" << endl;
        weixinSite = judge_weixin_id_exist(qqclient.qqvector[site].get_wxid());
        for (int i = 0; i < wxclient.weixinClient[weixinSite].get_friendlist().size(); i++) {
            for (int j = 0; j < qqclient.qqvector[site].get_friendlist().size(); j++) {
                if (wxclient.weixinClient[judge_weixin_id_exist(wxclient.weixinClient[weixinSite].get_friendlist()[i])].get_qqid() == qqclient.qqvector[site].get_friendlist()[j]) {
                    //cout<<QQClient.QQvector[site].get_friendlist()[0]<<endl;
                    break;
                }
                if (j == qqclient.qqvector[site].get_friendlist().size() - 1) {
                    cout << wxclient.weixinClient[judge_weixin_id_exist(wxclient.weixinClient[weixinSite].get_friendlist()[i])].get_qqid() << endl;
                    flag = 1;
                }
            }
        }
        if (!flag) {
            cout << "    微信中并没有推荐好友！" << endl;
        }
        else {
            cout << "    请根据以上信息添加推荐好友,";
            number = qqclient.qqvector[site].get_id();
            qqclient.add_friend(number);
        }
    }
    if (qqclient.qqvector[site].get_weibo_id() == 0)
        cout << "    该用户还未绑定微博！" << endl;
    else {
        flag = 0;
        cout << "    微博中可添加的推荐好友为：" << endl;
        weiboSite = judge_weibo_id_exist(qqclient.qqvector[site].get_weibo_id());
        for (int i = 0; i < wbclient.wbClient[weiboSite].get_friendlist().size(); i++) {
            for (int j = 0; j < qqclient.qqvector[site].get_friendlist().size(); j++) {
                if (wbclient.wbClient[judge_weibo_id_exist(wbclient.wbClient[weiboSite].get_friendlist()[i])].get_qqid() == qqclient.qqvector[site].get_friendlist()[j]) {
                    break;
                }
                if (j == qqclient.qqvector[site].get_friendlist().size() - 1) {
                    cout << "    " << wbclient.wbClient[judge_weibo_id_exist(wbclient.wbClient[weiboSite].get_friendlist()[i])].get_qqid() << endl;
                    flag = 1;
                }
            }
        }
        if (!flag) {
            cout << "    微博中并没有可添加的推荐好友！" << endl;
        }
        else {
            cout << "    请根据以上信息添加推荐好友" << endl;
            qqclient.add_friend(qqclient.qqvector[site].get_id());
        }
    }
}

void operate_QQ(int site) {//QQ操作界面
    int choose = 0;
    int number;
    int temp, flag;
    string password;
    cout << "    请输入要进行的操作：" << endl;
    cout << "    1、输出个人信息" << endl;//
    cout << "    2、修改个人信息" << endl;//
    cout << "    3、创建一个群" << endl;//
    cout << "    4、对自己管理的群进行操作" << endl;//
    cout << "    5、添加好友" << endl;//
    cout << "    6、删除好友" << endl;//
    cout << "    7、查找好友" << endl;//
    cout << "    8、加入群" << endl;//
    cout << "    9、退出群" << endl;//
    cout << "    10、添加微信和微博的推荐好友" << endl;
    cout << "    11、创建微博并绑定" << endl;//
    cout << "    12、创建微信并绑定" << endl;//
    cout << "    13、向好友发送信息" << endl;//
    cout << "    14、小游戏" << endl;//
    cout << "    15、重设密码" << endl;//
    cout << "    0、返回上一级" << endl;//
    cout << "    ";
    cin >> choose;
    if (choose == 1) {
        qqclient.qqvector[site].show_information();
        operate_QQ(site);
        return;
    }
    if (choose == 2) {
        qqclient.qqvector[site].change_information();
        operate_QQ(site);
        return;
    }
    if (choose == 3) {
        qqclient.set_new_QQ_group(qqclient.qqvector[site].get_id());
        operate_QQ(site);
        return;
    }
    if (choose == 4) {//未完成
        user_operate_QQ_group(site);
        operate_QQ(site);
        return;
    }
    if (choose == 5) {
        qqclient.add_friend(qqclient.qqvector[site].get_id());
        operate_QQ(site);
        return;
    }
    if (choose == 6) {
        qqclient.delete_friend(qqclient.qqvector[site].get_id());
        operate_QQ(site);
        return;
    }
    if (choose == 7) {
        //chaxun
        qqclient.chaxun_friend(qqclient.qqvector[site].get_id());
        operate_QQ(site);
        return;
    }
    if (choose == 8) {
        qqclient.enter_group(qqclient.qqvector[site].get_id());
        operate_QQ(site);
        return;
    }
    if (choose == 9) {
        qqclient.exit_group(qqclient.qqvector[site].get_id());
        operate_QQ(site);
        return;
    }
    if (choose == 10) {//添加推荐好友
        add_recommend_friend(site);
        operate_QQ(site);
        return;
    }
    if (choose == 11) {
        if (qqclient.qqvector[site].get_weibo_id() != 0) {
            cout << "    你已经绑定了一个微博，不可重复创建！" << endl;
        }
        else {
            wbaccount_wfn newWeibo;
            newWeibo.set_qqid(qqclient.qqvector[site].get_id());
            newWeibo.set_wb();
            wbclient.wbClient.push_back(newWeibo);
            qqclient.qqvector[site].set_weibo_id(newWeibo.get_id());
        }
        operate_QQ(site);
        return;
    }
    if (choose == 12) {
        if (qqclient.qqvector[site].get_wxid() != 0) {
            cout << "    你已经绑定了一个微信，不可重复创建！" << endl;
        }
        else {
            wxaccount_wfn newWeixin;
            newWeixin.set_wx();
            newWeixin.set_qqid(qqclient.qqvector[site].get_id());
            wxclient.weixinClient.push_back(newWeixin);
            qqclient.qqvector[site].set_wxid(newWeixin.get_id());
        }
        operate_QQ(site);
        return;
    }
    if (choose == 13) {
        client();
        operate_QQ(site);
        return;
    }
    if (choose == 14) {
        game_view();
        system("cls");
        game_view();
        return;
    }
    if (choose == 15) {
        cout << "  请输入修改后的密码:" << endl;
        cin >> password;
        qqclient.qqvector[site].set_password(password);
        operate_QQ(site);
        return;
    }
    if (choose == 0) {
        QQ_view();
        return;
    }
    else {
        cout << "    无效输入！" << endl;
        operate_QQ(site);
        return;
    }
}
void operate_weixin(int site) {
    int choose = 0;
    int number;
    int temp, flag;
    cout << "    请输入要进行的操作：" << endl;
    cout << "    1、输出个人信息" << endl;//
    cout << "    2、修改个人信息" << endl;//
    cout << "    3、创建一个群" << endl;//
    cout << "    4、对自己创建的群进行操作" << endl;//
    cout << "    5、添加好友" << endl;//
    cout << "    6、删除好友" << endl;//
    cout << "    7、查找好友" << endl;
    cout << "    8、退出群" << endl;//
    cout << "    9、创建一个QQ并绑定" << endl;////
    cout << "    0、返回上一级" << endl;//
    cout << "    ";
    cin >> choose;
    if (choose == 1) {
        wxclient.weixinClient[site].show_information();
        operate_weixin(site);
        return;
    }
    if (choose == 2) {
        wxclient.weixinClient[site].change_information();
        operate_weixin(site);
        return;
    }
    if (choose == 3) {
        wxclient.set_new_weixin_group(wxclient.weixinClient[site].get_id());
        operate_weixin(site);
        return;
    }
    if (choose == 4) {//未完成
        user_operate_weixin_group(site);
        operate_weixin(site);
        return;
    }
    if (choose == 5) {
        wxclient.add_friend(wxclient.weixinClient[site].get_id());
        operate_weixin(site);
        return;
    }
    if (choose == 6) {
        wxclient.delete_friend(wxclient.weixinClient[site].get_id());
        operate_weixin(site);
        return;
    }
    if (choose == 7) {
        //查询
        wxclient.chaxun_friend(wxclient.weixinClient[site].get_id());
        operate_weixin(site);
        return;
    }
    if (choose == 8) {
        wxclient.exit_group(wxclient.weixinClient[site].get_id());
        operate_weixin(site);
        return;
    }
    if (choose == 9) {
        if (wxclient.weixinClient[site].get_qqid() != 0) {
            cout << "    你已经绑定了一个QQ，不可重复创建！" << endl;
        }
        else {
            qqaccount_wfn newQQ;
            newQQ.set_qq();
            newQQ.set_wxid(wxclient.weixinClient[site].get_id());
            qqclient.qqvector.push_back(newQQ);
            wxclient.weixinClient[site].set_qqid(newQQ.get_id());
        }
        operate_weixin(site);
        return;
    }
    if (choose == 0) {
        return;
    }
    else {
        cout << "    无效输入！" << endl;
        operate_weixin(site);
        return;
    }
}
void operate_weibo(int site) {
    int choose = 0;
    int number;
    int temp, flag;
    cout << "    请输入要进行的操作：" << endl;
    cout << "    1、输出个人信息" << endl;//
    cout << "    2、修改个人信息" << endl;//
    cout << "    3、添加好友" << endl;//
    cout << "    4、删除好友" << endl;//
    cout << "    5、查找好友" << endl;
    cout << "    0、返回上一级" << endl;//
    cout << "    ";
    cin >> choose;
    if (choose == 1) {
        wbclient.wbClient[site].show_information();
        operate_weibo(site);
        return;
    }
    if (choose == 2) {
        wbclient.wbClient[site].change_information();
        operate_weibo(site);
        return;
    }
    if (choose == 3) {
        wbclient.add_friend(wbclient.wbClient[site].get_id());
        operate_weibo(site);
        return;
    }
    if (choose == 4) {
        wbclient.delete_friend(wbclient.wbClient[site].get_id());
        operate_weibo(site);
        return;
    }
    if (choose == 5) {
        //查询
        wbclient.chaxun_friend(wbclient.wbClient[site].get_id());
        operate_weibo(site);
        return;
    }
    if (choose == 0) {
        return;
    }
    else {
        cout << "    无效输入！" << endl;
        operate_weibo(site);
        return;
    }
}

void QQ_view() {//QQ主页面
    int choose = 0;
    int number;
    int temp;
    string password;
    system("cls");
    cout << "\n\n\n\t\t------------QQ用户界面-----------" << endl;
    cout << "\n\t\t\t\t1:<登录QQ>" << endl;
    cout << "\n\t\t\t\t2:<注册QQ>" << endl;
    cout << "\n\t\t\t\t3:<管理在线QQ>" << endl;
    cout << "\n\t\t\t\t4:<输出所有已注册的QQ信息>" << endl;
    cout << "\n\t\t\t\t0:<返回用户界面>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cin >> choose;
    if (choose == 1) {
        operate_QQ(QQ_login());
        system("pause");
        system("cls");
        return;
    }
    if (choose == 2) {
        qqclient.set_new_QQ_account();
        system("pause");
        QQ_view();
        return;
    }
    if (choose == 3) {
        int flag = 0;
        cout << "    已经登录的QQ:" << endl;
        for (int i = 0; i < qqclient.qqvector.size(); i++) {
            if (qqclient.qqvector[i].get_islogin() == 1) {
                cout << "    " << qqclient.qqvector[i].get_id() << endl;
                flag = 1;
            }
        }
        if (flag == 1) {
            cout << "    请输入要进行操作的QQ:" << "    ";
            cin >> number;
            temp = input_QQ_id(number);
            operate_QQ(temp);
            return;
        }
        else
            cout << "    还没有已登录的QQ!" << endl;
        system("pause");
        QQ_view();
        return;
    }
    if (choose == 4) {
        for (int i = 0; i < qqclient.qqvector.size(); i++) {
            qqclient.qqvector[i].show_information();
        }
        system("pause");
        system("cls");
        QQ_view();
        return;
    }
    if (choose == 0) {
        user_view();
        return;
    }
    else {
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        system("pause");
        system("cls");
        QQ_view();
        return;
    }
}
void weibo_view() {
    int choose = 0;
    int number;
    int temp;
    int flag = 0;
    string password;
    system("cls");
    cout << "\n\n\n\t\t-----------微博账号综合管理系统-----------" << endl;
    cout << "\n\t\t\t\t1:<微博账号登陆>" << endl;
    cout << "\n\t\t\t\t2:<对已登录的微博账号进行操作>" << endl;
    cout << "\n\t\t\t\t3:<输出所有已创建的微博信息>" << endl;
    cout << "\n\t\t\t\t0:<返回上一层>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cin >> choose;
    if (choose == 1) {
        operate_weibo(weibo_login());
        weibo_view();
        return;
    }
    if (choose == 2) {
        cout << "    已经登录的微博:" << endl;
        for (int i = 0; i < wbclient.wbClient.size(); i++) {
            if (wbclient.wbClient[i].get_islogin() == 1) {
                cout << "    " << wbclient.wbClient[i].get_id() << endl;
                flag = 1;
            }
        }
        if (flag == 1) {
            cout << "    请输入要进行操作的微博:" << endl;
            cout << "    ";
            cin >> number;
            temp = input_weibo_id(number);
            operate_weibo(temp);
            weibo_view();
            return;
        }
        else {
            cout << "    没有已登录的微博！" << endl;
            system("pause");
        }
        weibo_view();
        return;
    }
    if (choose == 3) {
        for (int i = 0; i < wbclient.wbClient.size(); i++) {
            wbclient.wbClient[i].show_information();
        }
        system("pause");
        system("cls");
        weibo_view();
        return;
    }
    if (choose == 0) {
        user_view();
        return;
    }
    else {
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        system("pause");
        system("cls");
        weibo_view();
        return;
    }
}
void weixin_view() {
    int choose = 0;
    int number;
    int temp;
    int flag = 0;
    string password;
    system("cls");
    cout << "\n\n\n\t\t-----------微信账号综合管理系统-----------" << endl;
    cout << "\n\t\t\t\t1:<微信账号登陆>" << endl;
    cout << "\n\t\t\t\t2:<对已登录的微信账号进行操作>" << endl;
    cout << "\n\t\t\t\t3:<注册微信账号>" << endl;
    cout << "\n\t\t\t\t4:<输出所有已创建的微信信息>" << endl;
    cout << "\n\t\t\t\t0:<返回上一层>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cin >> choose;
    if (choose == 1) {
        operate_weixin(weixin_login());
        weixin_view();
        return;
    }
    if (choose == 2) {
        cout << "    已经登录的微信:" << endl;
        for (int i = 0; i < wxclient.weixinClient.size(); i++) {
            if (wxclient.weixinClient[i].get_islogin() == 1) {
                cout << "    " << wxclient.weixinClient[i].get_id() << endl;
                flag = 1;
            }
        }
        if (flag == 1) {
            cout << "    请输入要进行操作的微信:";
            cout << "    ";
            cin >> number;
            temp = input_weixin_id(number);
            operate_weixin(temp);
            weixin_view();
            return;
        }
        else {
            cout << "    还没有已经登录的微信！" << endl;
            system("pause");
            weixin_view();
            return;
        }
    }
    if (choose == 3) {
        wxclient.set_new_weixin_account();
        weixin_view();
        return;
    }
    if (choose == 4) {
        for (int i = 0; i < wxclient.weixinClient.size(); i++) {
            wxclient.weixinClient[i].show_information();
        }
        system("pause");
        system("cls");
        weixin_view();
        return;
    }
    if (choose == 0) {
        user_view();
        return;
    }
    else {
        system("cls");
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        weixin_view();
        return;
    }
}
void main_view() {
    CONSOLE_TEXTMODE_BUFFER;
    system("color E0");
    system("cls");      //清屏函数
    int choose = 0;
    cout << "\n\n\n\t\t------------综合管理系统-----------" << endl;
    cout << "\n\t\t\t\t1:进入用户系统" << endl;
    cout << "\n\t\t\t\t0:<退出系统>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 2) {
        system("cls");
        if (choose == 1) {
            user_view();
            return;
        }
        if (choose == 0) {
            return;
        }
    }
    else {
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        system("pause");
        system("cls");
        main_view();
        return;
    }
}
void user_view() {
    int choose;
    system("cls");
    cout << "\n\n\n\t\t------------用户操作界面-----------" << endl;
    cout << "\n\t\t\t\t1:QQ界面" << endl;
    cout << "\n\t\t\t\t2:微信界面" << endl;
    cout << "\n\t\t\t\t3:微博界面" << endl;
    cout << "\n\t\t\t\t0:<返回主界面>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 3) {
        if (choose == 1) {
            QQ_view();
            return;
        }
        if (choose == 2) {
            weixin_view();
            return;
        }
        if (choose == 3) {
            weibo_view();
            return;
        }
        if (choose == 0) {
            main_view();
            return;
        }
    }
    else {
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        system("pause");
        system("cls");
        user_view();
        return;
    }
}
void game_view() {
    system("cls");
    int choose = 0;
    cout << "\n\n\n\t\t------------小游戏界面-----------" << endl;
    cout << "\n\t\t\t\t1:<贪吃蛇>" << endl;
    cout << "\n\t\t\t\t2:<十字消除>" << endl;
    cout << "\n\t\t\t\t0:<返回QQ主界面>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cout << "    ";
    cin >> choose;
    if (choose == 1) {
        tanchishe();
        return;
    }
    else if (choose == 2) {
        shizixiaochu();
        return;
    }
    else if (choose == 0) {
        QQ_view();
        return;
    }
    else {
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        system("pause");
        system("cls");
        game_view();
        return;
    }
}


//通讯区
//客户端
#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();
void client() {
    initialization();
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //AF_INET(IPV4) SOCK_STREAM(流套接字，使用TCP协议)  IPPROTO_TCP(TCP协议)
    if (s == INVALID_SOCKET) {
        printf("初始化套接字库失败！\n");
        return;
    }
    else {
        printf("初始化套接字库成功！\n");
    }
    //绑定IP和端口
    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(s, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) {
        printf("绑定失败！\n");
        return;
    }
    else {
        printf("绑定成功！\n");
    }
    //开始监听
    if (listen(s, 5) == SOCKET_ERROR) {
        printf("设置监听状态失败！\n");
        WSACleanup();
    }
    else {
        printf("设置监听状态成功！\n");
    }
    //循环接收数据
    SOCKET sclient;
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    char revdata[256];
    printf("连接ing.....\n");
    sclient = accept(s, (SOCKADDR*)&remoteAddr, &nAddrlen);
    if (s == INVALID_SOCKET) {
        printf("连接失败！\n");
        WSACleanup();
        return;
    }
    printf("连接建立，准备接受数据！\n");
    printf("成功接收：%s\r\n", inet_ntoa(remoteAddr.sin_addr));
    //接受数据
    while (1) {
        int ret = recv(sclient, revdata, 255, 0);
        if (ret > 0) {
            revdata[ret] = 0x00;
            printf("client:");
            printf(revdata);
        }
        else {
            printf("接受失败！\n");
            break;
        }
        printf("\nserver:");
        string data;
        cin >> data;
        const char* senddata;
        senddata = data.c_str();//string转const char*
        int send_len = send(sclient, senddata, strlen(senddata), 0);
        if (send_len < 0) {
            printf("发送失败！\n");
            break;
        }
    }
    closesocket(sclient);
    closesocket(s);
    WSACleanup();
    return;
}
void initialization() {
    //初始化套接字库
    WORD w_req = MAKEWORD(2, 2);//版本号
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        cout << "初始化套接字库失败！" << endl;
    }
    else {
        cout << "初始化套接字库成功！" << endl;
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        cout << "套接字库版本号不符！" << endl;
        WSACleanup();
    }
    else {
        cout << "套接字库版本正确！" << endl;
    }
    //填充服务端地址信息

}

int main()
{
    initialise();
    write_in_qq_client();
    write_in_weibo_client();
    //cout<<QQClient.QQvector[0].get_friendlist()[0]<<endl;
    main_view();
    write_in();
    system("pause");
    return 0;
}











//贪吃蛇
// 贪吃蛇的全局变量定义
int Blocks[HEIGHT][WIDTH] = { 0 }; //  二维数组，用于记录所有的游戏数据
char moveDirection;  //  小蛇移动方向
int food_i, food_j; //  食物的位置
int isFailure = 0; //  是否游戏失败

void moveSnake() //  移动小蛇及相关处理函数
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) // 对行遍历 
        for (j = 0; j < WIDTH; j++) // 对列遍历
            if (Blocks[i][j] > 0) // 大于0的为小蛇元素 
                Blocks[i][j]++; //  让其+1
    int oldTail_i, oldTail_j, oldHead_i, oldHead_j; // 定义变量，存储旧蛇尾、旧蛇头坐标  
    int max = 0; // 用于记录最大值 
    for (i = 0; i < HEIGHT; i++) //  对行列遍历
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (max < Blocks[i][j]) //  如果当前元素值比max大
            {
                max = Blocks[i][j]; // 更新max的值
                oldTail_i = i; //  记录最大值的坐标，就是旧蛇尾的位置
                oldTail_j = j; //  
            }
            if (Blocks[i][j] == 2) // 找到数值为2 
            {
                oldHead_i = i; //  数值为2恰好是旧蛇头的位置
                oldHead_j = j; //  
            }
        }
    }
    int newHead_i = oldHead_i; //  设定变量存储新蛇头的位置
    int newHead_j = oldHead_j;

    //  根据用户按键，设定新蛇头的位置
    if (moveDirection == 'w') // 向上移动
        newHead_i = oldHead_i - 1;
    else if (moveDirection == 's') // 向下移动
        newHead_i = oldHead_i + 1;
    else if (moveDirection == 'a') // 向左移动
        newHead_j = oldHead_j - 1;
    else if (moveDirection == 'd') // 向右移动
        newHead_j = oldHead_j + 1;

    //  如果蛇头超出边界，或者蛇头碰到蛇身，游戏失败
    if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0
        || Blocks[newHead_i][newHead_j]>0)
    {
        isFailure = 1; //  游戏失败
        return; // 函数返回
    }

    Blocks[newHead_i][newHead_j] = 1;  // 新蛇头位置数值为1	
    if (newHead_i == food_i && newHead_j == food_j) //  如果新蛇头正好碰到食物
    {
        food_i = rand() % (HEIGHT - 5) + 2; //  食物重新随机位置
        food_j = rand() % (WIDTH - 5) + 2; //  
        // 不对旧蛇尾处理，相当于蛇的长度+1
    }
    else // 新蛇头没有碰到食物
        Blocks[oldTail_i][oldTail_j] = 0; // 旧蛇尾变成空白，不吃食物时保持蛇的长度不变
}
void startup0()  //  初始化函数
{
    int i;
    Blocks[HEIGHT / 2][WIDTH / 2] = 1; // 画面中间画蛇头，数字为1
    for (i = 1; i <= 4; i++) //  向左依次4个蛇身，数值依次为2,3,4,5
        Blocks[HEIGHT / 2][WIDTH / 2 - i] = i + 1;
    moveDirection = 'd';	 //  初始向右移动
    food_i = rand() % (HEIGHT - 5) + 2; //  初始化随机食物位置
    food_j = rand() % (WIDTH - 5) + 2; //  
    initgraph(WIDTH * BLOCK_SIZE, HEIGHT * BLOCK_SIZE); //  新开画面
    setlinecolor(RGB(200, 200, 200)); // 设置线条颜色
    BeginBatchDraw(); // 开始批量绘制
}
void show0()  // 绘制函数
{
    cleardevice(); // 清屏
    int i, j;
    for (i = 0; i < HEIGHT; i++) //  对二维数组所有元素遍历
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (Blocks[i][j] > 0) // 元素大于0表示是蛇，这里让蛇的身体颜色色调渐变
                setfillcolor(HSVtoRGB(Blocks[i][j] * 10, 0.9, 1));
            else
                setfillcolor(RGB(150, 150, 150)); // 元素为0表示为空，颜色为灰色
            // 在对应位置处，以对应颜色绘制小方格
            fillrectangle(j * BLOCK_SIZE, i * BLOCK_SIZE,
                (j + 1) * BLOCK_SIZE, (i + 1) * BLOCK_SIZE);
        }
    }
    setfillcolor(RGB(0, 255, 0)); //  食物为绿色
    //  绘制食物小方块
    fillrectangle(food_j * BLOCK_SIZE, food_i * BLOCK_SIZE,
        (food_j + 1) * BLOCK_SIZE, (food_i + 1) * BLOCK_SIZE);
    if (isFailure) //  如果游戏失败
    {
        system("pause");
        closegraph();
        return;
        setbkmode(TRANSPARENT); // 文字字体透明    
        settextcolor(RGB(255, 0, 0));// 设定文字颜色
        settextstyle(80, 0, _T("宋体")); //  设定文字大小、样式
        outtextxy(240, 220, _T("游戏失败")); //  输出文字内容
        system("pause");
        closegraph();
        game_view();
    }
    FlushBatchDraw(); // 批量绘制
}
void updateWithoutInput0(int& flag) // 与输入无关的更新函数
{
    if (isFailure) { //  如果游戏失败，函数返回
        flag = 0;
        return;
    }
    static int waitIndex = 1; // 静态局部变量，初始化时为1
    waitIndex++; // 每一帧+1
    if (waitIndex == 10) // 如果等于10才执行，这样小蛇每隔10帧移动一次
    {
        moveSnake(); //  调用小蛇移动函数
        waitIndex = 1; // 再变成1
    }
}
void updateWithInput0()  // 和输入有关的更新函数
{
    if (_kbhit() && isFailure == 0)  //  如果有按键输入，并且不失败
    {
        char input = _getch(); //  获得按键输入
        if (input == 'a' || input == 's' || input == 'd' || input == 'w') // 如果是asdw 
        {
            moveDirection = input;  // 设定移动方向
            moveSnake(); // 调用小蛇移动函数
        }
    }
}
void tanchishe() //  主函数
{
    int flag = 1;
    startup0();  // 初始化函数，仅执行一次	
    while (flag)   // 一直循环
    {
        show0();  // 进行绘制
        updateWithoutInput0(flag); // 和输入无关的更新 
        updateWithInput0();    // 和输入有关的更新
    }
    return;
}

//十字消除
struct Block // 小方块结构体
{
    int x, y; // 小方块在画面中的x,y坐标
    int i, j;  // 小方块在二维数组中的i,j下标
    int colorId; // 对应颜色的下标
};

// 十字消除所需变量
Block blocks[RowNum][ColNum]; // 构建二维数组，存储所有数据
COLORREF  colors[ColorTypeNum + 1]; // 颜色数组，小方块可能的几种颜色
float maxTime; // 游戏允许的总时长
float remainTime; // 游戏剩余时间
float punishTime; // 玩家点错扣除的时间
int score; // 得分数，也就是消去的方块的个数
int noZeroBlockNum; // 非空白区域的砖块的个数
int level = 1; // 当前关卡序号

// 对于blocks[i][j]，绘制一个颜色为color，isfill填充的提示方框
void drawBlockHint(int i, int j, COLORREF color, int isfill)
{
    setlinecolor(color); // 设置线条颜色
    setfillcolor(color); // 设置填充颜色
    if (isfill == 1) // 画填充方块
        fillrectangle(blocks[i][j].x, blocks[i][j].y,
            blocks[i][j].x + BlockSize, blocks[i][j].y + BlockSize);
    if (isfill == 0) // 画非填充的方块线框
        rectangle(blocks[i][j].x, blocks[i][j].y,
            blocks[i][j].x + BlockSize, blocks[i][j].y + BlockSize);
}
void startup() // 初始化函数
{
    int i, j;

    int width = BlockSize * ColNum;   // 设定游戏画面的大小
    int height = BlockSize * (RowNum + 2); // 最下面用来显示一些提示信息
    initgraph(width, height);		// 新开窗口
    setbkcolor(RGB(220, 220, 220));   // 设置背景颜色
    setfillcolor(RGB(255, 0, 0));    // 设置填充色
    setlinestyle(PS_SOLID, 2);      // 设置线型、线宽
    cleardevice();    // 以背景颜色清屏
    BeginBatchDraw(); // 开始批量绘制
    srand(time(0)); // 随机种子初始化

    maxTime = 200 - level * 10; // 游戏允许的总时长，关卡越高时间越短
    remainTime = maxTime; // 游戏剩余时间
    punishTime = 0;  // 玩家点错扣除的时间

    colors[0] = RGB(220, 220, 220); // 颜色数组第一种颜色为灰白色，表示空白小方块
    for (i = 1; i < ColorTypeNum + 1; i++) // 其他几种颜色为彩色
        colors[i] = HSVtoRGB((i - 1) * 40, 0.6, 0.8);

    noZeroBlockNum = 0;
    // 对blocks二维数组进行初始化
    for (i = 0; i < RowNum; i++)
    {
        for (j = 0; j < ColNum; j++)
        {
            // 取随机数，1-ColorTypeNum为彩色，其他为空白色
            // 这样为空白色的比例更高，符合游戏的设定
            int t = rand() % (int(ColorTypeNum * 1.5));  // 取随机数
            if (t < ColorTypeNum + 1)
                blocks[i][j].colorId = t; // 小方块的颜色序号
            else // 其他情况，都为空白颜色方块
                blocks[i][j].colorId = 0; // 小方块的颜色序号

            blocks[i][j].x = j * BlockSize; // 小方块左上角的坐标
            blocks[i][j].y = i * BlockSize;
            blocks[i][j].i = i;   // 存储当前小方块在二维数组中的下标
            blocks[i][j].j = j;
            if (blocks[i][j].colorId != 0)
                noZeroBlockNum++; // 统计随机产生的方块中，非零方块的个数
        }
    }
    score = 0; // 得分数，也就是消去的方块的个数
}
void show() // 绘制函数
{
    cleardevice(); // 清屏
    setlinecolor(RGB(255, 255, 255)); // 白色线条

    int i, j;
    for (i = 0; i < RowNum; i++)
    {
        for (j = 0; j < ColNum; j++)
        {
            // 以对应的颜色、坐标画出所有的小方块
            setfillcolor(colors[blocks[i][j].colorId]);
            fillrectangle(blocks[i][j].x, blocks[i][j].y,
                blocks[i][j].x + BlockSize, blocks[i][j].y + BlockSize);
        }
    }
    setlinecolor(RGB(255, 0, 0)); // 设置进度条的颜色
    setfillcolor(RGB(255, 0, 0));
    // 根据剩余时间，绘制一个倒计时进度条，进度条按最大时间maxTime秒绘制
    fillrectangle(0, BlockSize * (RowNum + 0.2),
        remainTime * BlockSize * ColNum / maxTime, BlockSize * (RowNum + 0.8));

    // 输出提示文字信息
    TCHAR s[80]; // 定义字符数组
    setbkmode(TRANSPARENT); // 透明显示文字
    settextcolor(RGB(0, 0, 0));  // 设置字体颜色
    settextstyle(25, 0, _T("宋体")); // 设置文字大小、字体	
    _stprintf_s(s, _T("当前第%d关，已得%d分，达到%d分进入下一关"),
        level, score, int(0.9 * noZeroBlockNum));
    outtextxy(BlockSize * (ColNum / 4.5), BlockSize * (RowNum + 1.1), s); // 输出文字
    FlushBatchDraw(); // 开始批量绘制
}
void updateWithoutInput(int& flag) // 和输入无关的更新
{
    static clock_t start = clock(); // 记录第一次运行时刻
    clock_t now = clock(); // 获得当前时刻
    // 计算程序一共运行了多少秒
    double duration = double(now - start) / CLOCKS_PER_SEC;
    remainTime = maxTime - duration - punishTime; // 计算游戏剩余时间

    if (score >= int(0.9 * noZeroBlockNum)) // 得分达到要求
    {
        level++; // 如果得分达到要求，进入下一关
        start = clock();  // 重新开始计时
        startup(); // 调用初始化函数，重新开始游戏
    }
    else if (remainTime <= 0) // 得分没有达到要求且时间到了
    {
        flag = 0;
        system("pause");
        closegraph();
        return;
        setbkmode(TRANSPARENT); // 文字字体透明    
        settextcolor(RGB(255, 0, 0));// 设定文字颜色
        settextstyle(80, 0, _T("宋体")); //  设定文字大小、样式
        outtextxy(240, 220, _T("游戏失败")); //  输出文字内容
        system("pause");
        closegraph();
        game_view();
    }
}
void updateWithInput() // 和输入有关的更新
{
    if (remainTime <= 0) // 时间到了，不要操作
        return;
    int i, j;
    MOUSEMSG m;
    if (MouseHit())   // 当有鼠标消息时
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN) // 当按下鼠标左键时
        {
            // 通过鼠标位置计算出点击的小方块在二维数组中的下标
            int clicked_i = int(m.y) / BlockSize;
            int clicked_j = int(m.x) / BlockSize;

            // 如果当前点击的不是空白方块，不需要处理，返回
            if (blocks[clicked_i][clicked_j].colorId != 0)
                return;

            show(); // 先显示其他方块，再绘制提示框，后绘制的在最前面
            // 被点击到的空白方块，绘制下填充灰色方块提示框
            drawBlockHint(clicked_i, clicked_j, RGB(100, 100, 100), 1);

            // 定义数组存储上、下、左、右四个方向找到第一个不是空白的方块
            Block fourBlocks[4] = { blocks[clicked_i][clicked_j] }; //初始化为点击的方块
            int search; // 寻找下标

            // 向上找到第一个颜色不是空白的方块
            for (search = 0; clicked_i - search >= 0; search++)
            {
                if (blocks[clicked_i - search][clicked_j].colorId != 0)
                {
                    fourBlocks[0] = blocks[clicked_i - search][clicked_j];//赋给数组元素
                    break;
                }
            }
            // 向下找到第一个颜色不是空白的方块
            for (search = 0; clicked_i + search < RowNum; search++)
            {
                if (blocks[clicked_i + search][clicked_j].colorId != 0)
                {
                    fourBlocks[1] = blocks[clicked_i + search][clicked_j];//赋给数组元素
                    break;
                }
            }
            // 向左找到第一个颜色不是空白的方块
            for (search = 0; clicked_j - search >= 0; search++)
            {
                if (blocks[clicked_i][clicked_j - search].colorId != 0)
                {
                    fourBlocks[2] = blocks[clicked_i][clicked_j - search];//赋给数组元素
                    break;
                }
            }
            // 向右找到第一个颜色不是空白的方块
            for (search = 0; clicked_j + search < ColNum; search++)
            {
                if (blocks[clicked_i][clicked_j + search].colorId != 0)
                {
                    fourBlocks[3] = blocks[clicked_i][clicked_j + search];//赋给数组元素
                    break;
                }
            }

            // 统计fourBlocks的四个小方块，有没有同样颜色数目大于等于2的
            int colorStatistics[ColorTypeNum + 1] = { 0 }; // 初始化个数为0
            int isBadClick = 1; // 假设点击的方块不合适，十字区域没有有效消除的方块
            for (i = 1; i <= ColorTypeNum; i++) // i=0是空白颜色，不要统计
            {
                for (j = 0; j < 4; j++) // 遍历fourBlocks
                {
                    if (fourBlocks[j].colorId == i)
                        colorStatistics[i]++; //方块颜色序号i，对应统计个数+1
                }
                if (colorStatistics[i] >= 2) // 如果这种颜色方块个数大于等于2
                {
                    isBadClick = 0; // 能消除了，这次点击是好的操作
                    // 把对应十字区域要消除的方块颜色改成空白颜色
                    for (j = 0; j < 4; j++) // 遍历fourBlocks
                    {
                        if (fourBlocks[j].colorId == i)
                        {
                            // 要消除的方块区域绘制提示框
                            drawBlockHint(fourBlocks[j].i, fourBlocks[j].j,
                                RGB(0, 0, 0), 0);
                            // 颜色序号设为0，也就是空白的灰白色
                            blocks[fourBlocks[j].i][fourBlocks[j].j].colorId = 0;
                        }
                    }
                    score += colorStatistics[i]; // 得分加上消除的方块数
                }
            }

            // 十字区域没有能消除的方块，为错误点击，减去10秒钟时间
            if (isBadClick == 1)
                punishTime += 10;

            FlushBatchDraw(); // 批量绘制
            Sleep(300); // 绘制好提示框后暂停300毫秒

        } // if 当按下鼠标左键时
    }
}
void shizixiaochu() // 主函数
{
    int flag = 1;
    startup();  // 初始化	
    while (flag)  // 循环执行
    {
        show();  // 绘制
        updateWithoutInput(flag); // 和输入无关的更新
        updateWithInput();   // 和输入有关的更新
    }
    return;
}