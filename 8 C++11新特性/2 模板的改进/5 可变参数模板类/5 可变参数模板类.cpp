#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�̳з�ʽ�ݹ鷽ʽչ���ɱ����ģ����
//1���ݹ�̳�ģ����
//2���߽��������
//3���ɱ����ģ������

#include <typeinfo>

//3���ɱ����ģ������
template<class ...T> class Car {};

//1���ݹ�̳�ģ����
template<class Head,class...Tail>
class Car <Head, Tail...> :public Car<Tail...>//�ݹ�̳б���
{//��ʵ��������ʱ������������ĵݹ鹹��
public:
	Car()
	{
		cout << "type = " << typeid(Head).name() << endl;
	}
};
//2���߽��������
template<> class Car<> {};
int main()
{
	Car<int,char*,double> bmw;
	/*
	Car<int,char*,double> bmw;
	Car<char*,double>
	Car<double>
	Car<>
	*/
	return 0;
}