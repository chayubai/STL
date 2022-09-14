#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <iterator>

#if 0
/*
	copy算法 将容器内指定范围的元素拷贝到另一容器中
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param dest 目标起始迭代器
*/
copy(iterator beg, iterator end, iterator dest)
#endif
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	v2.resize(v1.size());//注意：往空的容器里面直接放数据，会报错
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//利用copy打印,ostream_iterator的头文件：#include <iterator>
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));//将拷贝的数据，放到流迭代器中，通过cout对象输出
}

#if 0
/*
	replace算法 将容器内指定范围的旧元素修改为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param oldvalue 旧元素
	@param newvalue 新元素
*/
replace(iterator beg, iterator end, oldvalue, newvalue)
#endif
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	replace(v.begin(), v.end(), 3, 3000);
	//replace(v.begin(), v.end(), 23, 3000);//找不到不替换
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

#if 0
/*
	replace_if算法 将容器内指定范围满足条件的元素替换为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param callback函数回调或者谓词(返回Bool类型的函数对象)
	@param newvalue 新元素
*/
replace_if(iterator beg, iterator end, _callback, newvalue)
#endif
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val == 3;
	}
};
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);

	//将所有等于3的元素替换成3000
	replace_if(v.begin(), v.end(), MyReplace(), 3000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

#if 0
/*
	注意: 交换的容器要同种类型
	swap算法 互换两个容器的元素
	@param c1容器1
	@param c2容器2
*/
swap(container c1, container c2)
#endif
void test4()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2(10, 100);
	cout << "交换前V1容器：" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	swap(v1, v2);
	cout << "交换后V1容器：" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

//技巧：当使用STL中的函数，可以通过转到定义查看函数源码的参数和返回类型