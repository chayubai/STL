#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class X
{
public:

	//X(){}//用户自己提供的无参构造，比编译器提供的默认构造效率低

	X() = default;//让编译器提供一个默认的构造函数，比自己提供的无参构造效率高

	X(int i)
	{//写了有参构造，编译器不会提供默认构造
		a = i;
	}
	int a;
};
//default只能修饰类中默认提供的成员函数：默认构造，拷贝构造，=赋值操作符重载函数，析构函数等
#if 0
class X2
{
public:

	int f() = default;//err
	X2(int a) = default;//err

};
#endif

class X3
{
public:

	X3();//类内声明

	X3(int i)
	{//写了有参构造，编译器不会提供默认构造
		a = i;
	}
	int a;
};
X3::X3() = default;//default可以放在类的外部，即类外实现，注意：需要加作用域

int main()
{
	X obj;
	return 0;
}