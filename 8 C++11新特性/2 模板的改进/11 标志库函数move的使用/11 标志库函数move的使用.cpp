#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 10;//aΪ��ֵ

	//int && b = a;//err ��ֵ���ܰ󶨵���ֵ����

	int&& c = std::move(a);//std::move(a)��һ����ֵת��Ϊ��ֵ
	
	//ע�⣺����ʹ���������ռ�std����ֱ��ʹ��move

	cout << "c = " << c << endl;
	return 0;
}