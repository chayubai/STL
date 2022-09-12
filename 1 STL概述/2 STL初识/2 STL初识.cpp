#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//迭代器 遍历功能，用指针理解
//原生指针也是一种迭代器
void test1()
{
	int arr[5] = { 1,2,3,4,5 };
	
	int* p = arr;//指针指向数组首地址，&array[0]
	for (int i = 0; i < 5; i++)
	{
		//cout << arr[i] << endl;
		cout << *(p++) << endl;
	}
}

#include <vector>
#include <algorithm>

void myPrint(int val)
{
	cout << val << endl;
}
void test2()
{
	//容器
	vector<int> v;//vector动态数组，创建一个vector容器v，容器中存放元素类型是int类型，使用容器需要包含头文件#include<vector>
	
	//myArray<int> arr;

	//容器v中插入元素
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//算法通过迭代器才能访问容器中的元素。
	//遍历容器v中的元素，使用迭代器
	
	//迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针

	//需要加作用域，表示使用具体类模板作用域下的迭代器，即每个容器都有自己专属的迭代器
	vector<int>::iterator itBegin = v.begin();//v.begin()起始迭代器，(指针)指向容器中第一个数据

	vector<int>::iterator itEnd = v.end();//v.end()结束迭代器，(指针)指向容器中最后一个元素的下一个位置

	//第一种遍历
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//第二种遍历
	//vector<int>::iterator迭代器类型
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it表示整型数据<int>
		cout << *it << endl;
	}

	//第三种遍历
	for_each(v.begin(), v.end(), myPrint);//_Func回调函数，使用标准算法，需要包含头文件#include <algorithm>
	
	//for_each()的源码：
	/*
	template <class _InIt, class _Fn>
	_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) 
	{ // perform function for each element [_First, _Last)
    
		_Adl_verify_range(_First, _Last);
		auto _UFirst      = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);

		for (; _UFirst != _ULast; ++_UFirst) //for (; _First != _Last; ++_First) for (; it != v.end(); it++)
		{
			_Func(*_UFirst);//_Func(*_First)回调函数，通过*_First找到元素，传给myPrint的val
		}

		return _Func;
	}
	*/
}

#include <string>
//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void PrintPerson1(Person& p)
{
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}
void test3()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//每个容器都要自己专属的迭代器 vector<int>::iterator  vector<Person>::iterator
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it表示Person类型的对象<Person>，it可以理解为指针
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
		//cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}

	for_each(v.begin(), v.end(), PrintPerson1);//_Func(*_First)回调函数，通过*_First找到Person对象，传给PrintPerson1的p
}

void PrintPerson2(Person*& p)
{
	cout << "姓名：" << p->m_Name << " 年龄：" << p->m_Age << endl;
}
//存放自定义数据类型的指针
void test4()
{
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it表示Person类型的对象的指针<Person*>
		cout << "姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
	}

	for_each(v.begin(), v.end(), PrintPerson2);//_Func(*_First)回调函数，通过*_First找到Person*对象的指针，传给PrintPerson2的p
}

//容器嵌套容器
void test5()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++) 
	{
		v1.push_back(i + 1);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}

	//将小容器放入到大容器种
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it表示vector<int>类型的小容器<vector<int>>
		for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
			cout << *vit << " ";
		cout << endl;
	}
}

int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	return 0;
}