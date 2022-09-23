#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <memory>//智能指针包含的头文件

class Test
{
public:
	~Test()
	{
		cout << "析构" << endl;
	}
};
void test1()
{
	unique_ptr<int> up1(new int(11));//创建智能指针对象

	cout << "*up1 = " << *up1 << endl;//重载了operator*()和operator->()

	{
		unique_ptr<Test> up2(new Test);
		//无需释放，自动释放

		//人为指定释放堆区空间
		//up2 = nullptr;//方法1
		up2 = NULL;//方法2
		up2.reset();//方法3，成员方法
		//可以释放多次，不会导致段错误

		cout << "**********" << endl;
	}
	cout << "————————" << endl;
}

void test2()
{
	unique_ptr<int> up1(new int(11));//创建智能指针对象
	//unique_ptr<int> up2 = up1;//err，禁用拷贝构造

	//把up1的使用权转移给了up2，之后up1不能再操作堆区空间
	unique_ptr<int> up2 = std::move(up1);//使用移动拷贝
	cout << "*up2 = " << *up2 << endl;
	//cout << "*up1 = " << *up1 << endl;//err，非法访问，操作野指针指向的内存
}

void test3()
{
	unique_ptr<int> up1(new int(11));//创建智能指针对象
	//up1.reset();//如果是无参，作用是显式释放堆区内容

	//如果有参，先释放原来堆区内容，重新给up1绑定一个新的堆区内容
	up1.reset(new int(22));

	cout << "*up1 = " << *up1 << endl;
}

void test4()
{
	unique_ptr<int> up1(new int(11));//创建智能指针对象
	
	//释放控制权，但不释放堆区内存
	int* p = up1.release();
	cout << *p << endl;
	//cout << *up1 << endl;//err

	//此时需要手动释放
	delete p;
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}