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
		//如果赋值本身，返回自身
		if (&s == this)
			return *this;
		if (this->str != NULL)
			delete[] this->str;

		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(this->str, s.str);

		cout << "operator=重载函数 s.str = " << s.str << endl;

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
	//移动赋值运算符重载函数
	//注意：参数是非const的右值引用
	MyString& operator=(MyString&& s)
	{
		//如果赋值本身，返回自身
		if (&s == this)
			return *this;
		if (this->str != NULL)
			delete[] this->str;

		this->len = s.len;
		this->str = s.str;//拷贝地址，没有重新申请内存

		//原来的指针置空
		s.str = NULL;
		
		cout << "移动operator=重载函数" << endl;
		
		return *this;
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

	return obj;//MyString t = obj; 返回临时对象t，用右值接收，会调用移动构造函数 tmp == obj 给临时对象(右值sobj)取别名tmp
	//func函数结束，obj需要析构，但不会delete，只是走了析构的代码
}
int main()
{

	MyString m("bcd");//实例化一个对象
	m = func();

	cout << "&m = " << (void*)&m << endl;

	//没有移动赋值运算符重载函数，VS下的结果：
	//有参构造函数 this->str = bcd								MyString m("bcd");
	//有参构造函数 this->str = mike								MyString obj("mike");
	//&obj = 00....	
	//移动构造函数												return obj;返回临时对象，调用移动构造
	//析构函数 operator=重载函数 s.str = mike					func函数结束，obj析构，没有delete。m = func();临时对象赋值给m对象
	//析构函数 已执行delete this->str = mike &tmp = 01....		main函数结束，临时变量释放
	//析构函数 已执行delete this->str = mike					main函数结束，m释放

	//有移动赋值运算符重载函数，VS下的结果：
	//有参构造函数 this->str = bcd
	//有参构造函数 this->str = mike
	//&obj = 00....
	//移动构造函数
	//析构函数 移动operator=重载函数 s.str = mike
	//析构函数 &tmp = 01....
	//析构函数 已执行delete this->str = mike

	return 0;
}

/*
和拷贝构造函数类似，有几点需要注意：
参数（右值）的符号必须是右值引用符号，即“&&”。
参数（右值）不可以是常量，因为我们需要修改右值。
参数（右值）的资源链接和标记必须修改，否则，右值的析构函数就会释放资源，转移到新对象的资源也就无效了。

有了右值引用和转移语义，我们在设计和实现类时，
对于需要动态申请大量资源的类，应该设计转移构造函数和转移赋值函数，以提高应用程序的效率。
*/