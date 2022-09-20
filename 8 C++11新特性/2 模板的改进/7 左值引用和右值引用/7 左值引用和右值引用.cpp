#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//在赋值表达式中，出现在等号左边的就是“左值”，而在等号右边的，则称为“右值”。
//C++中还有一个被广泛认同的说法，那就是可以取地址的、有名字的就是左值，反之，不能取地址的、没有名字的就是右值。
//相对于左值，右值表示字面常量、表达式、非引用返回值的函数等。

int& func()
{
	static int tmp;
	return tmp;
}
void test1()
{
	//左值引用是对一个左值进行引用的类型，右值引用则是对一个右值进行引用的类型。

	//左值引用和右值引用都是属于引用类型。无论是声明一个左值引用还是右值引用，都必须立即进行初始化。
	//而其原因可以理解为是引用类型本身自己并不拥有所绑定对象的内存，只是该对象的一个别名。

	//左值引用是具名变量值的别名，而右值引用则是不具名（匿名）变量的别名。
	
	//int& a = 2;     // 左值引用绑定到右值，编译失败, err
	int b = 2;		  // 非常量左值
	int& c = b;
	const int& d = b; // 常量左值引用绑定到非常量左值，编译通过, ok
	
	const int e = 2;  // 常量左值
	const int& f = c; // 常量左值引用绑定到常量左值，编译通过, ok
	const int& g = 2; // 常量左值引用绑定到右值，编程通过, ok
	int& h = func();  

	const int tmp = 10;
	const int& j = tmp;

	//const int & 万能引用
	//“const 类型 &”为 “万能”的引用类型，它可以接受非常量左值、常量左值、右值对其进行初始化；
}

int func2()
{
	return 10;
}
void test2()
{
	//右值引用
	int&& a = 10;
	
	int&& b = func2();

	int i = 10;
	int j = 20;
	int&& c = i + j;

	//注意：不能把一个左值赋值给一个右值引用
	int k = 10;
	//int&& d = k;//err
}

void f(int& tmp)
{
	cout << "左值引用 = " << tmp << endl;
}
void f(int&& tmp)
{
	cout << "右值引用 = " << tmp << endl;
}
void test3()
{
	int a = 10;
	f(a);
	f(110);
}
int main()
{
	test3();
	return 0;
}