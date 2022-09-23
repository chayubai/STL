#define _CRT_SECURE_NO_WARNINGS 1
/*
完美转发适用于这样的场景：需要将一组参数原封不动的传递给另一个函数。
“原封不动”不仅仅是参数的值不变，在 C++ 中，除了参数值之外，
还有以下两组属性：左值／右值和 const/non-const。
完美转发就是在参数传递过程中，所有这些属性和参数值都不能改变，
同时，而不产生额外的开销，就好像转发者不存在一样。在泛型函数中，这样的需求非常普遍。

即通过完美转发后，形参为左值，传入的实参也是左值，形参为右值，传入的实参也是右值
形参为const值，传入的实参也是const值，形参为非const值，传入的实参也是非const值
*/

#include <iostream>
using namespace std;

#if 0
template<class T> void func(const T&)
{
	cout << "const T&" << endl;
}

template<class T> void func(T&)
{
	cout << "T&" << endl;
}

template<class T> void forward_val(const T& tmp)//const T&版本
{
	func(tmp);
}

template<class T> void forward_val(T& tmp)//T&版本
{
	func(tmp);
}

void test1()
{
	int a = 0;
	const int& b = 1;

	//需要重载两个版本
	forward_val(a);//a为左值，调用forward_val(T& tmp)
	forward_val(b);//b为const引用，forward_val(const T& tmp)
	forward_val(111);//b为const引用，forward_val(const T& tmp)

	//由于每一个func(tmp)函数形参类型不同，都要提供一个forward_val()函数重载，只是形参类型不同，其余都相同，导致代码量很大

	//为了减少代码量，如何实现非重载完美转发？ -- 引用折叠
}
#endif

template<class T> void func(const T&)
{
	cout << "const T&" << endl;
}

template<class T> void func(T&)
{
	cout << "T&" << endl;
}

template<class T> void func(T&&)
{
	cout << "T&&" << endl;
}

template <typename T> void func(const T&& val)
{
	cout << "const T &&" << endl;
}

template<class T> void forward_val(T&& tmp)//参数为右值引用
{
	//std::forward函数模板的作用：保持参数的左值、右值属性
	func( std::forward<T>(tmp) );
}

void test2()
{
	int a = 0;
	const int& b = 1;

	forward_val(a);//a为左值，调用func(T&)
	forward_val(b);//b为const引用，func(const T&)
	forward_val(111);//func(T&&)，如果没有void func(T&&)会调用func(const T&)
	forward_val( std::move(b) );//const T &&
}
int main()
{
	//test1();
	test2();

	return 0;
}
/*
test(T&)
{
	func(TR&)
}

TR的类型定义	声明v的类型		v的实际类型
T &				TR				T &
T &				TR &			T &
T &				TR &&			T &
T &&			TR				T &&
T &&			TR &			T &
T &&			TR &&			T &&
一旦定义中出现了左值引用，引用折叠总是优先将其折叠为左值引用
*/