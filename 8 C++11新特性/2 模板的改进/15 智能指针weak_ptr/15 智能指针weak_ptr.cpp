#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <memory>//智能指针包含的头文件

void test1()
{
	shared_ptr<int> sp1(new int(11));
	shared_ptr<int> sp2 = sp1;//可以调用拷贝构造，有两个对象和堆区空间绑定

	weak_ptr<int> wp = sp1;
	cout << "num = " << sp1.use_count() << endl;//调用成员方法，打印计数器
	cout << "num = " << wp.use_count() << endl;//调用成员方法，打印计数器

	//weak_ptr虽然不和堆区空间绑定，但可以通过成员方法lock函数获取shared_ptr<T>对象
	shared_ptr<int> sp3 = wp.lock();//有3个对象绑定堆区空间
	cout << "num = " << sp1.use_count() << endl;//调用成员方法，打印计数器
	cout << "num = " << wp.use_count() << endl;//调用成员方法，打印计数器

	cout << *sp1 << " , " << *sp2 << " , " << *sp3 << endl;
	//cout << *wp << endl;//err, 没有重载 * 和 -> 但可以使用lock获得一个可用的shared_ptr对象

	sp1.reset();
	sp2.reset(); 
	sp3.reset();

	cout << "num = " << sp1.use_count() << endl;//调用成员方法，打印计数器
	cout << "num = " << wp.use_count() << endl;//调用成员方法，打印计数器

	//当堆区空间释放后，wp.lock()获取的的返回值为空
	shared_ptr<int> tmp = wp.lock();
	if (tmp == nullptr)
	{
		cout << "堆区空间已经释放" << endl;
	}
}
int main()
{
	return 0;
}