#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int func(int a, int b) 
{ 
	return a + b; 
}

auto func2(int a, int b)->int//ָ�������ķ�������Ϊint���ͣ��������ͺ���
{
	return a + b;
}

auto func3(int a, double b)->decltype(a+b)//���ݷ���ֵ���������ָ�������ķ�������
{
	return a + b;//���ڲ�֪������������ʲô���ͣ�����ʹ��׷�ٷ������͵ķ���
}

void test1()
{
	int a = 10;
	double b = 1.1;
	auto c = func3(10, 11.1);
	cout << "c = " << c << endl;
	//��ʹ��auto->intʱ���о��ȶ�ʧ����ʹ��auto->doubleʱ���ᾫ�ȶ�ʧ
	//ͨ��auto��decltype����ʹ�ã��������
}

template<class T1,class T2>
auto mul(T1& t1, T2& t2)->decltype(t1* t2)//����t1��t2�����ֻ��ʹ�ã����޸ģ�����ʹ��const�޶�
{
	return t1 * t2;
}
void test2()
{
	auto i = 10;
	auto j = 11.2;
	
	auto k = mul(i, j);

	//auto q = mul(20, 30);//�����������ĺ���ģ�壬�ͻ�ʧ�ܣ�T1& t1= ����;���Ϸ�
	//���������10��������ǳ��� ����ֵ��Ӧ�ø�Ϊ��const�����ã���auto mul(const T1& t1,const T2& t2)��
	//������&&��ֵ����������ƥ��,��auto mul(T1&& t1,const T2&& t2)

	cout << "i * j = " << k << endl;
}
int main()
{
	
	test1();
	test2();
	return 0;
}