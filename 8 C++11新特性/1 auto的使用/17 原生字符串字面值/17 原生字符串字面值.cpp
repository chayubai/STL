#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main()
{
	//原生字符串字面值：输入什么打印什么
	cout << R"(hell0,\n world)" << endl;

	string str = R"(hello \4 \r
	abc，mike
	hello \n)";

	cout << str << endl;

	return 0;
}