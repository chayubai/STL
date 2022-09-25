#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//仿函数，重载operator()
class MyFunctor
{
public:
    MyFunctor(int tmp) : round(tmp) {}
    int operator()(int tmp)
    {
        return tmp + round;
    }
private:
    int round;//状态
};

void test1()
{
    int round = 2;
    MyFunctor f(round);//调用构造函数
    cout << "result = " << f(10) << endl; //operator()(int tmp)
}
void test2()
{
    int round = 2;
    //lambda表达式
    auto f = [round](int tmp)
    {
        return round + tmp;
    };

    cout << "result = " << f(1) << endl;
    //事实上，仿函数是编译器实现lambda的一种方式，
    //通过编译器都是把lambda表达式转化为一个仿函数对象。
    //因此，在C++11中，lambda可以视为仿函数的一种等价形式。
}
int main()
{

    return 0;
}
