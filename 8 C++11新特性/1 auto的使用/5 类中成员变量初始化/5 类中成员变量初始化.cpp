#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class A
{
public:
	A(int a):ma(a)//参数列表初始化
	{
		//ma = a;
	}
	int ma;
};

class B
{
public:
	int data{ 1 };//对data初始化
	int data2 = 1;
	A tmp{ 10 };//对tmp初始化
	string name{ "mike" };//对name初始化
};
int main()
{
	B obj;
	cout << obj.data << endl;
	cout << obj.data2 << endl;
	cout << obj.tmp.ma << endl;
	cout << obj.name << endl;

	return 0;
}