#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>

//2��vs2019��֧�֣������β���auto��������qt����
//void func(auto a){}

struct Test2
{
	int a;
	//3��auto����������Ϊ�Զ������͵ĳ�Ա����
	//auto b = 10;
};

void test()
{
	//1��auto�������ʱ�������ʼ��

	//auto a;//�޷��Ƶ�����
	//a = 10;

	//4��������auto����
	//auto b[3] = { 1,2,3 };

	//5��ģ��ʵ�������Ͳ�����auto����
	vector<int> a;
	//vector<auto> b;
	//vector<auto> b = { 1 };
}
int main()
{
	return 0;
}