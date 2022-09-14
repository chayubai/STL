#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
#if 0
/*
	ͷ�ļ���#include <numeric>
	accumulate�㷨 ��������Ԫ���ۼ��ܺ�
	@param beg ������ʼ������
	@param end ��������������
	@param value�������ս���Ļ����ϵ��ۼ�ֵ
	@param ����int�ܺ�
*/
accumulate(iterator beg, iterator end, value)
#endif
void test1()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//0-100���ۼƺ�
	int sum = accumulate(v.begin(), v.end(), 0);//���������� ��ʼ�ۼ�ֵ
	cout << "sum = " << sum << endl;

	sum = accumulate(v.begin(), v.end(), 1000);
	cout << "sum = " << sum << endl;
}

#if 0
/*
	ͷ�ļ���#include <numeric>
	fill�㷨 �����������Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param value t���Ԫ��
*/
fill(iterator beg, iterator end, value)
#endif
void test2()
{
	vector<int> v;
	v.resize(10);//ע�⣺�����Ҫ��һ�У����ᱨ��������ӡ���

	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

int main()
{
	//test1();
	test2();
	
	return 0;
}