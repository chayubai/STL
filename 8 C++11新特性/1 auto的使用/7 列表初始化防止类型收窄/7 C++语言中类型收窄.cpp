#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 1024;
	char b = { a };//������խ���޷�����ͨ���������ӡ�int��ת������char����Ҫ����ת��

	cout << "b = " << b << endl;
	//���ʹ���б��ʼ�������Է�ֹ��������խ

	return 0;
}

//ע�⣺���������еı����������ֹ������խ��qt���Ա���ͨ��