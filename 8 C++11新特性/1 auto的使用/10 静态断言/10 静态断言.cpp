#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <cassert>

void test1()
{
	bool flag = false;

	//运行时，检查条件，如果条件为真，往下执行。如果条件为假，中断程序，提示错误

	//assert(flag == true);
	assert(flag == false);

	cout << "hello c++" << endl;
}

void test2()
{
	//static_assert(条件常量表达式, "提示的字符串");

	//编译时，检查条件，如果条件为真，往下执行。如果条件为假，中断程序，提示错误

	//static_assert(sizeof(void*) == 8, "64位系统不支持");//直接编译报错
	static_assert(sizeof(void*) == 4, "64位系统不支持");

	cout << "hello c++" << endl;
}
int main()
{

	return 0;
}