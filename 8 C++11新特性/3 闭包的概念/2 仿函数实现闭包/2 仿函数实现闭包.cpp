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

int main()
{
    int round = 2;
    MyFunctor f(round);//调用构造函数
    cout << "result = " << f(10) << endl; //operator()(int tmp)

    return 0;
}
