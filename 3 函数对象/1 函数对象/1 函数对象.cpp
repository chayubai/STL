#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//重载函数调用操作符的类，其对象常称为函数对象（function object），即它们是行为类似函数的对象，
//也叫仿函数(functor),其实就是重载“()”操作符，使得类对象可以像函数那样调用。

//注意：函数对象(仿函数)是一个类，不是一个函数。
//把函数对象理解为，一个类，但是类内重载了()，在通过该类创建对象调用()很像一个函数调用
class MyPrint
{
public:
	MyPrint()
	{
		m_count = 0;
	}
	void operator()(int num)
	{
		cout << num << endl;
		m_count++;
	}
public:
	int m_count;//调用次数的状态
};
void myPrint1(int num)
{
	cout << num << endl;
}
void test1()
{
	MyPrint myPrint;
	myPrint(100);//本质上是一个类的对象，因此也称为函数对象，也叫仿函数
	//函数对象可以像普通函数那样接收参数

	myPrint1(100);//函数调用

	MyPrint()(100);//匿名对象调用
}

int num = 0;//全局变量，真正开发中，尽量避免去使用全局变量
//由于全局变量，在多线程中属于公共资源，很多人都会使用他，导致不确定
void myPrint2(int num)
{
	num++;

	cout << num << endl;
}
void test2()
{
	//函数对象 超出了普通函数的概念，可以拥有自己的状态
	MyPrint myPrint;
	myPrint(100);
	myPrint(100);
	myPrint(100);
	cout << "同一个对象，调用次数：" << myPrint.m_count << endl;//保存函数调用的状态
	
	//对于普通函数，如果做统计操作，需要定义全局变量或静态变量
	myPrint2(1); 
	myPrint2(2);
	cout << "函数，调用次数：" << num << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	MyPrint mp;
	MyPrint p = for_each(v.begin(), v.end(), mp);//第三个参数使用仿函数或回调函数，for_each返回类型会第三个参数的类型
	//第三个参数：使用仿函数时，传入(匿名)对象即可。使用回调函数，传入函数调用。
	cout << "myPrint，调用次数：" << mp.m_count << endl;//0，for_each底层源码没有使用引用类型，而是值拷贝，函数内的改变不会影响函数外的变量
	cout << "myPrint，调用次数：" << p.m_count << endl;//4

#if 0
	// FUNCTION TEMPLATE for_each
	template <class _InIt, class _Fn>
	_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { //_Fn _Func不是引用类型，调用拷贝构造，将对象mp传入返回类型为该对象的类型
		// perform function for each element [_First, _Last)
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		for (; _UFirst != _ULast; ++_UFirst) {
			_Func(*_UFirst);
		}

		return _Func;
	}
#endif
}

void doPrint(MyPrint myPrint, int num)
{
	myPrint(num);
}
void test3()
{
	//匿名函数对象可以作为函数参数
	doPrint(MyPrint(), 1000);
}
//总结：
//1、函数对象通常不定义构造函数和析构函数，所以在构造和析构时不会发生任何问题，避免了函数调用的运行时问题。
//2、函数对象超出普通函数的概念，函数对象可以有自己的状态
//3、函数对象可 内联编译 inline，性能好(跑源码)。用函数指针几乎不可能，进栈出栈开销
//4、模版函数对象使函数对象具有通用性，这也是它的优势之一

int main()
{
	test3();
	return 0;
}