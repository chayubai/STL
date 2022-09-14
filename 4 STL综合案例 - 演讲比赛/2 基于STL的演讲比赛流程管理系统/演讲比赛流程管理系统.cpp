#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include "speechManager.h"
#include <ctime>
int main() {
#if 0
    SpeechManager sm;
    sm.show_Menu();
#endif
#if 0
    SpeechManager sm;

    int choice = 0; //用来存储用户的选项

    while (true)
    {
        sm.show_Menu();

        cout << "请输入您的选择： " << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
        case 1:  //开始比赛
            break;
        case 2:  //查看往届比赛记录
            break;
        case 3:  //清空记录
            break;
        case 0:  //退出系统
            sm.exitSystem();
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }
#endif
#if 0
    SpeechManager sm;
    
    for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    {
        cout << "选手编号：" << it->first
            << " 姓名： " << it->second.m_Name
            << " 成绩： " << it->second.m_Score[0] << endl;//显示第一轮的信息
    }
#endif
#if 0
    SpeechManager sm;

    int choice = 0; //用来存储用户的选项

    while (true)
    {
        sm.show_Menu();

        cout << "请输入您的选择： " << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
        case 1:  //开始比赛
            sm.startSpeech();
            break;
        case 2:  //查看往届比赛记录
            break;
        case 3:  //清空记录
            break;
        case 0:  //退出系统
            sm.exitSystem();
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }
#endif
#if 0
    //随机数种子
    srand((unsigned int)time(NULL));

    SpeechManager sm;

    int choice = 0; //用来存储用户的选项

    while (true)
    {
        sm.show_Menu();

        cout << "请输入您的选择： " << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
        case 1:  //开始比赛
            sm.startSpeech();
            break;
        case 2:  //查看往届比赛记录
            sm.showRecord();
            break;
        case 3:  //清空记录
            break;
        case 0:  //退出系统
            sm.exitSystem();
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }
#endif
    //随机数种子
    srand((unsigned int)time(NULL));

    SpeechManager sm;//如果放外面，对象只会创建一次，如果程序不关闭，就只能比赛一次
    //解决方法1：把管理类对象的创建，放在mian.cpp的while循环里
    //解决方法2：在speakerManager.cpp的startSpeech中，重置比赛，重新重建选手，重新获取记录

    int choice = 0; //用来存储用户的选项

    while (true)
    {
        //SpeechManager sm;
        sm.show_Menu();

        cout << "请输入您的选择： " << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
        case 1:  //开始比赛
            sm.startSpeech();
            break;
        case 2:  //查看往届比赛记录
            sm.showRecord();
            break;
        case 3:  //清空记录
            sm.clearRecord();
            break;
        case 0:  //退出系统
            sm.exitSystem();
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }

    system("pause");

    return 0;
}