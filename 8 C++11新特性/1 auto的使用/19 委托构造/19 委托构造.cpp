#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Test
{
public:
	//ί�й��죬һ��Ҫͨ����ʼ���б�ʽ
	/*
	Test()
	{

	}*/
	Test():Test(1,'a')//Ĭ�Ϲ���ί���вι����ʼ����Ա����
	{

	}
	/*
	Test(int x) :a(x)
	{

	}
	*/
	Test(int x) :Test(x,'b')//�вι���ί���вι����ʼ����Ա����
	{

	}
	/*
	Test(char x) :b(x)
	{

	}
	*/
	Test(char x) :Test(10,x)//�вι���ί���вι����ʼ����Ա����
	{

	}
	int a;
	char b;
private:
	Test(int x, char y) :a(x), b(y)
	{

	}
};
int main()
{
	Test t1;//Test():Test(1,'a')
	cout << t1.a << endl;
	cout << t1.b << endl;

	Test t2(10);//Test(int x) :Test(x,'b')
	cout << t2.a << endl;
	cout << t2.b << endl;

	Test t3('a');//Test(char x) :Test(10,x)
	cout << t3.a << endl;
	cout << t3.b << endl;
	return 0;
}