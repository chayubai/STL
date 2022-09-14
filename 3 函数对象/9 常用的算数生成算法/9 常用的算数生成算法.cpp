#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
#if 0
/*
	头文件：#include <numeric>
	accumulate算法 计算容器元素累计总和
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value，在最终结果的基础上的累加值
	@param 返回int总和
*/
accumulate(iterator beg, iterator end, value)
#endif
void test1()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//0-100的累计和
	int sum = accumulate(v.begin(), v.end(), 0);//第三个参数 起始累加值
	cout << "sum = " << sum << endl;

	sum = accumulate(v.begin(), v.end(), 1000);
	cout << "sum = " << sum << endl;
}

#if 0
/*
	头文件：#include <numeric>
	fill算法 向容器中添加元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value t填充元素
*/
fill(iterator beg, iterator end, value)
#endif
void test2()
{
	vector<int> v;
	v.resize(10);//注意：如果不要这一行，不会报错，但不打印结果

	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

int main()
{
	//test1();
	test2();
	
	return 0;
}