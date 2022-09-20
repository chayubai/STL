#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//可变参数的模板参数 0-n任意个参数
template<class... T>//T叫模板参数包
void func(T... args)//args叫函数参数包
{
	//获取可变参数的个数
	cout << "num = " << sizeof...(args) << endl;
}

//如：tuple也是一个可变参数的模板
void test1()
{
	func(10);//自动推导
	func<int>(10);
	func<int, int>(10, 20);
	func<char, const char*, int>('a', "abc", 25);
}

int main()
{
	test1();
	return 0;
}