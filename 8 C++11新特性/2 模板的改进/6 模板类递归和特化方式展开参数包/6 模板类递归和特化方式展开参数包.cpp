#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//继承方式递归方式展开可变参数模板类
//1、变长模板类定义
//2、边界结束条件
//3、变长模板类声明

//3、变长模板类声明
template<int...last>
class Test
{
};

//1、变长模板类定义
template<int first,int...last>
class Test<first, last...>
{
public:
	static const int val = first * Test<last...>::val;
};

//2、边界结束条件
template<> 
class Test<> 
{
public:
	static const int val = 1;
};

int main()
{
	cout << Test<2, 3, 4, 5>::val << endl;
	/*
	Test<2, 3, 4, 5>::val
	Test<3, 4, 5>::val
	Test<4, 5>::val
	Test<5>::val
	Test<>::val

	结果：2 * 3 * 4 * 5 * 1
	*/
	return 0;
}