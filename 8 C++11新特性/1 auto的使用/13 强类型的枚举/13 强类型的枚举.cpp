#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	enum Status
	{
		Ok,
		Error
	};
	/*enum Status2
	{
		Ok,
		Error
	};*/

	//“test1::Ok”: 重定义；以前的定义是“枚举数”
	//“test1::Error”: 重定义；以前的定义是“枚举数”

	Status flag = Ok;//Ok是一个全局变量，只能定义一次

	cout << sizeof(Ok) << endl;//4
	//枚举值默认是0开始，就是说被赋予了整数值，肯定是int大小
}

void test2()
{
	//1、强类型枚举，enum后面加上class或struct修饰
	enum class Status
	{
		Ok,
		Error
	};
	enum struct Status2
	{
		Ok,
		Error
	};

	//注意：强类型枚举虽然有class/struct修饰，但里面没有私有，公有之分

	//Status flag = Ok;//报错：未定义标识符 "Ok"

	//2、强类型枚举定义变量，必须加作用域
	Status flag = Status::Ok;

	//默认情况下，强类型枚举定义的成员变量类型为int类型
	cout << sizeof(Status2::Ok) << endl;

	//3、强类型枚举，可以指定成员变量的类型
	enum struct Status3 : char
	{
		Ok,
		Error
	};

	cout << sizeof(Status3::Ok) << endl;
	enum struct Status4 : long long
	{
		Ok,
		Error
	};

	cout << sizeof(Status4::Ok) << endl;
}
int main()
{
	test1();
	test2();
	return 0;
}