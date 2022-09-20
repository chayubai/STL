#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//�ɱ������ģ����� 0-n���������
template<class... T>//T��ģ�������
void func(T... args)//args�к���������
{
	//��ȡ�ɱ�����ĸ���
	cout << "num = " << sizeof...(args) << endl;
}

//�磺tupleҲ��һ���ɱ������ģ��
void test1()
{
	func(10);//�Զ��Ƶ�
	func<int>(10);
	func<int, int>(10, 20);
	func<char, const char*, int>('a', "abc", 25);
}

int main()
{
	test1();
	return 0;
}