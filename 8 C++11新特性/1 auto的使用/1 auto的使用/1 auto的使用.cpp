#define _CRT_SECURE_NO_WARNINGS 1
/*
1��Qt Creator - New Project - ��Qt��Ŀ - �½�һ����C++���Ե���Ŀ��
����Ŀ�ļ�.pro�����ã�CONFIG += c++11//c���Դ�д
2��Linux�նˣ�g++ xxx.cpp  -std=c++11
ע�⣺����һЩc++11�����ԣ���vs�п��ܲ��ܼ���
*/

#include <iostream>
using namespace std;

void test1()
{
	//��C�У�auto���ξֲ��������ֲ�����Ҳ��auto�������Զ����������ֲ�����ջ���Զ����ٿռ䣬�Զ�ά��
	{
		int a;//auto int a;C�����У�Ĭ�Ͼֲ�����ǰ����һ��auto�ؼ���
	}
}

double func()
{
	return 1.1;
}
class Test
{
public:
	int a;
};
void test2()
{
	//C++11, auto�����û���ʼ�������Զ��Ƶ�����

	int a = 1;
	auto b = 1;//b�����;���int
	auto c = func();//c�����;���double

	Test str;
	auto d = str;//d�����;���Test
}

#include <vector>
void test3(vector<int> &tmp)
{
	for (auto i = tmp.begin(); i != tmp.end(); i++)
	{
		//....
	}
}

int main()
{
	return 0;
}