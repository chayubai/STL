#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class X
{
public:

	X(){}//�޲ι���

	//X(const X&) {}//��������
	X(const X&) = delete;//��=delete���εĺ������˺���������

	//X& operator= (const X&) { return *this; }//=��ֵ��������غ���
	X& operator= (const X&) = delete;//��=delete���εĺ������˺���������

	//��ͨ����Ҳ��ʹ��=delete����
	//X(int) {}
	X(int) = delete;//��=delete���εĺ������˺���������

	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;
};

int main()
{
	X obj1;//�����޲ι���

	//X obj2 = obj1;//err���������챻����

	//obj2 = obj1;//err��=��ֵ��������غ���������

	//X obj3(10);//err

	//X* p = new X;//err

	//X* p = new X[10];//err

	return 0;
}