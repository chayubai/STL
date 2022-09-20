#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//继承方式递归方式展开可变参数模板类
//1、递归继承模板类
//2、边界结束条件
//3、可变参数模板声明

#include <typeinfo>

//3、可变参数模板声明
template<class ...T> class Car {};

//1、递归继承模板类
template<class Head,class...Tail>
class Car <Head, Tail...> :public Car<Tail...>//递归继承本身
{//当实例化对象时，则会引起基类的递归构造
public:
	Car()
	{
		cout << "type = " << typeid(Head).name() << endl;
	}
};
//2、边界结束条件
template<> class Car<> {};
int main()
{
	Car<int,char*,double> bmw;
	/*
	Car<int,char*,double> bmw;
	Car<char*,double>
	Car<double>
	Car<>
	*/
	return 0;
}