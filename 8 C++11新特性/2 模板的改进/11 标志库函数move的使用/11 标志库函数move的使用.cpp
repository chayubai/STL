#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 10;//a为左值

	//int && b = a;//err 左值不能绑定到右值引用

	int&& c = std::move(a);//std::move(a)将一个左值转换为右值
	
	//注意：由于使用了命名空间std，可直接使用move

	cout << "c = " << c << endl;
	return 0;
}