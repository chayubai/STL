#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class X
{
public:

	//X(){}//�û��Լ��ṩ���޲ι��죬�ȱ������ṩ��Ĭ�Ϲ���Ч�ʵ�

	X() = default;//�ñ������ṩһ��Ĭ�ϵĹ��캯�������Լ��ṩ���޲ι���Ч�ʸ�

	X(int i)
	{//д���вι��죬�����������ṩĬ�Ϲ���
		a = i;
	}
	int a;
};
//defaultֻ����������Ĭ���ṩ�ĳ�Ա������Ĭ�Ϲ��죬�������죬=��ֵ���������غ���������������
#if 0
class X2
{
public:

	int f() = default;//err
	X2(int a) = default;//err

};
#endif

class X3
{
public:

	X3();//��������

	X3(int i)
	{//д���вι��죬�����������ṩĬ�Ϲ���
		a = i;
	}
	int a;
};
X3::X3() = default;//default���Է�������ⲿ��������ʵ�֣�ע�⣺��Ҫ��������

int main()
{
	X obj;
	return 0;
}