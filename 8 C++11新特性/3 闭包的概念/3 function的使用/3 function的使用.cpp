#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <functional> //std::function
void func(void)
{//普通全局函数
    cout << __func__ << endl;
}

class Test
{
public:
    static int test_func(int a)
    {//类中静态函数
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

class MyFunctor
{
public:
    int operator()(int a)
    {//仿函数
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

int main()
{
    //function< 返回类型(形参列表类型) >
    
    //绑定一个普通函数
    function< void(void) > f1 = func;//f1类似与函数指针
    f1();//等价于func()

    //绑定类中的静态函数
    function< int(int) > f2 = Test::test_func;
    cout << f2(111) << endl;//等价于Test::test_func(111)

    //绑定一个仿函数，绑定对象，仿函数调用obj()
    MyFunctor obj;
    function< int(int) > f3 = obj;
    cout << f3(222) << endl;////等价于obj(222)

    /*
   std::function对象最大的用处就是在实现函数回调，
   使用者需要注意，它不能被用来检查相等或者不相等，
   但是可以与NULL或者nullptr进行比较。
    */

    return 0;
}
