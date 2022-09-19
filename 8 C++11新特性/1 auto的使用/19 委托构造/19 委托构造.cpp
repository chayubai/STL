#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Test
{
public:
	//委托构造，一定要通过初始化列表方式
	/*
	Test()
	{

	}*/
	Test():Test(1,'a')//默认构造委托有参构造初始化成员属性
	{

	}
	/*
	Test(int x) :a(x)
	{

	}
	*/
	Test(int x) :Test(x,'b')//有参构造委托有参构造初始化成员属性
	{

	}
	/*
	Test(char x) :b(x)
	{

	}
	*/
	Test(char x) :Test(10,x)//有参构造委托有参构造初始化成员属性
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