#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

//A���ϣ�0 1 2 3 4 5 6 7 8 9
//B���ϣ�5 6 7 8 9 10 11 12 13 14
//�����ȥ�ཻ���ֵ�Ԫ�أ���һ��������ʣ���Ԫ��
//A��B�Ĳ��0 1 2 3 4
//B��A�Ĳ��10 11 12 13 14

#if 0
/*
	set_intersection�㷨 ������set���ϵĽ���
	ע��:�������ϱ�������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test1()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//����������С����Ľ����ȡ����С���Ǹ�
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	
	//ע�⣺����ʱ��������������itEnd
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
}
#if 0
/*
	set_union�㷨 ������set���ϵĲ���
	ע��:�������ϱ�������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test2()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//����������С����Ľ����ȡ������֮��
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	//ע�⣺����ʱ������������itEnd
	//���дvTarget.end()����Ὣ������Ϊ0��ȫ����ӡ����
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
}

#if 0
/*
	set_difference�㷨 ������set���ϵĲ
	ע��:�������ϱ�������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test3()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//����������С����Ľ����ȡ�����������Ǹ�
	vTarget.resize(max(v1.size(), v2.size()));

	//A �� B�Ĳ 
	cout << "A �� B�Ĳ ��" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	//ע�⣺����ʱ������������itEnd
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
	cout << endl;

	//B �� A�Ĳ 
	cout << "B �� A�Ĳ ��" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

	//ע�⣺����ʱ������������itEnd
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
}

int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}