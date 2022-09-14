#define _CRT_SECURE_NO_WARNINGS 1
//算法主要是由头文件<algorithm> <functional> <numeric>组成。
//<algorithm>是所有STL头文件中最大的一个, 其中常用的功能涉及到比较，交换，查找，遍历，复制，修改，反转，排序，合并等...
//<numeric>体积很小，只包括在几个序列容器上进行的简单运算的模板函数.
//<functional> 定义了一些模板类, 用以声明函数对象。

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#if 0
/*
	遍历算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  回调函数或者函数对象
	@return 函数对象
*/
for_each(iterator beg, iterator end, _callback);
#endif
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << endl;
		m_count++;
	}
	int m_count = 0;
};
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for_each用于遍历
	for_each(v.begin(), v.end(), MyPrint());

	//for_each有返回值，将对象返回
	MyPrint print = for_each(v.begin(), v.end(), MyPrint());

	cout << "print.m_count = " << print.m_count << endl;
}

#include <functional>
class MyPrint2:public binary_function<int,int,void>
{
public:
	void operator()(int val,int start) const
	{
		cout << val + start<< endl;
	}
};
void test2()
{
	//for_each可以绑定参数进行输出
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(MyPrint2(),1000));
}

#if 0
/*
	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _callback 回调函数或者函数对象
	@return 返回目标容器迭代器
*/
transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
#endif

class MyTransform
{
public:
	int operator()(int val)
	{
		return val + 1000;
	}
};
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> v2;
	//初始vector是没有容量的。往没有容量的容器中放数据是会报错的
	//v2.reserve(v.size());//会报错：预留了空间，相当于荒地不能直接使用，但可以搭配push_back使用
	v2.resize(v.size());//重置v2容量的大小

	transform(v.begin(), v.end(), v2.begin(), MyTransform());
	//将[begin,end)区间的值依次遍历后，通过回调函数或这仿函数的返回值，将容器v1中的数据放入v2中

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	//transform源码1：
#if 0
	template <class _InIt, class _OutIt, class _Fn>
	_CONSTEXPR20 _OutIt transform(const _InIt _First, const _InIt _Last, _OutIt _Dest, _Fn _Func) {
		// transform [_First, _Last) with _Func
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		auto _UDest = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		for (; _UFirst != _ULast; ++_UFirst, (void) ++_UDest) {
			*_UDest = _Func(*_UFirst);
		}

		_Seek_wrapped(_Dest, _UDest);
		return _Dest;
	}
#endif
}

//将容器1和容器2中的元素相加放入到第三个容器中
struct transformTest02 
{
	int operator()(int v1, int v2) 
	{
		return v1 + v2;
	}
};
void test4()
{
	vector<int> vSource1;
	vector<int> vSource2;
	for (int i = 0; i < 10; i++) 
	{
		vSource1.push_back(i + 1);
		vSource2.push_back(i + 1);
	}
	for_each(vSource1.begin(), vSource1.end(), [](int val) {cout << val << " "; });
	cout << endl;
	for_each(vSource2.begin(), vSource2.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//目标容器
	vector<int> vTarget;
	//给vTarget开辟空间
	vTarget.resize(vSource1.size());

	transform(vSource1.begin(), vSource1.end(), vSource2.begin(), vTarget.begin(), transformTest02());
	//打印
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
	//transform源码2：
#if 0
	template <class _InIt1, class _InIt2, class _OutIt, class _Fn>
	_CONSTEXPR20 _OutIt transform(
		const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, _OutIt _Dest, _Fn _Func) {
		// transform [_First1, _Last1) and [_First2, ...) with _Func
		_Adl_verify_range(_First1, _Last1);
		auto _UFirst1 = _Get_unwrapped(_First1);
		const auto _ULast1 = _Get_unwrapped(_Last1);
		const auto _Count = _Idl_distance<_InIt1>(_UFirst1, _ULast1);
		auto _UFirst2 = _Get_unwrapped_n(_First2, _Count);
		auto _UDest = _Get_unwrapped_n(_Dest, _Count);
		for (; _UFirst1 != _ULast1; ++_UFirst1, (void) ++_UFirst2, ++_UDest) {
			*_UDest = _Func(*_UFirst1, *_UFirst2);
		}

		_Seek_wrapped(_Dest, _UDest);
		return _Dest;
	}

#endif
}
int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}

//技巧：当使用STL中的函数，可以通过转到定义查看函数源码的参数和返回类型