#define _CRT_SECURE_NO_WARNINGS 1
/*
lambda���ʽ��������C++11�б���Ϊ���հ����͡���ÿһ��lambda���ʽ������һ����ʱ����(��ֵ)��
��ˣ��ϸ�ؽ���lambda�������Ǻ���ָ�롣

����C++11��׼ȴ����lambda���ʽ����ָ���ת����
����ǰ��lambda����û�в����κα������Һ���ָ����ʾ�ĺ���ԭ�ͣ������lambda��������������ͬ�ĵ��÷�ʽ��

*/

#include <iostream>
using namespace std;

#include <functional>

int main()
{
	function<void(int)> f1 = [](int a) {cout << a << endl; };
	f1(11);

	function<int(int)> f2 = [](int a) {return a+1; };
	cout << f2(9) << endl;

	function<int(int)> f3 = bind(
		[](int a) {return a + 1; }, std::placeholders::_1);
	cout << f3(9) << endl;

	auto f4 = [](int x, int y)->int {return x + y; };
	cout << f4(1, 2) << endl;

	decltype(f4) tmp = f4;
	cout << tmp(2, 2) << endl;

	//����һ������ָ��
	//ע�⺯��ָ�������int (int, int)��lambda���ʽ����(int x, int y)->int һ�£�
	typedef int (*PFUNC) (int, int);
	PFUNC p1 = f4;//lambda���ʽת��Ϊ����ָ�룬������[]�����ⲿ����(���Բ��񣬵��ǲ����ں�������ʹ��)
	cout << p1(10, 20) << endl;
	//int a = 10;
	//auto f4 = [=](int x, int y)->int {cout << a << endl; return x + y; };
	//PFUNC p1 = f4;//err

	//decltype(f4) tmp2 = p1;//����ָ��ת��Ϊlambda���ʽ���ǲ����Եģ�err
	return 0;
}