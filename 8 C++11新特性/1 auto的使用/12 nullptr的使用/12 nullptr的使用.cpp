#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void func(int a)
{
	//....
	cout << __LINE__ << endl;//打印第几行
}
void func(int* p)//重载
{
	//....
	cout << __LINE__ << endl;//打印第几行
}

int main()
{
	int* p = NULL;//#define NULL 0
	int* p2 = 0;

	func(0);//8
	func(NULL);//8
	//防止产生二义性，应使用nullptr对指针赋初始值

	func(nullptr);//13

	//nullptr只能给指针赋值
	p = NULL;
	p2 = nullptr;
	if (p == p2)
		cout << "equal" << endl;

	//不能给一个普通整型变量赋初值nullptr
	//int tmp = nullptr;//报错：无法从"nullptr"转换为"int"

	return 0;
}