#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void func(int a)
{
	//....
	cout << __LINE__ << endl;//��ӡ�ڼ���
}
void func(int* p)//����
{
	//....
	cout << __LINE__ << endl;//��ӡ�ڼ���
}

int main()
{
	int* p = NULL;//#define NULL 0
	int* p2 = 0;

	func(0);//8
	func(NULL);//8
	//��ֹ���������ԣ�Ӧʹ��nullptr��ָ�븳��ʼֵ

	func(nullptr);//13

	//nullptrֻ�ܸ�ָ�븳ֵ
	p = NULL;
	p2 = nullptr;
	if (p == p2)
		cout << "equal" << endl;

	//���ܸ�һ����ͨ���ͱ�������ֵnullptr
	//int tmp = nullptr;//�����޷���"nullptr"ת��Ϊ"int"

	return 0;
}