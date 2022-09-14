#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

//A集合：0 1 2 3 4 5 6 7 8 9
//B集合：5 6 7 8 9 10 11 12 13 14
//差集：除去相交部分的元素，另一个集合中剩余的元素
//A与B的差集：0 1 2 3 4
//B与A的差集：10 11 12 13 14

#if 0
/*
	set_intersection算法 求两个set集合的交集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test1()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//设置容器大小，最坏的结果，取容器小的那个
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	
	//注意：遍历时，结束迭代器是itEnd
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
}
#if 0
/*
	set_union算法 求两个set集合的并集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test2()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//设置容器大小，最坏的结果，取两容器之和
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	//注意：遍历时结束迭代器是itEnd
	//如果写vTarget.end()，则会将容器中为0的全部打印出来
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
}

#if 0
/*
	set_difference算法 求两个set集合的差集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
*/
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test3()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//设置容器大小，最坏的结果，取两容器最大的那个
	vTarget.resize(max(v1.size(), v2.size()));

	//A 与 B的差集 
	cout << "A 与 B的差集 ：" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	//注意：遍历时结束迭代器是itEnd
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
	cout << endl;

	//B 与 A的差集 
	cout << "B 与 A的差集 ：" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

	//注意：遍历时结束迭代器是itEnd
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
}

int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}