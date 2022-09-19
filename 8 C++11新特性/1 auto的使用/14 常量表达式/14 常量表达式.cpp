#define _CRT_SECURE_NO_WARNINGS 1
//常量表达式主要是允许一些计算发生在编译时，即发生在代码编译而不是运行的时候。

//这是很大的优化：假如有些事情可以在编译时做，它将只做一次，而不是每次程序运行时都计算。
#include <iostream>
using namespace std;
int GetNum()
{
	return 3;
}
const int GetNum2()
{
	return 3;
}
constexpr int GetNum3()
{//常量表达式，发生在编译阶段
	return 3;
}

//注意：vs2013不支持，qt下支持
void test1()
{
	enum {
		//e1 = GetNum(),//报错：表达式必须含有常量值
		//e1 = GetNum2(),//报错：表达式必须含有常量值
		e1 = GetNum3(),
		e2
	};
	constexpr int tmp = GetNum3();//发生在编译阶段
	enum {
		a1 = tmp,
		a2
	};
}

int a = 3;//全局变量

void test2()
{
	//constexpr函数的限制：
	//1.函数中只能有return一个语句（有极少特例）
	//2.函数必须有返回值（不能是void函数）
	//3.在使用前必须已有定义
	//4.return返回语句表达式中不能使用非常量表达式的函数、全局数据，且必须是一个常量表达式
#if 0
	constexpr int func1()
	{
		//1、constexpr函数体只能有return语句
		//err
		constexpr int a = 1;
		return a;
	}

	//vs 2019不支持，qt下测试
	constexpr int func2()
	{
		//1、允许包含typedef，using指令，静态断言
		static_assert(1, "fail");

		return 3;
	}

	//3、函数必须有返回值（不能是void函数）
	constexpr void func3()
	{
		//err
	}

	//4、return返回语句表达式中不能使用非常量表达式的函数、全局数据，且必须是一个常量表达式
	constexpr int func4()
	{
		//err
		return a;//返回全局变量
	}
	int num()
	{
		return 10;//运行阶段
	}
	constexpr int func5()//编译阶段，矛盾
	{
		//err
		return test();//返回非常量表达式的函数
	}
}
#endif

}
int main()
{
	constexpr int func6();//声明

	constexpr int tmp = func6();//err，在使用前必须已有定义，与传统的函数使用不同
	return 0;
}

constexpr int func6()//编译阶段，矛盾
{
	//err
	return 10;//返回非常量表达式的函数
}