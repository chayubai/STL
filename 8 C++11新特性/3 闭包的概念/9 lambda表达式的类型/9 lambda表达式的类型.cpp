#define _CRT_SECURE_NO_WARNINGS 1
/*
lambda表达式的类型在C++11中被称为“闭包类型”，每一个lambda表达式则会产生一个临时对象(右值)。
因此，严格地将，lambda函数并非函数指针。

不过C++11标准却允许lambda表达式向函数指针的转换，
但提前是lambda函数没有捕获任何变量，且函数指针所示的函数原型，必须跟lambda函数函数有着相同的调用方式。

*/

#include <iostream>
using namespace std;

#include <functional>

int main()
{
	function<void(int)> f1 = [](int a) {cout << a << endl; };
	f1(11);

	function<int(int)> f2 = [](int a) {return a+1; };
	cout << f2(9) << endl;

	function<int(int)> f3 = bind(
		[](int a) {return a + 1; }, std::placeholders::_1);
	cout << f3(9) << endl;

	auto f4 = [](int x, int y)->int {return x + y; };
	cout << f4(1, 2) << endl;

	decltype(f4) tmp = f4;
	cout << tmp(2, 2) << endl;

	//定义一个函数指针
	//注意函数指针和类型int (int, int)和lambda表达式类型(int x, int y)->int 一致，
	typedef int (*PFUNC) (int, int);
	PFUNC p1 = f4;//lambda表达式转换为函数指针，不允许[]捕获外部变量(可以捕获，但是不能在函数体中使用)
	cout << p1(10, 20) << endl;
	//int a = 10;
	//auto f4 = [=](int x, int y)->int {cout << a << endl; return x + y; };
	//PFUNC p1 = f4;//err

	//decltype(f4) tmp2 = p1;//函数指针转换为lambda表达式，是不可以的，err
	return 0;
}