#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#if 0
/*
	find算法 查找元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return 返回查找元素的位置
*/
find(iterator beg, iterator end, value)
#endif
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
		cout << "找到了元素" << *pos << endl;
	else
		cout << "未找到" << endl;
}

#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	/*bool operator==(Person& p)//报错：二元“ == ”: 没有找到接受“const _Ty”类型的右操作数的运算符(或没有可接受的转换)
	{
		return m_name == p.m_name && m_age == p.m_age;
	}*/
	bool operator==(const Person& p)//底层源码参数对比是 const _Ty & _Val
	{
		return m_name == p.m_name && m_age == p.m_age;
	}
	string m_name;
	int m_age;
};
void test2()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person p5("bbb", 10);
	vector<Person>::iterator pos = find(v.begin(), v.end(), p5);//find底层源码也是==比较，由于自定义数据类型不知道怎么比较，需要重载==号
	if (pos != v.end())
		cout << "找到了元素 姓名：" << pos->m_name << " 年龄：" << pos->m_age << endl;
	else
		cout << "未找到" << endl;
#if 0
	//find源码：
	template <class _InIt, class _Ty>
	_NODISCARD _CONSTEXPR20 _InIt _Find_unchecked(const _InIt _First, const _InIt _Last, const _Ty & _Val) {
		// find first matching _Val; choose optimization
		// activate optimization for contiguous iterators to (const) bytes and integral values
		return _Find_unchecked1(_First, _Last, _Val, bool_constant<_Memchr_in_find_is_safe<_InIt, _Ty>>{});
	}

	template <class _InIt, class _Ty>
	_NODISCARD _CONSTEXPR20 _InIt find(_InIt _First, const _InIt _Last, const _Ty & _Val) { // find first matching _Val
		_Adl_verify_range(_First, _Last);
		_Seek_wrapped(_First, _Find_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Val));
		return _First;
}
	template <class _InIt, cl ass _Ty>
	_NODISCARD constexpr _InIt _Find_unchecked1(_InIt _First, const _InIt _Last, const _Ty & _Val, false_type) {
		// find first matching _Val
		for (; _First != _Last; ++_First) {
			if (*_First == _Val) {//find底层源码也是==比较，由于自定义数据类型不知道怎么比较，需要重载==号
				break;				//*_First == p 再与p5比较，调用==操作符函数
			}
		}

		return _First;
	}
#endif
}

#if 0
/*
	find_if算法 条件查找
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return 返回第一个满足条件的迭代器的位置
*/
find_if(iterator beg, iterator end, _callback);
#endif
#include <functional>
class MyComparePerson : public binary_function<Person*, Person* ,bool>
{
public:
	bool operator()(Person *p1,Person* p2) const//注意：容器是Person*元素，比较的参数也应该是Person*
	{
		return p1->m_name == p2->m_name && p1->m_age == p2->m_age;
	}
};
void test3()
{
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	//指针作比较是没有意义的
	Person* p = new Person("bbb", 20);
	//find_if(v.begin(), v.end(), p)//不能这样使用

	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyComparePerson(),p));//*_Fist == p1
	if (pos != v.end())
		cout << "找到了元素 姓名：" << (*pos)->m_name << " 年龄：" << (*pos)->m_age << endl;
	else
		cout << "未找到" << endl;
}

#if 0
/*
	adjacent_find算法 查找相邻重复元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
	@return 返回相邻元素的第一个位置的迭代器
*/
adjacent_find(iterator beg, iterator end, _callback);
#endif
void test4()
{
	vector<int> v;

	v.push_back(3);
	v.push_back(2);
	v.push_back(30);
	v.push_back(30);
	v.push_back(6);
	v.push_back(3);

	vector<int>::iterator ret = adjacent_find(v.begin(), v.end());//返回第一个相邻元素的指针
	//_FwdIt adjacent_find(const _FwdIt _First, const _FwdIt _Last)
	//由于_First类型，可知_FwdIt为迭代器类型
	if (ret != v.end())
		cout << "找到了相邻的重复元素：" << *ret << endl;
	else
		cout << "未找到" << endl;
}

#if 0
/*
	binary_search算法 二分查找法
	注意: 在无序序列中不可用
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return bool 查找返回true 否则false
*/
bool binary_search(iterator beg, iterator end, value);
#endif
void test5()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
		cout << "找到了数据2"<< endl;
	else
		cout << "未找到数据2" << endl;
}

#if 0
/*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  value回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
count(iterator beg, iterator end, value);
/*
	count_if算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
count_if(iterator beg, iterator end, _callback);
#endif
class GreaterThan3
{
public:
	bool operator()(int val)
	{
		return val >= 3;
	}
};
void test6()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 3);
	cout << "3的个数为：" << num << endl;

	//统计大于等于3的个数
	num = count_if(v.begin(), v.end(), GreaterThan3());
	//0 1 2 3 4 5 6 7 8 9 3 3 3 
	cout << "大于等于3的个数为：" << num << endl;
}

//自定义数据类型
class Person2
{
public:
	Person2(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person2& p)//报错：二元“ == ”: 没有找到接受“const _Ty”类型的右操作数的运算符(或没有可接受的转换)
		//重载底层源码需要严格控制变量类型，这里不加const修饰参数p，会报错
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test7()
{
	vector<Person2> v;

	Person2 p1("刘备", 35);
	Person2 p2("关羽", 35);
	Person2 p3("张飞", 35);
	Person2 p4("赵云", 30);
	Person2 p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person2 p("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);//count底层源码也是==比较，由于自定义数据类型不知道怎么比较，需要重载==号
	cout << "num = " << num << endl;
}
class AgeLess35
{
public:
	bool operator()(const Person2& p)
	{
		return p.m_Age < 35;
	}
};
void test8()
{
	vector<Person2> v;

	Person2 p1("刘备", 35);
	Person2 p2("关羽", 35);
	Person2 p3("张飞", 35);
	Person2 p4("赵云", 30);
	Person2 p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小于35岁的个数：" << num << endl;
}

int main()
{
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	test8();
	return 0;
}

//技巧：当使用STL中的函数，可以通过转到定义查看函数源码的参数和返回类型