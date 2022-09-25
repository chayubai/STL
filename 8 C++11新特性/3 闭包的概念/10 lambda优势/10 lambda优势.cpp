#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm> //std::for_each
#include <iostream>
using namespace std;

vector<int> nums;
vector<int> largeNums;

class LNums
{
public:
    LNums(int u) : ubound(u) {} //构造函数

    void operator () (int i) const
    {//仿函数
        if (i > ubound)
        {
            largeNums.push_back(i);
        }
    }
private:
    int ubound;
};

int tmp = 5;

void func(int& n)
{
    if (n > tmp)
    {
        largeNums.push_back(n);
    }
}

void print(int& n)
{
    cout << n << " ";
}

void test1()
{
    //初始化数据
    for (auto i = 0; i < 10; ++i)
    {
        nums.push_back(i);
    }
    int ubound = 5;

    //1、传统的for循环
    for (auto itr = nums.begin(); itr != nums.end(); ++itr)
    {
        if (*itr > ubound)
        {
            largeNums.push_back(*itr);
        }
    }
    for (auto itr = largeNums.begin(); itr != largeNums.end(); itr++)
    {
        cout << *itr << ", ";
    }
    cout << endl;
}
void test2()
{
    //初始化数据
    for (auto i = 0; i < 10; ++i)
    {
        nums.push_back(i);
    }
    int ubound = 5;

    //2、使用仿函数
    for_each(nums.begin(), nums.end(), LNums(ubound));

    //2、回调函数
    //for_each(nums.begin(), nums.end(), func);

    //2、回调函数遍历
    for_each(largeNums.begin(), largeNums.end(), print);
}
void test3()
{
    //初始化数据
    for (auto i = 0; i < 10; ++i)
    {
        nums.push_back(i);
    }
    int ubound = 5;

    //3、使用lambda函数和算法for_each
    for_each(nums.begin(), nums.end(), [=](int i)
        {
            if (i > ubound)
            {
                largeNums.push_back(i);
            }
        }
    );

    //4、使用lambda函数遍历元素
    for_each(largeNums.begin(), largeNums.end(), [=](int i)
        {
            cout << i << ", ";
        }
    );
    cout << endl;

}
int main()
{
    //test1();
    //test2();
    test3();
    return 0;
}
