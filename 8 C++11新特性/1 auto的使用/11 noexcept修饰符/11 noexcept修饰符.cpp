#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void func1()
{
	throw 1;//抛出整型类型的异常
}
void func2() throw()
{
	//这个函数不能抛出任何类型的异常
}
void func3() noexcept
{
	//不抛出任何类型的异常
}

//注意：noexcept关键字在vs2013不支持，在qt下测试可以通过
int main()
{

	return 0;
}