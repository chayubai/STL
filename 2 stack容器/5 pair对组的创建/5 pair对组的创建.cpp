#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//���飺������ֵ�ϲ�Ϊһ��ֵ���ɶԳ��ֵ����ݣ����ö�����Է�����������
//ͨ�����鴴�����󣬶������а���������Ա����first��second
void test1()
{
	//��������
	pair<string, int> p("Tom", 10);//ʹ��pair����Ҫͷ�ļ�

	cout << "������" << p.first << " ���䣺" << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 18);

	cout << "������" << p2.first << " ���䣺" << p2.second << endl;

	//pair=��ֵ
	pair<string, int> p3 = p2;
	cout << p3.first << endl;
	cout << p3.second << endl;
}

int main()
{
	test1();
	return 0;
}