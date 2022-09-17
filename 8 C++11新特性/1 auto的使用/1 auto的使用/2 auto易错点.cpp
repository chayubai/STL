#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>

//2、vs2019不支持，函数形参是auto变量，但qt可以
//void func(auto a){}

struct Test2
{
	int a;
	//3、auto变量不能作为自定义类型的成员变量
	//auto b = 10;
};

void test()
{
	//1、auto定义变量时，必须初始化

	//auto a;//无法推导类型
	//a = 10;

	//4、不能是auto数组
	//auto b[3] = { 1,2,3 };

	//5、模板实例化类型不能是auto类型
	vector<int> a;
	//vector<auto> b;
	//vector<auto> b = { 1 };
}
int main()
{
	return 0;
}