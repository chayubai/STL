#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//override�����ã�ȷ�������������������麯��������дʱ����������麯������ͬ��ǩ��
class A1
{
public:
	//���ǵ�һ���麯����û����д��������override���Σ�����ᱨ��
	virtual void func(int a){}
};
class A2 :public A1
{
public:
	//virtual void func() {}//�����ض��壬�����ػ����ͬ������
	virtual void func(int b) override{}
	//����д�麯���ĵط�������override�ؼ��֣�Ҫ�������д���麯���ͻ���һģһ���������޷�����ͨ��
	//�βα��������Բ�һ��
};

int main()
{
	return 0;
}