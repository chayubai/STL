#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Test
{
	int a;
	int b;
	char name[50];
};
void test1()
{
	//C�����У�֧���Զ�����������
	struct Test t = { 1,2,"mike" };//�б��ʼ��

	int arr[] = { 1,2,3 };
}
void test2()
{
	//C++������֧����ͨ�����б��ʼ��
	int a = 1;
	int b = { 1 };//�б��ʼ��
	int c{ 3 };//�б��ʼ��

	int arr[]{ 1,2,3 };

}
int main()
{
	return 0;
}