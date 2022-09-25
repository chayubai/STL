#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//lambda 表达式是一个匿名函数
//C++11中的lambda表达式用于定义并创建匿名的函数对象
/*
	lambda表达式的基本构成：
	[]() mutable exception -> int
	{
		//函数体
	}

	[] 标识一个lambda的开始，这部分必须存在，不能省略。用于捕获外面的变量
	() 如果匿名函数没有参数，可以省略


	->int 指定返回值类型，可以省略，因为可以通过函数返回值自动推导返回值类型
	mutable关键字，表示允许mutable修饰的const值可以修改

*/

int tmp = 10;
class Test
{
public:
	void func()
	{
		int a = 100;//局部变量

		//[]为空，没有捕获任何变量
		//auto f1 = []() { cout << i << endl; };//err
		auto f1 = [=]() { cout << i << endl; };
		auto f2 = [&]() { cout << i << endl; };

		//捕获类成员变量，全局变量
		auto f3 = [this]() { 
			cout << i << endl;
			cout << tmp << endl;
			//cout << a << endl;//不可以捕获局部变量
		};
	}
	int i = 0;
};
int main()
{
	int a = 0;
	int b = 1;
	int c = 2;

	auto f1 = []() {};//暂时理解f1为函数指针

	//a，b以值传递方式，在函数体中使用
	auto f2 = [a, b]() { cout << a << " " << b << endl; };
	f2();

	//[]里面的是捕获外面的变量，x，y才是参数
	auto f3 = [a, b](int x, int y) {
		cout << a << " " << b << endl;
		cout << x << " " << y << endl;
	};
	f3(10, 20);

	//外面的变量全部以值传递的方式，在函数体中使用
	auto f4 = [=] { cout << a << " " << b << endl; };
	f4();

	//外面的变量全部以引用传递的方式，在函数体中使用
	auto f5 = [&] { cout << a << " " << b << endl; };

	//a以值传递的方式，其他以引用传递的方式，在函数体中使用
	//注意：[&, a]顺序不能反了
	auto f6 = [&, a] { cout << a << " " << b << endl; };

	//a以引用传递的方式，其他以值传递的方式，在函数体中使用
	//注意：[=, &a]顺序不能反了
	auto f7 = [=, &a] { cout << a << " " << b << endl; };

	//默认情况下，lambda函数，以const修饰函数体，即函数体中使用捕获到的变量时只能读不能改
	//值传递无法修改，想修改加mutable
	//auto f8 = [=]() { a++; };
	auto f8 = [=]() mutable { a++; };

	//注意：[]捕获的变量是当前匿名函数作用域下的变量或者全局变量
	//auto f9 = [=]() mutable { cout << i << " " << tmp << endl;};//err


	return 0;
}