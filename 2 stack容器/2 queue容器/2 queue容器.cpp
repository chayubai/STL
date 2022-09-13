#define _CRT_SECURE_NO_WARNINGS 1
//Queue所有元素的进出都必须符合”先进先出”的条件，只有queue的顶端元素，才有机会被外界取用。
//Queue不提供遍历功能，也不提供迭代器。

//queue容器本质上是单链表
//队头-出队 队尾-入队
//特性总结：
//不支持遍历，不提供迭代器，不支持随机访问
//遍历时，搭配empty和pop函数使用


#include <iostream>
#include <queue>
using namespace std;

#if 0
1、queue构造函数
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue& que);//拷贝构造函数
2、queue存取、插入和删除操作
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素
3、queue赋值操作
queue & operator=(const queue & que);//重载等号操作符
4、queue大小操作
empty();//判断队列是否为空
size();//返回队列的大小
#endif

#include <string>

class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
int main()
{
	queue<int> m;
	m.push(1);
	m.push(2);
	//m[1];不支持随机访问

	queue<Person> q;
	Person p1("01", 15);
	Person p2("02", 17);
	Person p3("03", 18);
	Person p4("04", 16);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "size = " << q.size() << endl;
	//如果要访问非队头的元素，需要先pop掉队头的元素
	while (!q.empty())
	{
		cout << "队头：姓名 " << q.front().m_name << " 年龄 " << q.front().m_age << endl;
		cout << "队尾：姓名 " << q.back().m_name << " 年龄 " << q.back().m_age << endl;
		
		q.pop();
	}
	cout << "size = " << q.size() << endl;

	return 0;
}

//作业1 queue容器存放对象指针
//作业2 queue容器存放stack容器