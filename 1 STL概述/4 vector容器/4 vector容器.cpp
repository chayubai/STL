#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//vector容器，类似与一个动态的数组（动态顺序表），每次动态开辟的空间不是按2倍的大小开辟
//底层是动态顺序表，支持随机访问

//所谓动态增加大小，并不是在原空间之后续接新空间(因为无法保证原空间之后尚有可配置的空间)，
//而是一块更大的内存空间，然后将原数据拷贝新空间，并释放原空间。
//因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了。
//这是程序员容易犯的一个错误，务必小心。

//特性总结:
//vector是动态数组，连续内存空间，具有随机存取效率高的优点。
//vector是单口容器，在队尾插入和删除元素效率高，在指定位置插入会导致数据元素移动,效率低。
void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
}
//注意：pos是迭代器指向的位置，begin是迭代器指向的第一个元素的位置，end是迭代器指向的最后一个元素的下一个位置

#if 0
1、vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector& vec);//拷贝构造函数。

//例子 使用第2个构造函数 我们可以...
int arr[] = { 2,3,4,1,9 };
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
#endif
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(v1.begin(), v1.end());//调用有参构造
	printVector(v2);

	vector<int> v3(v2);//调用拷贝构造
	printVector(v3);

	int arr[] = { 10,20,30,40,50 };
	vector<int> v4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> v5(v4.begin(), v4.end());
	printVector(v4);
}

#if 0
2、vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector& vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
#endif
void test2()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.assign(v1.begin(), v1.end());//调用有参构造
	printVector(v2);

	vector<int> v3(10,100);//vector(n, elem);//构造函数将n个elem拷贝给本身。
	printVector(v3);
	
	cout << "互换后的v2和v3：" << endl;
	v3.swap(v2);//两个容器的指针进行交换
	printVector(v2);
	printVector(v3);
}

#if 0
3、vector大小操作
size();//返回容器中元素的个数
boo1 empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
//注意：reverse翻转
#endif
void test3()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	if (v1.empty())//或者v1.size()=0
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空，大小为：" << v1.size() << endl;
	}

	v1.resize(10);//重置大小
	printVector(v1);//默认填充0

	v1.resize(3);
	printVector(v1);//多余的删除

	v1.resize(10, 100);
	printVector(v1);//指定填充值
}

#if 0
4、vector数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
#endif
void test4()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << v1.front() << endl;
	cout << v1.back() << endl;
}

#if 0
5、vector插入和删除操作
insert(const_iterator pos, int count, ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
//注意：string容器的删除。string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
#endif
void test5()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	//v1.insert(v1.begin(), 100);//插入1个100
	v1.insert(v1.begin(), 2, 100);//插入2个100

	v1.insert(v1.begin()+2,100);//vector都迭代器支持随机访问
	//支持数组下标，一般都支持随机访问
	printVector(v1);

	v1.push_back(1000);
	printVector(v1);

	v1.pop_back();
	printVector(v1);

	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin(),v1.end());//等价clear()
	v1.clear();
	printVector(v1);
}

//案例1：巧用swap收缩内存
void test6()
{
	//vector添加元素会容量自动增长，但是删除元素容量不会自动减少
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;

	//此时 通过resize改变容器大小
	v.resize(10);

	cout << "capacity:" << v.capacity() << endl;//容量没有改变，造成空间浪费
	cout << "size:" << v.size() << endl;

	//收缩空间
	vector<int>(v).swap(v);//v.resize(10);将前十个数据保留下来，vector<int>(v)使用v.size大小初始化匿名对象
	//匿名对象.swap(v)，通过交换（本质上是交换指针），当匿名对象执行完，指向的数据自动释放
	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;
}

//案例2：巧用reserve预留空间
void test7()
{
	vector<int> v;

	//预先开辟空间，没有这一行，需要开辟30次，才能存100000的数据
	v.reserve(100000);//减少动态开辟带来的消耗

	int* pStart = NULL;
	int count = 0;
	for (int i = 0; i < 100000; i++) 
	{
		v.push_back(i);//动态开辟是，重新找一块空间
		if (pStart != &v[0])//只要开辟新空间，pStart就不一样
		{
			pStart = &v[0];
			count++;//计算总共开辟的多少次空间
		}
	}

	cout << "count:" << count << endl;
	//如果你知道容量大概要存储的元素个数，那么可以提前预留空间
}

#include <list>
void test8()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//注意：使用逆序迭代器reverse_iterator  it++
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << endl;
	}
	//vector的迭代器是随机访问迭代器，支持跳跃访问
	vector<int>::iterator itBegin = v.begin();
	itBegin += 3;
	//小技巧：
	//通过迭代器+num判断是否支持跳跃访问

	cout << *itBegin << endl;//40

	//erase(const_iterator pos);//删除迭代器指向的元素
	v.erase(v.begin() + 3);
	printVector(v);

#if 0
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	list<int>::iterator itBegin = l.begin();
	//支持双向访问
	itBegin++;
	itBegin--;
	//itBegin = itBegin + 3;//list迭代器是不支持随机访问的，报错
#endif 
}

int main()
{
	//test6();
	//test7();
	test8();
	return 0;
}