#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//C++ 11允许派生类继承基类的构造函数（默认构造函数、复制构造函数、移动构造函数除外）。
#if 0
class A
{
public:
    A(int i) { cout << "i = " << i << endl; }
    A(double d, int i) {}
    A(float f, int i, const char* c) {}
    // ...
};

class B : public A
{
public:
    using A::A; // 继承构造函数
    // ...
    virtual void ExtraInterface() {}
};
#endif
class A
{
public:
    A(int x, int y)
    {
        a = x;
        b = y;
    }
protected:
    int a;
    int b;
};

class B :public A
{
public:
#if 0
    //1、通过参数列表给基类构造函数传参
    B(int x, int y) :A(x, y)
    {

    }
#endif

    //2、等价using指令
    using A::A;//继承有参构造函数

    void dispaly()
    {
        cout << "a = " << a << ", b=" << b << endl;
    }
    //没有增加新的成员变量

    //当如果有新增的成员变量，必须使用有参构造初始化
};

//注意：
//1、继承的构造函数只能初始化基类中的成员变量，不能初始化派生类的成员变量
//2、如果基类的构造函数被声明为私有，或者派生类是从基类中虚继承，那么不能继承构造函数
//3、一旦使用继承构造函数，编译器不会再为派生类生成默认构造函数

int main()
{
    //B b;//当B没有构造函数时，会报错。因为b继承了A是属性，没有对A进行初始化
    B b(10,20);
    b.dispaly();
	return 0;
}