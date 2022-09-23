#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
shared_ptr允许多个该智能指针共享第“拥有”同一堆分配对象的内存，
这通过引用计数（reference counting）实现，会记录有多少个shared_ptr共同指向一个对象，
一旦最后一个这样的指针被销毁，也就是一旦某个对象的引用计数变为0，这个对象才会被自动删除。
*/
#include <memory>//智能指针包含的头文件

void test1()
{
	shared_ptr<int> sp1(new int(11));
	shared_ptr<int> sp2 = sp1;//可以调用拷贝构造，有两个对象和堆区空间绑定

	cout << "num = " << sp2.use_count() << endl;//调用成员方法，打印计数器

	//释放sp1，只是计数器-1，堆区空间没有释放
	sp1.reset();
	cout << "num = " << sp2.use_count() << endl;

	cout << *sp2 << endl;
	//cout << *sp1 << endl;//err，释放堆区空间的绑定，无法通过sp1操作堆区内存

	//释放sp2，只是计数器-1，堆区空间没有释放，只有当计数器的值为0，堆区空间就会释放
	sp2.reset();
	cout << "num = " << sp2.use_count() << endl;
}
int main()
{
	return 0;
}