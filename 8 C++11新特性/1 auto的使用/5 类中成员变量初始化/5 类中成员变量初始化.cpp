#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class A
{
public:
	A(int a):ma(a)//�����б��ʼ��
	{
		//ma = a;
	}
	int ma;
};

class B
{
public:
	int data{ 1 };//��data��ʼ��
	int data2 = 1;
	A tmp{ 10 };//��tmp��ʼ��
	string name{ "mike" };//��name��ʼ��
};
int main()
{
	B obj;
	cout << obj.data << endl;
	cout << obj.data2 << endl;
	cout << obj.tmp.ma << endl;
	cout << obj.name << endl;

	return 0;
}