#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//deque容器，类似与一个双向数组，vector是单向数组
//底层是动态顺序表，支持随机访问，分段连续的内存空间
//特性总结:
//双端插入和删除元素效率较高.
//指定位置插入也会导致数据元素移动,降低效率.
//可随机存取, 效率高.

//deque容器的实现原理，类似与二维数组，外层数组存放指针，内层数组元素，内存元素个数相同
//当需要头插数据的时候，放入第一个外层数组指向的内层数组中，
//当头插空间不足，在第一个外层数组前开辟指针
//当需要尾插数据的时候，放入最后一个外层数组指向的内存数组中
//当尾插空间不足，在最后一个外层数组后开辟指针

#include <deque>
//注意：pos是迭代器指向的位置，begin是迭代器指向的第一个元素的位置，end是迭代器指向的最后一个元素的下一个位置

#if 0
1、deque构造函数
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque& deq);//拷贝构造函数。
#endif

#if 0
2、deque赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque& operator=(const deque& deq); //重载等号操作符 
swap(deq);// 将deq与本身的元素互换


#endif

#if 0
3、deque大小操作
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
#endif
void printDeque(const deque<int> &d)
{
	//iterator 普通迭代器
	//reverse_iterator 逆序迭代器
	//const_iterator 只读迭代器
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 1000;//使用const修饰d，防止*d.迭代器误操作
		//注意：迭代器使用const_iterator
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	deque<int> d2;
	d2 = d;// = 赋值

	printDeque(d2);

	if (d2.empty())
	{
		cout << "d2为空" << endl;
	}
	else
	{
		cout << "d2不为空，大小为：" << d2.size() << endl;
	}

	deque<int> d3(d);//拷贝构造

	printDeque(d3);
}

#if 0
4、deque双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

#if 0
5、deque数据存取
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据
#endif
#endif
void test2()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	d.push_front(40);
	d.push_front(50);
	printDeque(d);

	//注意由于pop_front()和pop_back()没有返回值，删除前需要确定是否是自己需要删除的值
	int val = d.front();
	d.pop_front();
	printDeque(d);

	//注意由于pop_front()和pop_back()没有返回值，删除前需要确定是否是自己需要删除的值
	val = d.back();
	d.pop_back();
	printDeque(d);

	cout << d.front() << endl;
	cout << d.back() << endl;

}
#if 0
6、deque插入操作 pos为迭代器
insert(pos, elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值。
#endif

#if 0
7、deque删除操作
clear();//移除容器的所有数据
erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
#endif
void test3()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	d.push_back(40);
	d.push_front(30);
	
	printDeque(d);

	//d.insert(d.begin(), 100);
	//d.insert(d.begin(), 2,100);
	//printDeque(d);

	//d.insert(d.begin()++, 2, 100);
	printDeque(d);

	//注意：使用前置++插入数据，才能正确插入
	d.insert(++d.begin(), 2, 100);
	printDeque(d);

	//将两个100删除
	//d.erase(++d.begin());
	//d.erase(++d.begin());
	//printDeque(d);
	
	//erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	d.erase(d.begin()+1, d.begin() + 3);//注意end是开区间
	printDeque(d);
}
int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}