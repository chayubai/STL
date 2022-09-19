#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Date
{
    //constexpr���ι��캯�������캯�������Ϊ�գ���Ա���Եĳ�ʼ������ʹ�ò����б���г�ʼ��
    constexpr Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    //C++20 �����ں������н��и�ֵ

    //�ṩ���нӿ�
    constexpr int GetYear() { return year; }
    constexpr int GetMonth() { return month; }
    constexpr int GetDay() { return day; }

private:
    int year;
    int month;
    int day;
};

//vs2019��֧�֣���qt������
int main()
{
    //��������
    constexpr Date date{ 1949, 10, 1 };//����ʹ�ó��������캯�����Σ��ǳ���������

    constexpr int month = date.GetMonth();

    cout << month << endl;  // 10

    return 0;
}
