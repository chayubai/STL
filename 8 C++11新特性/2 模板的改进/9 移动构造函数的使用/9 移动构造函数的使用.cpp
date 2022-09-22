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

	//移动构造函数
	//注意：参数是非const的右值引用
	MyString(MyString&& tmp)
	{
		this->str = tmp.str;//拷贝地址，没有重新申请内存
		this->len = tmp.len;

		//原来的指针置空
		tmp.str = NULL;

		cout << "移动构造函数" << endl;
	}

	~MyString()
	{
		cout << "析构函数  ";

		if (this->str != NULL)
		{
			cout << "已执行delete this->str = " << this->str;

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

	return obj;//MyString t = obj; 返回临时对象t，用右值接收，会调用移动构造函数 tmp == obj 给临时对象(右值obj)取别名tmp
	//func函数结束，obj需要析构，但不会delete，只是走了析构的代码
}
int main()
{
	//MyString tmp = func();
	//cout << "&tmp = " << (void*)&tmp << endl;

	//频繁调用拷贝构造和析构函数，效率会很低
	//如何使得不管什么编译器下，编译后都是效率最高的？ -- 移动语义

	MyString&& m = func();//右值引用接收,对临时变量取别名m, main函数结束，m会析构，会delete
	//m.str = t.str m.len = t.len t.str = NULL

	cout << "&m = " << (void*)&m << endl;

	//VS下的结果：
	//有参构造函数 this->str = mike					MyString obj("mike");
	//&obj = 01....
	//移动构造函数									return obj;生成临时对象(新对象)，返回临时对象(新对象)，由obj初始化新对象，obj调用移动构造函数
	//析构函数 &m = 01....							func调用完毕，obj调用析构函数，没有释放
	//析构函数 已执行delete this->str = mike		MyString&& m = func();给临时对象取别名为m，main调用完毕，释放m，也就是临时对象，

	return 0;
}