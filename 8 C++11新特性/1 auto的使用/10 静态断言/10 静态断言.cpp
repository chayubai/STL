#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <cassert>

void test1()
{
	bool flag = false;

	//����ʱ������������������Ϊ�棬����ִ�С��������Ϊ�٣��жϳ�����ʾ����

	//assert(flag == true);
	assert(flag == false);

	cout << "hello c++" << endl;
}

void test2()
{
	//static_assert(�����������ʽ, "��ʾ���ַ���");

	//����ʱ������������������Ϊ�棬����ִ�С��������Ϊ�٣��жϳ�����ʾ����

	//static_assert(sizeof(void*) == 8, "64λϵͳ��֧��");//ֱ�ӱ��뱨��
	static_assert(sizeof(void*) == 4, "64λϵͳ��֧��");

	cout << "hello c++" << endl;
}
int main()
{

	return 0;
}