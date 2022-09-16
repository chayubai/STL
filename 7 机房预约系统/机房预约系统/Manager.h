#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "GlobalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

class Manager :public Identity
{
public:

    //Ĭ�Ϲ���
    Manager();

    //�вι���  ����Ա����������
    Manager(string name, string pwd);

    //ѡ��˵�
    virtual void operMenu();

    //����˺�  
    void addPerson();

    //�鿴�˺�
    void showPerson();

    //�鿴������Ϣ
    void showComputer();

    //���ԤԼ��¼
    void cleanFile();

    //��ʼ�����������ڳ�ʼ��ѧ�������ͽ�ʦ����
    void initVector();

    //���ѧ������
    vector<Student> vStu;

    //��Ž�ʦ����
    vector<Teacher> vTea;

    //����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
    bool checkRepeat(int id, int type);

    //��ʼ�����������ڳ�ʼ��������Ϣ
    void initComputerRoom();

    //��������
    vector<ComputerRoom> vCom;
};

