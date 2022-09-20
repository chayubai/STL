#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//在C++98/03的泛型编程中，模板实例化有一个很繁琐的地方，就是连续两个右尖括号(>>)会被编译解释成右移操作符，
//而不是模板参数表的形式，需要一个空格进行分割，以避免发生编译时的错误。
template<int i> class X {};
template<class T> class Y {};
void test1()
{
	Y<X<10>> obj1;//qt下，C++11之前，不支持这种写法，2个右尖括号之间必须有空格
}

#include <type_traits>
//通过tyedef给一个类型起别名，不能新建类型
typedef int m_int;
using my_int = int;//C++11方式，类型取别名
void test2()
{
	//is_same类模板，中的成员value可以判断2个类型是否一致，如果是返回真，否则返回假
	cout << is_same<m_int,my_int>::value << endl;
}

//1、普通函数的默认参数
void func(int a = 3) {}

//2、类模板支持默认参数的模板参数
template<class T=int> class A {};

//3、C++11才支持，函数模板带默认的模板参数
template<class T = int> void func2(T a) {}

//4、类模板的默认参数必须是从右往左。但函数模板没有要求
//template<class T1 = int, class T2> class B {};//err
template<class T1, class T2 = int> class B {};
template<class T1 = int, class T2> void func3(T1 a,T2 b) {}

int main()
{

	return 0;
}