#define _CRT_SECURE_NO_WARNINGS 1
//谓词是指 普通函数 或 重载的operator() 返回值是bool类型的函数对象(仿函数)。
//如果operator接受一个参数，那么叫做一元谓词, 如果接受两个参数，那么叫做二元谓词，谓词可作为一个判断式。
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//一元谓词
class GreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};
void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//查找第一个大于20的数字

	//第三个参数 函数对象 匿名对象，也可以使用对象名
	//GreaterThan20 greaterThan20;
	//vector<int>::iterator ret = find_if(v.begin(), v.end(), greaterThan20);//GreaterThan20()匿名对象，pred仿函数，或回调函数，该函数返回迭代器

	vector<int>::iterator ret = find_if(v.begin(), v.end(), GreaterThan20());//GreaterThan20()匿名对象，pred仿函数，或回调函数，该函数返回迭代器
	if (ret != v.end())
		cout << "找到了大于20的数字为：" << *ret << endl;
	else
		cout << "未找到" << endl;
	//注意：找所有大于20的数，可以加一个循环
	//find_if源码：
#if 0
	// FUNCTION TEMPLATE find_if
	template <class _InIt, class _Pr>
	_NODISCARD _CONSTEXPR20 _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred) { // find first satisfying _Pred
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		for (; _UFirst != _ULast; ++_UFirst) {
			if (_Pred(*_UFirst)) {//GreaterThan20()(*_UFirst) *_UFirst == val
				break;
			}
		}

		_Seek_wrapped(_First, _UFirst);
		return _First;//返回迭代器，如果满足条件，返回该位置的迭代器，如果没有满足的条件，返回end()迭代器
	}
#endif
}

//二元谓词
void myPrintInt(int val)
{
	cout << val << " ";
}
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	sort(v.begin(), v.end());//从小到大

	//遍历
	for_each(v.begin(), v.end(), myPrintInt);
	cout << endl;

	//使用函数对象，改变算法策略
	sort(v.begin(), v.end(),MyCompare());//从大到小

	//注意：仿函数需要加(),回调函数只需要函数名
	
	//lambda表达式
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	//[](int val) {cout << val << " "; }匿名函数，[]代表lambda表达式标志
	cout << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}