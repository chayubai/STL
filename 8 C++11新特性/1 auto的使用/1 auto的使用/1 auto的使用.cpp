#define _CRT_SECURE_NO_WARNINGS 1
/*
1、Qt Creator - New Project - 非Qt项目 - 新建一个纯C++语言的项目，
在项目文件.pro中配置：CONFIG += c++11//c可以大写
2、Linux终端，g++ xxx.cpp  -std=c++11
注意：对于一些c++11新特性，在vs中可能不能兼容
*/

#include <iostream>
using namespace std;

void test1()
{
	//在C中，auto修饰局部变量，局部变量也叫auto变量，自动变量，即局部变量栈区自动开辟空间，自动维护
	{
		int a;//auto int a;C语言中，默认局部变量前面有一个auto关键字
	}
}

double func()
{
	return 1.1;
}
class Test
{
public:
	int a;
};
void test2()
{
	//C++11, auto根据用户初始化内容自动推导类型

	int a = 1;
	auto b = 1;//b的类型就是int
	auto c = func();//c的类型就是double

	Test str;
	auto d = str;//d的类型就是Test
}

#include <vector>
void test3(vector<int> &tmp)
{
	for (auto i = tmp.begin(); i != tmp.end(); i++)
	{
		//....
	}
}

int main()
{
	return 0;
}