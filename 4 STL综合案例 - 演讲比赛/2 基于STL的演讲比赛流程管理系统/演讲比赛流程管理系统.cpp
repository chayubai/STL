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

    int choice = 0; //�����洢�û���ѡ��

    while (true)
    {
        sm.show_Menu();

        cout << "����������ѡ�� " << endl;
        cin >> choice; // �����û���ѡ��

        switch (choice)
        {
        case 1:  //��ʼ����
            break;
        case 2:  //�鿴���������¼
            break;
        case 3:  //��ռ�¼
            break;
        case 0:  //�˳�ϵͳ
            sm.exitSystem();
            break;
        default:
            system("cls"); //����
            break;
        }
    }
#endif
#if 0
    SpeechManager sm;
    
    for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    {
        cout << "ѡ�ֱ�ţ�" << it->first
            << " ������ " << it->second.m_Name
            << " �ɼ��� " << it->second.m_Score[0] << endl;//��ʾ��һ�ֵ���Ϣ
    }
#endif
#if 0
    SpeechManager sm;

    int choice = 0; //�����洢�û���ѡ��

    while (true)
    {
        sm.show_Menu();

        cout << "����������ѡ�� " << endl;
        cin >> choice; // �����û���ѡ��

        switch (choice)
        {
        case 1:  //��ʼ����
            sm.startSpeech();
            break;
        case 2:  //�鿴���������¼
            break;
        case 3:  //��ռ�¼
            break;
        case 0:  //�˳�ϵͳ
            sm.exitSystem();
            break;
        default:
            system("cls"); //����
            break;
        }
    }
#endif
#if 0
    //���������
    srand((unsigned int)time(NULL));

    SpeechManager sm;

    int choice = 0; //�����洢�û���ѡ��

    while (true)
    {
        sm.show_Menu();

        cout << "����������ѡ�� " << endl;
        cin >> choice; // �����û���ѡ��

        switch (choice)
        {
        case 1:  //��ʼ����
            sm.startSpeech();
            break;
        case 2:  //�鿴���������¼
            sm.showRecord();
            break;
        case 3:  //��ռ�¼
            break;
        case 0:  //�˳�ϵͳ
            sm.exitSystem();
            break;
        default:
            system("cls"); //����
            break;
        }
    }
#endif
    //���������
    srand((unsigned int)time(NULL));

    SpeechManager sm;//��������棬����ֻ�ᴴ��һ�Σ�������򲻹رգ���ֻ�ܱ���һ��
    //�������1���ѹ��������Ĵ���������mian.cpp��whileѭ����
    //�������2����speakerManager.cpp��startSpeech�У����ñ����������ؽ�ѡ�֣����»�ȡ��¼

    int choice = 0; //�����洢�û���ѡ��

    while (true)
    {
        //SpeechManager sm;
        sm.show_Menu();

        cout << "����������ѡ�� " << endl;
        cin >> choice; // �����û���ѡ��

        switch (choice)
        {
        case 1:  //��ʼ����
            sm.startSpeech();
            break;
        case 2:  //�鿴���������¼
            sm.showRecord();
            break;
        case 3:  //��ռ�¼
            sm.clearRecord();
            break;
        case 0:  //�˳�ϵͳ
            sm.exitSystem();
            break;
        default:
            system("cls"); //����
            break;
        }
    }

    system("pause");

    return 0;
}