#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	int a = 10;

	//��ֵ���ݷ�ʽ�����ں�������ʹ�ã��������ڵı����Ǻ������һ����ʱ����
	auto f1 = [=]() mutable
	{
		//a = 111;
		cout << "lambda::a = " << a << endl;
	};

	f1();//û��ע��a = 111;

	cout << "main::a = " << a << endl;

	a = 222;
	f1();//ע��a = 111;
}

void test2()
{
	int b = 10;

	//�����ô��ݷ�ʽ�����ں�������ʹ�ã��������ڵı����Ǻ������ͬһ������
	auto f1 = [&]()
	{
		//b = 111;
		cout << "lambda::b = " << b << endl;
	};

	f1();//û��ע��a = 111;

	cout << "main::b = " << b << endl;

	b = 222;
	f1();//ע��b = 111;
}
int main()
{
	test1();
	test2();

	return 0;
}
