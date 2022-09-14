#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#if 0
/*
	merge算法 容器元素合并，并存储到另一容器中
	注意：两个容器必须是有序的，且两容器的顺序要一致（可以容器类型不相同？）
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
//算法思想：从两个有序容器中，取小者放入第三个容器中，当有一个容器为空，剩余的另一个容器中的元素全部放入第三个容器中
*/
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test11()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());//注意：往空的容器里面直接放数据，会报错
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

void test12()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());

	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());//注意：往空的容器里面直接放数据，会报错

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin(), greater<int>());
	//注意：merge默认也是从小到大，当两个容器是从大到小，merge也要指定从大到小
	//否则，编译会通过，但是运行会报错
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}
#if 0
/*
	sort算法 容器元素排序
	@param beg 容器1开始迭代器
	@param end 容器1结束迭代器
	@param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
sort(iterator beg, iterator end, _callback)
#endif
#include <functional>
void test2()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//降序排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

#if 0
/*
	random_shuffle算法 对指定范围内的元素随机调整次序
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
*/
random_shuffle(iterator beg, iterator end)
#endif
#include <ctime>
void test3()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());//注意也需要加srand()，否则也是伪随机
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}
//应用场景：洗牌，抽签

#if 0
/*
	reverse算法 反转指定范围的元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
*/
reverse(iterator beg, iterator end)
#endif
void test4()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(0);
	v.push_back(30);
	v.push_back(20);
	//注意：有序的反转是逆序

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	reverse(v.begin(), v.end());

	cout << "反转后：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

//注意：sort、random_shuffle()函数对于不支持随机访问的容器，使用会报错
//对于sort提供成员函数，random_shuffle不提供成员函数，如果需要使用需要自己写
//对于reverse支持不能随机访问的容器
#include <list>
void test5()
{
	vector<int> v1;
	list<int> l2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		l2.push_back(i + 1);
	}
	sort(v1.begin(), v1.end(), greater<int>());
	//sort(l2.begin(), l2.end(), greater<int>());//报错
	l2.sort(greater<int>());//可以使用自带的成员函数sort

	vector<int> vTarget;
	vTarget.resize(v1.size() + l2.size());//注意：往空的容器里面直接放数据，会报错

	merge(v1.begin(), v1.end(), l2.begin(), l2.end(), vTarget.begin(), greater<int>());
	//注意：merge默认也是从小到大，当两个容器是从大到小，merge也要指定从大到小
	//否则，编译会通过，但是运行会报错
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

void test6()
{
	list<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//random_shuffle(v.begin(), v.end());//list不支持随机访问，使用random_shuffle报错
	//二进制“ + ”:“std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<_Ty>>>”不定义该运算符或到预定义运算符可接收的类型的转换
	//v.random_shuffle();//报错：list容器没有成员函数random_shuffle
	//如果需要使用，不要自己写
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

void test7()
{
	list<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(0);
	v.push_back(30);
	v.push_back(20);
	//注意：有序的反转是逆序

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	reverse(v.begin(), v.end());

	cout << "反转后：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

int main()
{
	srand((unsigned int)time(NULL));
	
	//test11();
	//test12();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}

//技巧：当使用STL中的函数，可以通过转到定义查看函数源码的参数和返回类型