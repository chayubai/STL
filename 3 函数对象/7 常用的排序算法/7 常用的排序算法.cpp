#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#if 0
/*
	merge�㷨 ����Ԫ�غϲ������洢����һ������
	ע�⣺������������������ģ�����������˳��Ҫһ�£������������Ͳ���ͬ����
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
//�㷨˼�룺���������������У�ȡС�߷�������������У�����һ������Ϊ�գ�ʣ�����һ�������е�Ԫ��ȫ�����������������
*/
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
#endif
void test11()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());//ע�⣺���յ���������ֱ�ӷ����ݣ��ᱨ��
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

void test12()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());

	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());//ע�⣺���յ���������ֱ�ӷ����ݣ��ᱨ��

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin(), greater<int>());
	//ע�⣺mergeĬ��Ҳ�Ǵ�С���󣬵����������ǴӴ�С��mergeҲҪָ���Ӵ�С
	//���򣬱����ͨ�����������лᱨ��
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}
#if 0
/*
	sort�㷨 ����Ԫ������
	@param beg ����1��ʼ������
	@param end ����1����������
	@param _callback �ص���������ν��(����bool���͵ĺ�������)
*/
sort(iterator beg, iterator end, _callback)
#endif
#include <functional>
void test2()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//��������
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

#if 0
/*
	random_shuffle�㷨 ��ָ����Χ�ڵ�Ԫ�������������
	@param beg ������ʼ������
	@param end ��������������
*/
random_shuffle(iterator beg, iterator end)
#endif
#include <ctime>
void test3()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());//ע��Ҳ��Ҫ��srand()������Ҳ��α���
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}
//Ӧ�ó�����ϴ�ƣ���ǩ

#if 0
/*
	reverse�㷨 ��תָ����Χ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
*/
reverse(iterator beg, iterator end)
#endif
void test4()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(0);
	v.push_back(30);
	v.push_back(20);
	//ע�⣺����ķ�ת������

	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	reverse(v.begin(), v.end());

	cout << "��ת��" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

//ע�⣺sort��random_shuffle()�������ڲ�֧��������ʵ�������ʹ�ûᱨ��
//����sort�ṩ��Ա������random_shuffle���ṩ��Ա�����������Ҫʹ����Ҫ�Լ�д
//����reverse֧�ֲ���������ʵ�����
#include <list>
void test5()
{
	vector<int> v1;
	list<int> l2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		l2.push_back(i + 1);
	}
	sort(v1.begin(), v1.end(), greater<int>());
	//sort(l2.begin(), l2.end(), greater<int>());//����
	l2.sort(greater<int>());//����ʹ���Դ��ĳ�Ա����sort

	vector<int> vTarget;
	vTarget.resize(v1.size() + l2.size());//ע�⣺���յ���������ֱ�ӷ����ݣ��ᱨ��

	merge(v1.begin(), v1.end(), l2.begin(), l2.end(), vTarget.begin(), greater<int>());
	//ע�⣺mergeĬ��Ҳ�Ǵ�С���󣬵����������ǴӴ�С��mergeҲҪָ���Ӵ�С
	//���򣬱����ͨ�����������лᱨ��
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
}

void test6()
{
	list<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//random_shuffle(v.begin(), v.end());//list��֧��������ʣ�ʹ��random_shuffle����
	//�����ơ� + ��:��std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<_Ty>>>����������������Ԥ����������ɽ��յ����͵�ת��
	//v.random_shuffle();//����list����û�г�Ա����random_shuffle
	//�����Ҫʹ�ã���Ҫ�Լ�д
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

void test7()
{
	list<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(0);
	v.push_back(30);
	v.push_back(20);
	//ע�⣺����ķ�ת������

	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	reverse(v.begin(), v.end());

	cout << "��ת��" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

int main()
{
	srand((unsigned int)time(NULL));
	
	//test11();
	//test12();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}

//���ɣ���ʹ��STL�еĺ���������ͨ��ת������鿴����Դ��Ĳ����ͷ�������