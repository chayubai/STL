#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//lambda ���ʽ��һ����������
//C++11�е�lambda���ʽ���ڶ��岢���������ĺ�������
/*
	lambda���ʽ�Ļ������ɣ�
	[]() mutable exception -> int
	{
		//������
	}

	[] ��ʶһ��lambda�Ŀ�ʼ���ⲿ�ֱ�����ڣ�����ʡ�ԡ����ڲ�������ı���
	() �����������û�в���������ʡ��


	->int ָ������ֵ���ͣ�����ʡ�ԣ���Ϊ����ͨ����������ֵ�Զ��Ƶ�����ֵ����
	mutable�ؼ��֣���ʾ����mutable���ε�constֵ�����޸�

*/

int tmp = 10;
class Test
{
public:
	void func()
	{
		int a = 100;//�ֲ�����

		//[]Ϊ�գ�û�в����κα���
		//auto f1 = []() { cout << i << endl; };//err
		auto f1 = [=]() { cout << i << endl; };
		auto f2 = [&]() { cout << i << endl; };

		//�������Ա������ȫ�ֱ���
		auto f3 = [this]() { 
			cout << i << endl;
			cout << tmp << endl;
			//cout << a << endl;//�����Բ���ֲ�����
		};
	}
	int i = 0;
};
int main()
{
	int a = 0;
	int b = 1;
	int c = 2;

	auto f1 = []() {};//��ʱ���f1Ϊ����ָ��

	//a��b��ֵ���ݷ�ʽ���ں�������ʹ��
	auto f2 = [a, b]() { cout << a << " " << b << endl; };
	f2();

	//[]������ǲ�������ı�����x��y���ǲ���
	auto f3 = [a, b](int x, int y) {
		cout << a << " " << b << endl;
		cout << x << " " << y << endl;
	};
	f3(10, 20);

	//����ı���ȫ����ֵ���ݵķ�ʽ���ں�������ʹ��
	auto f4 = [=] { cout << a << " " << b << endl; };
	f4();

	//����ı���ȫ�������ô��ݵķ�ʽ���ں�������ʹ��
	auto f5 = [&] { cout << a << " " << b << endl; };

	//a��ֵ���ݵķ�ʽ�����������ô��ݵķ�ʽ���ں�������ʹ��
	//ע�⣺[&, a]˳���ܷ���
	auto f6 = [&, a] { cout << a << " " << b << endl; };

	//a�����ô��ݵķ�ʽ��������ֵ���ݵķ�ʽ���ں�������ʹ��
	//ע�⣺[=, &a]˳���ܷ���
	auto f7 = [=, &a] { cout << a << " " << b << endl; };

	//Ĭ������£�lambda��������const���κ����壬����������ʹ�ò��񵽵ı���ʱֻ�ܶ����ܸ�
	//ֵ�����޷��޸ģ����޸ļ�mutable
	//auto f8 = [=]() { a++; };
	auto f8 = [=]() mutable { a++; };

	//ע�⣺[]����ı����ǵ�ǰ���������������µı�������ȫ�ֱ���
	//auto f9 = [=]() mutable { cout << i << " " << tmp << endl;};//err


	return 0;
}