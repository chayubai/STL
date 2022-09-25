#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	int a = 10;

	//以值传递方式捕获，在函数体中使用，即函数内的变量是函数外的一份临时拷贝
	auto f1 = [=]() mutable
	{
		//a = 111;
		cout << "lambda::a = " << a << endl;
	};

	f1();//没有注释a = 111;

	cout << "main::a = " << a << endl;

	a = 222;
	f1();//注释a = 111;
}

void test2()
{
	int b = 10;

	//以引用传递方式捕获，在函数体中使用，即函数内的变量是函数外的同一个变量
	auto f1 = [&]()
	{
		//b = 111;
		cout << "lambda::b = " << b << endl;
	};

	f1();//没有注释a = 111;

	cout << "main::b = " << b << endl;

	b = 222;
	f1();//注释b = 111;
}
int main()
{
	test1();
	test2();

	return 0;
}
