#define _CRT_SECURE_NO_WARNINGS 1
/*
闭包有很多种定义，一种说法是，闭包是带有上下文的函数。说白了，就是有状态的函数。更直接一些，不就是个类吗？换了个名字而已。

一个函数，带上了一个状态，就变成了闭包了。那什么叫 “带上状态” 呢？ 意思是这个闭包有属于自己的变量，这些个变量的值是创建闭包的时候设置的，并在调用闭包的时候，可以访问这些变量。

函数是代码，状态是一组变量，将代码和一组变量捆绑 (bind) ，就形成了闭包。

闭包的状态捆绑，必须发生在运行时。

*/
#include <iostream>
using namespace std;

struct A
{
	void operator()()
	{
		m_count++;
	}
	int m_count = 0;//函数调用的次数状态
};
int main()
{
	A a1;
	a1();
	a1();
	cout << a1.m_count << endl;
	return 0;
}