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

    //默认构造
    Manager();

    //有参构造  管理员姓名，密码
    Manager(string name, string pwd);

    //选择菜单
    virtual void operMenu();

    //添加账号  
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();

    //初始化容器，用于初始化学生容量和教师容量
    void initVector();

    //存放学生容器
    vector<Student> vStu;

    //存放教师容器
    vector<Teacher> vTea;

    //检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
    bool checkRepeat(int id, int type);

    //初始化容器，用于初始化机房信息
    void initComputerRoom();

    //机房容器
    vector<ComputerRoom> vCom;
};

