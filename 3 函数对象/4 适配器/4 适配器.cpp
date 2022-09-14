#define _CRT_SECURE_NO_WARNINGS 1

//注意：这节课讲的几种适配器，最高的支持标准是C++14，学习了可以读懂旧代码
//更高的标准里已被舍弃，能使用更简洁、统一的bind()方法进行适配。
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyPrint:public binary_function<int,int,void>//二元继承
{
public:
	/*void operator()(int val)
	{
		cout << val << endl;
	}*/
	void operator()(int val,int start) const////二元 实际上，是重载binary_function类的()操作符
	{
		//cout << val + start << endl;
		cout << "val = " << val << " start = " << start << " sum = " << val + start << endl;
	}
};
//1、函数对象适配器bind2nd()
//绑定适配器：将一个二元函数对象转为一元函数对象
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//方式1：
	//MyPrint print;
	//for_each(v.begin(), v.end(), print);
	//方式2：
	//for_each(v.begin(), v.end(), MyPrint());//for_each算法底层*_First == val，只有一个参数
	int num = 0;
	cout << "请输入起始累加值：";
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd(MyPrint(),num));//bind2nd(MyPrint(),num)是一个内建函数对象，需要包含#include <functional>
	//bind2nd(MyPrint(),num)就相当于适配器，适配成一个参数以适配底层源码只能传入一个参数 *_First = bind2nd()
	for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
	//bind1st(参数1, 参数2) operator()(int val,int start) 参数1 == start 参数2 == val
}
//1、利用内建函数对象对参数进行绑定
//2、继承binary_function<参数1类型，参数2类型，返回值类型>的类
//3、operator() const

//2、取反适配器
class GreaterThanFive:public unary_function<int,bool>//一元继承
{
public:
	bool operator()(int val) const//一元
	{
		return val > 5;
	}
};
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThanFive());//find_if算法底层*_First == val，只有一个参数
	if (pos != v.end())
		cout << "找到大于5的值为：" << *pos << endl;
	else
		cout << "未找到" << endl;

	//一元取反：找小于5的数
	//方法1：operator()的return改为 < 5
	//方法2：not1()取反内建函数对象
	pos = find_if(v.begin(), v.end(), not1(GreaterThanFive()));//find_if算法底层*_First == val，只有一个参数
	if (pos != v.end())
		cout << "找到小于5的值为：" << *pos << endl;
	else
		cout << "未找到" << endl;

	//找小于num的数
	int num = 5;
	pos = find_if(v.begin(), v.end(), not1( ( bind2nd( greater<int>() ,num ) ) ) );//find_if算法底层*_First == val，只有一个参数
	//bind2nd( greater<int>() ,num )就相当于适配器，适配成一个参数以适配底层源码只能传入一个参数
	if (pos != v.end())
		cout << "找到小于5的值为：" << *pos << endl;
	else
		cout << "未找到" << endl;

	//二元取反：
	sort(v.begin(), v.end(),not2(less<int>()));//not2(less<int>())相当于greater<int>()
	//not1的operator()参数为一个，即一元谓词
	//not2的operator()参数为两个，即二元谓词

	//注意：less<int>()，greater<int>()内建函数对象底层源码以及继承了对应的类，和operator()加了const
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
//1、利用not1进行一元取反
//2、继承unary_function
//3、operator() const

//3、函数适配器
void myPrint3(int val,int start)//全局函数没有this指针
{
	cout << val + start<< endl;
}
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//如果需要对回调函数进行参数绑定，需要将回调函数是配成函数对象
	//将函数指针(函数名) 适配成函数对象/仿函数，ptr_fun
	//函数没有继承，也不用加const
	//
	//bind2nd
	for_each(v.begin(), v.end(),bind2nd( ptr_fun(myPrint3),100 ) );//使用回调函数
}

#include <string> 
//4、成员函数适配器
class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	void showPerson()
	{
		cout << "成员函数：姓名：" << m_name << " 年龄：" << m_age << endl;
	}
	void addAge()
	{
		m_age += 10;
	}
	string m_name;
	int m_age;
};
void myPrint4(Person& p)
{
	cout << "全局函数：姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
}
void test4()
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

	//利用全局函数（回调函数）
	for_each(v.begin(), v.end(), myPrint4);
	
	//利用mem_fun_ref适配成全局函数
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));

	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

void test5()
{
	vector<Person*> v1;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	for_each(v1.begin(), v1.end(), mem_fun(&Person::showPerson));
}

//如果容器存放的是对象指针，  那么用mem_fun
//如果容器中存放的是对象实体，那么用mem_fun_ref

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}