#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//继承控制关键字：final override
//final的作用：阻止类进一步派生，虚函数的进一步重写

#if 0
class A1 final//加上final关键字后，指定A1类不能派生，即不能被继承
{
public:
	int a;
};
class A2 :public A1//err，基类不能再派生
{
public:

};
#endif

class B1
{
public:
	virtual void func() final{}//final最终版本的虚函数，不能再重写
};
//派生类重写基类的虚函数
class B2 :public B1
{
public:
	//virtual void func() {}//err，基类中的虚函数是最终版本，不能再重写
};

int main()
{
	return 0;
}