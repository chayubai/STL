#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//�̳п��ƹؼ��֣�final override
//final�����ã���ֹ���һ���������麯���Ľ�һ����д

#if 0
class A1 final//����final�ؼ��ֺ�ָ��A1�಻�������������ܱ��̳�
{
public:
	int a;
};
class A2 :public A1//err�����಻��������
{
public:

};
#endif

class B1
{
public:
	virtual void func() final{}//final���հ汾���麯������������д
};
//��������д������麯��
class B2 :public B1
{
public:
	//virtual void func() {}//err�������е��麯�������հ汾����������д
};

int main()
{
	return 0;
}