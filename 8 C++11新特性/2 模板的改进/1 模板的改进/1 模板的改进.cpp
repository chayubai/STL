#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��C++98/03�ķ��ͱ���У�ģ��ʵ������һ���ܷ����ĵط����������������Ҽ�����(>>)�ᱻ������ͳ����Ʋ�������
//������ģ����������ʽ����Ҫһ���ո���зָ�Ա��ⷢ������ʱ�Ĵ���
template<int i> class X {};
template<class T> class Y {};
void test1()
{
	Y<X<10>> obj1;//qt�£�C++11֮ǰ����֧������д����2���Ҽ�����֮������пո�
}

#include <type_traits>
//ͨ��tyedef��һ������������������½�����
typedef int m_int;
using my_int = int;//C++11��ʽ������ȡ����
void test2()
{
	//is_same��ģ�壬�еĳ�Աvalue�����ж�2�������Ƿ�һ�£�����Ƿ����棬���򷵻ؼ�
	cout << is_same<m_int,my_int>::value << endl;
}

//1����ͨ������Ĭ�ϲ���
void func(int a = 3) {}

//2����ģ��֧��Ĭ�ϲ�����ģ�����
template<class T=int> class A {};

//3��C++11��֧�֣�����ģ���Ĭ�ϵ�ģ�����
template<class T = int> void func2(T a) {}

//4����ģ���Ĭ�ϲ��������Ǵ������󡣵�����ģ��û��Ҫ��
//template<class T1 = int, class T2> class B {};//err
template<class T1, class T2 = int> class B {};
template<class T1 = int, class T2> void func3(T1 a,T2 b) {}

int main()
{

	return 0;
}