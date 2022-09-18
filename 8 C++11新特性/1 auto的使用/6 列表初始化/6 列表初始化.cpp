#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Test
{
	int a;
	int b;
	char name[50];
};
void test1()
{
	//C语言中，支持自定义数据类型
	struct Test t = { 1,2,"mike" };//列表初始化

	int arr[] = { 1,2,3 };
}
void test2()
{
	//C++语言中支持普通类型列表初始化
	int a = 1;
	int b = { 1 };//列表初始化
	int c{ 3 };//列表初始化

	int arr[]{ 1,2,3 };

}
int main()
{
	return 0;
}