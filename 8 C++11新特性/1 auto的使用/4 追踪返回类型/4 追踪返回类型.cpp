#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int func(int a, int b) 
{ 
	return a + b; 
}

auto func2(int a, int b)->int//指定函数的返回类型为int类型，返回类型后置
{
	return a + b;
}

auto func3(int a, double b)->decltype(a+b)//根据返回值的类型灵活指定函数的返回类型
{
	return a + b;//对于不知道返回类型是什么类型，可以使用追踪返回类型的方法
}

void test1()
{
	int a = 10;
	double b = 1.1;
	auto c = func3(10, 11.1);
	cout << "c = " << c << endl;
	//当使用auto->int时会有精度丢失，当使用auto->double时不会精度丢失
	//通过auto和decltype搭配使用，更加灵活
}

template<class T1,class T2>
auto mul(T1& t1, T2& t2)->decltype(t1* t2)//对于t1和t2，如果只是使用，而修改，可以使用const限定
{
	return t1 * t2;
}
void test2()
{
	auto i = 10;
	auto j = 11.2;
	
	auto k = mul(i, j);

	//auto q = mul(20, 30);//如果调用上面的函数模板，就会失败，T1& t1= 常量;不合法
	//解决方法：10这个数字是常量 是右值，应该改为带const的引用，即auto mul(const T1& t1,const T2& t2)，
	//或者用&&右值，做到类型匹配,即auto mul(T1&& t1,const T2&& t2)

	cout << "i * j = " << k << endl;
}
int main()
{
	
	test1();
	test2();
	return 0;
}