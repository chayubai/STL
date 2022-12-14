#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include "GlobalFile.h"
#include "Identity.h"
#include <fstream>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

//教师菜单
void teacherMenu(Identity*& teacher)
{
    while (true)
    {
        //教师菜单
        teacher->operMenu();

        Teacher* tea = (Teacher*)teacher;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            //查看所有预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            //审核预约
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}
//学生菜单
void studentMenu(Identity*& student)
{
    while (true)
    {
        //学生菜单
        student->operMenu();

        Student* stu = (Student*)student;
        int select = 0;

        cin >> select;

        if (select == 1) //申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) //查看自身预约
        {
            stu->showMyOrder();
        }
        else if (select == 3) //查看所有预约
        {
            stu->showAllOrder();
        }
        else if (select == 4) //取消预约
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
//管理员菜单
void managerMenu(Identity*& manager)
{
    while (true)
    {
        //管理员菜单
        manager->operMenu();//多态

        //将指针进行强转，用于后续调用子类中特有接口
        Manager* man = (Manager*)manager;
        int select = 0;

        cin >> select;

        if (select == 1)  //添加账号
        {
            //cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) //查看账号
        {
            //cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) //查看机房
        {
            //cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 4) //清空预约
        {
            //cout << "清空预约" << endl;
            man->cleanFile();
        }
        else//注销登录
        {
            delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
        //这里如果选择错误可以优化一下
    }
}

//登录功能
void LoginIn(string fileName, int type)
{
    Identity* person = NULL;//用于父类指针指向子类对象，发生多态

    ifstream ifs;
    ifs.open(fileName, ios::in);

    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)	//学生登录
    {
        cout << "请输入你的学号" << endl;
        cin >> id;
    }
    else if (type == 2) //教师登录
    {
        cout << "请输入您的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;

    if (type == 1)
    {
        //学生登录验证
        int fId;//从文件中读取的id号
        string fName;//从文件中获取的姓名
        string fPwd;//从文件中获取密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            //cout << fId << fName << fPwd << endl;//测试是否读取信息

            //与用户输入的信息做对比
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "学生验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);//用于父类指针指向子类对象，发生多态

                //进入学生的子菜单
                studentMenu(person);

                return;
            }
        }
    }
    else if (type == 2)
    {
        //教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);//用于父类指针指向子类对象，发生多态

                //进入教师的子菜单
                teacherMenu(person);

                return;
            }
        }
    }
    else if (type == 3)
    {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                cout << "验证登录成功!" << endl;
                //登录成功后，按任意键进入管理员界面
                system("pause");
                system("cls");
                //创建管理员对象
                person = new Manager(name, pwd);//用于父类指针指向子类对象，发生多态

                //进入管理员的子菜单
                managerMenu(person);

                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;

    system("pause");
    system("cls");
    return;
}

int main() {

    int select = 0;

    while (true)
    {

        cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select; //接受用户选择

        switch (select)
        {
        case 1:  //学生身份
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2:  //老师身份
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3:  //管理员身份
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0:  //退出系统
            cout << "欢迎下一次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "输入有误，请重新选择！" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    system("pause");
    return 0;
}