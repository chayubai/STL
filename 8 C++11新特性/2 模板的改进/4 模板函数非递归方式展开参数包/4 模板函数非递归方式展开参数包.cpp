#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
void Print(T tmp)
{
	cout << tmp << endl;
}
//参数包展开函数
template<class...T>
void expand(T...args)
{
	//逗号运算符
	//初始化列表
	int a[] = { (Print(args),0)... };
}

int main()
{
	expand(1, 2, 3, 4);
	/*
	expand函数的逗号表达式：(print(args), 0)， 
	也是按照这个执行顺序，先执行print(args)，再得到逗号表达式的结果0。
	同时，通过初始化列表来初始化一个变长数组，
	{ (print(args), 0)... }将会展开成( (print(args1), 0), (print(args2), 0), (print(args3), 0), etc...), 
	最终会创建一个元素只都为0的数组int a[sizeof...(args)]。
	*/
	return 0;
}