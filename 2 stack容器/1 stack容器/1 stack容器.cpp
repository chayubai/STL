#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
using namespace std;

//Stack所有元素的进出都必须符合“先进后出”的条件，只有stack顶端的元素，才有机会被外界取用。
//Stack不提供遍历功能，也不提供迭代器。
//遍历时，搭配empty和pop函数使用

//stack容器，本质上是动态数组 注意：vector也是一个动态数组，但这两个容器提供的函数接口有所区别
//特性总结:
//栈不能遍历，不支持随机存取,只能通过top从栈顶获取和删除元素. .

#if 0
1、stack构造函数
stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式： 
stack(const stack& stk);//拷贝构造函数
2、stack赋值操作
stack & operator=(const stack & stk);//重载等号操作符
3、stack数据存取操作
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
4、stack大小操作
empty();//判断堆栈是否为空
size();//返回堆栈的大小
#endif 

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	//s[1];不支持随机访问
	cout << "size = " << s.size() << endl;
	//如果要访问非栈顶的元素，需要先pop掉栈顶的元素
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << "size = " << s.size() << endl;

	return 0;
}

//作用1 栈容器存放对象指针
//作业2 栈容器存放对象