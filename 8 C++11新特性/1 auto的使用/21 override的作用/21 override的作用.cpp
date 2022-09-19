#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//override的作用：确保在派生类中声明的虚函数发生重写时，跟基类的虚函数有相同的签名
class A1
{
public:
	//这是第一个虚函数，没有重写，不能用override修饰，否则会报错
	virtual void func(int a){}
};
class A2 :public A1
{
public:
	//virtual void func() {}//这是重定义，会隐藏基类的同名函数
	virtual void func(int b) override{}
	//在重写虚函数的地方，加上override关键字，要求必须重写的虚函数和基类一模一样，否则无法编译通过
	//形参变量名可以不一样
};

int main()
{
	return 0;
}