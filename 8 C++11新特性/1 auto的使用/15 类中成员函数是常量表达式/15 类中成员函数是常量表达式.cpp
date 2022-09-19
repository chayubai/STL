#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Date
{
    //constexpr修饰构造函数，构造函数体必须为空，成员属性的初始化可以使用参数列表进行初始化
    constexpr Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    //C++20 可以在函数体中进行赋值

    //提供公有接口
    constexpr int GetYear() { return year; }
    constexpr int GetMonth() { return month; }
    constexpr int GetDay() { return day; }

private:
    int year;
    int month;
    int day;
};

//vs2019不支持，在qt下运行
int main()
{
    //创建对象
    constexpr Date date{ 1949, 10, 1 };//必须使用常量给构造函数传参，非常量不可以

    constexpr int month = date.GetMonth();

    cout << month << endl;  // 10

    return 0;
}
