#define _CRT_SECURE_NO_WARNINGS 1
//List容器是一个带头双向循环链表。
//由于list是一个双向链表，迭代器必须能够具备前移、后移的能力，所以list容器提供的是Bidirectional Iterators.
//List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效。
//这在vector是不成立的，因为vector的插入操作可能造成记忆体重新配置，导致原有的迭代器全部失效，
//甚至List元素的删除，也只有被删除的那个元素的迭代器失效，其他迭代器不受任何影响。

//特性总结:
//采用动态存储分配 ,不会造成内存浪费和溢出
//链表执行插入和删除操作十分方便 ,修改指针即可,不需要移动大量元素
//链表灵活，由于不支持随机访问，为了保存节点和节点之间的前驱和后继，因此空间和时间额外耗费较大
//注意：自己提供了sort方法，find方法查找自定义数据类型，需要提供指定规则(回调函数/仿函数)

//不支持随机访问，这是由结构所决定的，对于list容器，底层的数据结构是(双向)链表，因此不支持随机访问

#include <iostream>
#include <list>
using namespace std;
void test()
{
	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}
	//cout << myList[0];//无法随机访问
#if 0
	//验证双向循环链表，注意：vs2013才行，高版本会将一些成员属性隐藏掉，无法访问

	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead)
		{
			node = node->_Next;
			//node = node->_Prev;
		}
	}
#endif
}

#if 0
1、list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n, elem);//构造函数将n个elem拷贝给本身。
list(const list& lst);//拷贝构造函数。
2、list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos, elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
#endif
void printList(const list<int>& l)//问：为什么const list<int> l报错？
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}

	//逆序遍历  
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
	{
		cout << *it << endl;
	}

	//list迭代器不支持随机访问，支持双向访问
	list<int>::iterator it = l.begin();
	//it = it + 1;
}
void test2()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);
	
	printList(l);//200 100 10 20 30

	l.pop_back();
	l.pop_front();
	printList(l);//10 20 30

	l.insert(l.begin(), 10000);
	printList(l);
	l.erase(l.begin());
	printList(l);//10 20 30

	l.push_back(20);
	l.push_back(20);
	printList(l);//10 20 30 20 20

	l.remove(20);
	printList(l);//10 30
}
#if 0

3、list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
4、list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list& lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
5、list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
#endif

void test3()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);

	list<int> l2;
	l2.assign(10, 100);
	printList(l2);

	l.swap(l2);
	printList(l2);

	//l[0];//不可以用[]访问list容器中的元素
	//l.at(0);//不可以用at方式访问list容器中的元素
	
	//迭代器也不支持随机访问
	list<int>::iterator it = l.begin();
	//it = it + 1;//报错
	it++;
	it--;//支持双向
}

#if 0
6、list反转排序 - 质变算法，注意：逆序是非质变算法
reverse();//反转链表，比如list包含1,3,5元素，运行此方法后，list就包含5,3,1元素。
sort(); //list排序
#endif
#include <algorithm>
bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
void test4()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);
	printList(l);
	l.reverse();
	printList(l);

	//sort(l.begin(), l.end());//sort是全局函数，这样会报错
	//如果容器的迭代器支持随机访问，可以直接使用系统提供的标准算法

	//对于不支持随机访问的迭代器的容器，不能使用系统提供的算法，但容器内(类内)部会提供对应的算法接口
	l.sort();//默认从小到大
	printList(l);

	//从大到小排序
	l.sort(myCompare);//Pred 回调函数
	printList(l);
}

#include <string>
//自定义数据类型的排序
class Person
{
public:
	Person(string name, int age,int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}

	bool operator==(const Person& p) const//这里要加const，否则编译不通过
	{
		if (m_name == p.m_name && m_age == p.m_age && m_height == p.m_height)
		{
			return true;
		}
		return false;
	}

	string m_name;
	int m_age;
	int m_height;
};
bool myComparePerson(Person& p1, Person& p2)
{
	if(p1.m_age == p2.m_age)
		return p1.m_height < p2.m_height;
	return p1.m_age > p2.m_age;
}
void test5()
{
	list<Person> l;
	Person p1("亚瑟", 14,170);
	Person p2("赵云", 19,179);
	Person p3("关羽", 22, 185);
	Person p4("妲己", 11,160);
	Person p5("孙悟空", 13,230);
	Person p6("刘备", 22,170);
	Person p7("张飞", 22,180);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	l.push_back(p7);

	//按照年龄进行降序，从大到小，如果年龄相等，按身高进行升序
	//对于自定义的数据类型，必须要指定排序规则
	//l.sort();//报错
	l.sort(myComparePerson);

	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << (*it).m_age << " 身高：" << it->m_height << endl;
	}

	l.remove(p4);//不能直接remove自定义数类型，否则会报错，需要重载==操作符
	//remove的本质是，遍历迭代器
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << (*it).m_age << " 身高：" << it->m_height << endl;
	}
#if 0
	//remove源码：
	void remove(const _Ty & _Val)
	{	//erase each element matching _val
		iterator _Val_it = end();
		for (iterator _First = begin(); _First != end(); )
			if (*_First == _Val)//如果直接l.remove(p4);需要重载==操作符，不知道如何比较自定义数据类型的变量
				if (_STD addressof(*_First) == _STD addressof(_Val))
					_Val_it = _First++;
				else
					_First = erase(_First);
			else
				++_First;
		if (_Val_it != end())
			erase(_Val_it);
	}
#endif
}

int main() 
{
	//test4();

	test5();
	return 0;
}