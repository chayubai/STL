#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void func1()
{
	throw 1;//�׳��������͵��쳣
}
void func2() throw()
{
	//������������׳��κ����͵��쳣
}
void func3() noexcept
{
	//���׳��κ����͵��쳣
}

//ע�⣺noexcept�ؼ�����vs2013��֧�֣���qt�²��Կ���ͨ��
int main()
{

	return 0;
}