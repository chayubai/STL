#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		cout << tmp << " ";
	}
	cout << endl;

	//���ϴ�ͳ�������ȼ��������ʹ�÷���
	for (int tmp : a)//��ÿ��ȡa[i]��ֵ������tmp
	{
		cout << tmp << " ";
	}
	cout << endl;
}

void test2()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++)
	{
		int &tmp = a[i];
		cout << tmp << " ";
	}
	cout << endl;
	
	//���ϴ�ͳ�������ȼ��������ʹ�÷���
	for (int &tmp : a)//��ÿ��ȡa[i]��ֵ����������
	{
		cout << tmp << " ";
	}
	cout << endl;
}

void test3()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		int* tmp = &a[i];
		cout << tmp << " ";
	}
	cout << endl;
	//for (int* tmp : a)//��ÿ��ȡa[i]��ֵ�����ܴ���ָ��tmp
	//{
	//	cout << tmp << " ";
	//}
	cout << endl;
}

//�β��е����鲻�����飬����ָ��������޷�ȷ��Ԫ�ظ���
//���ڷ�Χ��for�������Χ��Ҫȷ���󣬷����޷�ʹ��
void func1(int* a)
{
	//for (auto tmp : a)//a��һ��ָ�룬�޷�ȷ����Χ
	//{
	//	cout << tmp << endl;
	//}
}
void func2(int a[])
{
	//for (auto tmp : a)//int a[]��һ��ָ�룬�޷�ȷ����Χ
	//{
	//	cout << tmp << endl;
	//}
}
void func3(int a[])
{
	/*for (auto& tmp : a)//int a[]��һ��ָ�룬�޷�ȷ����Χ
	{
		cout << tmp << endl;
	}*/
}
void test4()
{
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);
	func1(a);
	func2(a);
	func3(a);
}
int main()
{
	test1();
	return 0;
}