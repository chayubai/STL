#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <cstring>
class MyString
{
public:
	MyString(const char* s = "abc")
	{
		this->len = strlen(s);
		this->str = new char[len + 1];
		strcpy(this->str, s);

		cout << "有参构造函数 this->str = " << str << endl;
	}
	MyString(const MyString& s)
	{
		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(this->str, s.str);
		cout << "拷贝构造函数 s.str = " << s.str << endl;
	}
	MyString& operator=(const MyString& s)
	{
		cout << "operator=重载函数 s.str = " << s.str << endl;

		//如果赋值本身，返回自身
		if (&s == this)
			return *this;
		if (this->str != NULL)
			delete[] this->str;

		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(this->str, s.str);

		return *this;
	}
	~MyString()
	{
		cout << "析构函数  ";

		if (this->str != NULL)
		{
			cout << "已执行delete this->str = " << this->str << endl;

			delete[] this->str;
			this->str = NULL;
			this->len = 0;
		}
	}
private:
	char* str;
	int len = 0;
};

MyString func()//返回普通对象，不是引用，即返回的是右值
{
	MyString obj("mike");
	cout << "&obj = " << (void*)&obj << endl;
	//qt下，返回值优化技术，直接将obj对象过渡给tmp
	//vs下，debug模式下，没有做返回值优化
	return obj;
}
int main()
{
	MyString tmp = func();
	cout << "&tmp = " << (void*)&tmp << endl;

	//同时从vs和qt下观察，&obj和&tmp的地址
	//发现qt下是相同的
	//发现vs下是不同的

	//Qt下的结果：
	//有参构造函数 this->str = mike					MyString obj("mike");
	//&obj = 00....
	//&tmp = 00....
	//析构函数 已执行delete this->str = mike		MyString tmp = func();obj直接过渡到tmp，main调用完毕，释放tmp
	//&obj和&tmp的地址相同

	//VS下的结果：
	//有参构造函数 this->str = mike					MyString obj("mike");
	//&obj = 00....
	//拷贝构造函数 s.str = mike						return obj;生成临时对象(新对象)，返回临时对象(新对象)，由obj初始化新对象，调用拷贝构造，
	//析构函数 已执行delete this->str = mike		func调用完毕，obj释放
	//&tmp = 00....
	//析构函数 已执行delete this->str = mike		MyString tmp = func();临时对象直接过渡到tmp(做了一次优化，如果没有做优化应该再调用一次拷贝和一次析构临时对象)，main调用完毕，释放tmp
	//&obj和&tmp的地址不同

	//防止返回值优化选项：
	//g++ xxx.cpp -fno-elide-constructors -std=c++11
	//linux下的结果：
	//有参构造函数 this->str = mike					MyString obj("mike");
	//&obj = 0x....
	//拷贝构造函数 s.str = mike						return obj;生成临时对象(新对象)，由obj初始化新对象，返回临时对象(新对象)
	//析构函数 已执行delete this->str = mike		func调用完毕，obj释放
	//拷贝构造函数 s.str = mike						MyString tmp = func();临时对象初始化tmp
	//析构函数 已执行delete this->str = mike		析构临时对象
	//&tmp = 0x....
	//析构函数 已执行delete this->str = mike		main调用完毕，释放tmp

	//频繁调用拷贝构造和析构函数，效率会很低
	//如何使得不管什么编译器下，编译后都是效率最高的？ -- 移动语义
	//1、移动构造函数
	//2、移动赋值运算符重载函数
	return 0;
}