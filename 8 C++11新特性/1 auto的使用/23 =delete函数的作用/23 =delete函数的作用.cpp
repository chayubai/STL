#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class X
{
public:

	X(){}//无参构造

	//X(const X&) {}//拷贝构造
	X(const X&) = delete;//用=delete修饰的函数，此函数被禁用

	//X& operator= (const X&) { return *this; }//=赋值运算符重载函数
	X& operator= (const X&) = delete;//用=delete修饰的函数，此函数被禁用

	//普通函数也能使用=delete修饰
	//X(int) {}
	X(int) = delete;//用=delete修饰的函数，此函数被禁用

	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;
};

int main()
{
	X obj1;//调用无参构造

	//X obj2 = obj1;//err，拷贝构造被禁用

	//obj2 = obj1;//err，=赋值运算符重载函数被禁用

	//X obj3(10);//err

	//X* p = new X;//err

	//X* p = new X[10];//err

	return 0;
}