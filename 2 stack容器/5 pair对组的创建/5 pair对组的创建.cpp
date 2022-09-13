#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//对组：将两个值合并为一个值。成对出现的数据，利用对组可以返回两个数据
//通过对组创建对象，对组类中包含两个成员属性first和second
void test1()
{
	//创建对组
	pair<string, int> p("Tom", 10);//使用pair不需要头文件

	cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 18);

	cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;

	//pair=赋值
	pair<string, int> p3 = p2;
	cout << p3.first << endl;
	cout << p3.second << endl;
}

int main()
{
	test1();
	return 0;
}