#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
void Print(T tmp)
{
	cout << tmp << endl;
}
//������չ������
template<class...T>
void expand(T...args)
{
	//���������
	//��ʼ���б�
	int a[] = { (Print(args),0)... };
}

int main()
{
	expand(1, 2, 3, 4);
	/*
	expand�����Ķ��ű��ʽ��(print(args), 0)�� 
	Ҳ�ǰ������ִ��˳����ִ��print(args)���ٵõ����ű��ʽ�Ľ��0��
	ͬʱ��ͨ����ʼ���б�����ʼ��һ���䳤���飬
	{ (print(args), 0)... }����չ����( (print(args1), 0), (print(args2), 0), (print(args3), 0), etc...), 
	���ջᴴ��һ��Ԫ��ֻ��Ϊ0������int a[sizeof...(args)]��
	*/
	return 0;
}