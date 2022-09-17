#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		cout << tmp << " ";
	}
	cout << endl;

	//以上传统方法，等价于下面的使用方法
	for (int tmp : a)//将每次取a[i]的值，传给tmp
	{
		cout << tmp << " ";
	}
	cout << endl;
}

void test2()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++)
	{
		int &tmp = a[i];
		cout << tmp << " ";
	}
	cout << endl;
	
	//以上传统方法，等价于下面的使用方法
	for (int &tmp : a)//将每次取a[i]的值，传给引用
	{
		cout << tmp << " ";
	}
	cout << endl;
}

void test3()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		int* tmp = &a[i];
		cout << tmp << " ";
	}
	cout << endl;
	//for (int* tmp : a)//将每次取a[i]的值，不能传给指针tmp
	//{
	//	cout << tmp << " ";
	//}
	cout << endl;
}

//形参中的数组不是数组，而是指针变量，无法确定元素个数
//基于范围的for，这个范围是要确定后，否则无法使用
void func1(int* a)
{
	//for (auto tmp : a)//a是一个指针，无法确定范围
	//{
	//	cout << tmp << endl;
	//}
}
void func2(int a[])
{
	//for (auto tmp : a)//int a[]是一个指针，无法确定范围
	//{
	//	cout << tmp << endl;
	//}
}
void func3(int a[])
{
	/*for (auto& tmp : a)//int a[]是一个指针，无法确定范围
	{
		cout << tmp << endl;
	}*/
}
void test4()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);
	func1(a);
	func2(a);
	func3(a);
}
int main()
{
	test1();
	return 0;
}