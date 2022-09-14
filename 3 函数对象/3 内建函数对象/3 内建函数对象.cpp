#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>

//对于一些算法的参数需要使用函数对象时，可以考虑内建函数对象，就不需要自己在实现仿函数了

//STL内建了一些函数对象。分为:算数类函数对象,关系运算类函数对象，逻辑运算类仿函数。
//使用内建函数对象，需要引入头文件 #include<functional>。

#if 0
6个算数类函数对象, 除了negate是一元运算，其他都是二元运算。
template<class T> T plus<T>//加法仿函数
template<class T> T minus<T>//减法仿函数
template<class T> T multiplies<T>//乘法仿函数
template<class T> T divides<T>//除法仿函数
template<class T> T modulus<T>//取模仿函数
template<class T> T negate<T>//取反仿函数

6个关系运算类函数对象, 每一种都是二元运算。
template<class T> bool equal_to<T>//等于
template<class T> bool not_equal_to<T>//不等于
template<class T> bool greater<T>//大于
template<class T> bool greater_equal<T>//大于等于
template<class T> bool less<T>//小于
template<class T> bool less_equal<T>//小于等于

逻辑运算类运算函数, not为一元运算，其余为二元运算。
template<class T> bool logical_and<T>//逻辑与
template<class T> bool logical_or<T>//逻辑或
template<class T> bool logical_not<T>//逻辑非
#endif
/*
//自定义的模板函数对象 - 有问题
template<class T>
class Print
{
public:
	void operator()(T num)
	{
		cout << "num = " << num << end;
	}
};
void test()
{
	//void Print<T>//自定义的打印仿函数
	Print<int> p;
	p(10);
}
*/
void test1()
{
	//template<class T>
	//T negate<T>//取反仿函数
	negate<int> n;
	cout << n(10) << endl;

	//template<class T> 
	//T plus<T>//加法仿函数
	plus<int> p;//二元运算 内建函数对象的数据类型是一致的
	cout << p(10,10) << endl;
}

void test2()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);

	//从大到小
	sort(v.begin(), v.end(), greater<int>());//greater<int>()匿名对象

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	//sort源码
#if 0
	template <class _RanIt, class _Pr>
	_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last, _Pr _Pred) { // order [_First, _Last)
		_Adl_verify_range(_First, _Last);
		const auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		_Sort_unchecked(_UFirst, _ULast, _ULast - _UFirst, _Pass_fn(_Pred));
	}

	template <class _RanIt>
	_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last) { // order [_First, _Last)
		_STD sort(_First, _Last, less<>{});//默认两个参数时，调用less<>{}
	}
#endif
}

void test3()
{
	vector<bool> v;
	v.push_back(true);//1
	v.push_back(false);//0
	v.push_back(true);
	v.push_back(false);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
	//利用逻辑非 将容器v搬运到容器v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
}
int main()
{
	//test2();
	test3();
	return 0;
}