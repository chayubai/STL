#define _CRT_SECURE_NO_WARNINGS 1

//ע�⣺��ڿν��ļ�������������ߵ�֧�ֱ�׼��C++14��ѧϰ�˿��Զ����ɴ���
//���ߵı�׼���ѱ���������ʹ�ø���ࡢͳһ��bind()�����������䡣
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyPrint:public binary_function<int,int,void>//��Ԫ�̳�
{
public:
	/*void operator()(int val)
	{
		cout << val << endl;
	}*/
	void operator()(int val,int start) const////��Ԫ ʵ���ϣ�������binary_function���()������
	{
		//cout << val + start << endl;
		cout << "val = " << val << " start = " << start << " sum = " << val + start << endl;
	}
};
//1����������������bind2nd()
//������������һ����Ԫ��������תΪһԪ��������
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//��ʽ1��
	//MyPrint print;
	//for_each(v.begin(), v.end(), print);
	//��ʽ2��
	//for_each(v.begin(), v.end(), MyPrint());//for_each�㷨�ײ�*_First == val��ֻ��һ������
	int num = 0;
	cout << "��������ʼ�ۼ�ֵ��";
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd(MyPrint(),num));//bind2nd(MyPrint(),num)��һ���ڽ�����������Ҫ����#include <functional>
	//bind2nd(MyPrint(),num)���൱���������������һ������������ײ�Դ��ֻ�ܴ���һ������ *_First = bind2nd()
	for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
	//bind1st(����1, ����2) operator()(int val,int start) ����1 == start ����2 == val
}
//1�������ڽ���������Բ������а�
//2���̳�binary_function<����1���ͣ�����2���ͣ�����ֵ����>����
//3��operator() const

//2��ȡ��������
class GreaterThanFive:public unary_function<int,bool>//һԪ�̳�
{
public:
	bool operator()(int val) const//һԪ
	{
		return val > 5;
	}
};
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThanFive());//find_if�㷨�ײ�*_First == val��ֻ��һ������
	if (pos != v.end())
		cout << "�ҵ�����5��ֵΪ��" << *pos << endl;
	else
		cout << "δ�ҵ�" << endl;

	//һԪȡ������С��5����
	//����1��operator()��return��Ϊ < 5
	//����2��not1()ȡ���ڽ���������
	pos = find_if(v.begin(), v.end(), not1(GreaterThanFive()));//find_if�㷨�ײ�*_First == val��ֻ��һ������
	if (pos != v.end())
		cout << "�ҵ�С��5��ֵΪ��" << *pos << endl;
	else
		cout << "δ�ҵ�" << endl;

	//��С��num����
	int num = 5;
	pos = find_if(v.begin(), v.end(), not1( ( bind2nd( greater<int>() ,num ) ) ) );//find_if�㷨�ײ�*_First == val��ֻ��һ������
	//bind2nd( greater<int>() ,num )���൱���������������һ������������ײ�Դ��ֻ�ܴ���һ������
	if (pos != v.end())
		cout << "�ҵ�С��5��ֵΪ��" << *pos << endl;
	else
		cout << "δ�ҵ�" << endl;

	//��Ԫȡ����
	sort(v.begin(), v.end(),not2(less<int>()));//not2(less<int>())�൱��greater<int>()
	//not1��operator()����Ϊһ������һԪν��
	//not2��operator()����Ϊ����������Ԫν��

	//ע�⣺less<int>()��greater<int>()�ڽ���������ײ�Դ���Լ��̳��˶�Ӧ���࣬��operator()����const
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
//1������not1����һԪȡ��
//2���̳�unary_function
//3��operator() const

//3������������
void myPrint3(int val,int start)//ȫ�ֺ���û��thisָ��
{
	cout << val + start<< endl;
}
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//�����Ҫ�Իص��������в����󶨣���Ҫ���ص���������ɺ�������
	//������ָ��(������) ����ɺ�������/�º�����ptr_fun
	//����û�м̳У�Ҳ���ü�const
	//
	//bind2nd
	for_each(v.begin(), v.end(),bind2nd( ptr_fun(myPrint3),100 ) );//ʹ�ûص�����
}

#include <string> 
//4����Ա����������
class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	void showPerson()
	{
		cout << "��Ա������������" << m_name << " ���䣺" << m_age << endl;
	}
	void addAge()
	{
		m_age += 10;
	}
	string m_name;
	int m_age;
};
void myPrint4(Person& p)
{
	cout << "ȫ�ֺ�����������" << p.m_name << " ���䣺" << p.m_age << endl;
}
void test4()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//����ȫ�ֺ������ص�������
	for_each(v.begin(), v.end(), myPrint4);
	
	//����mem_fun_ref�����ȫ�ֺ���
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));

	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

void test5()
{
	vector<Person*> v1;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	for_each(v1.begin(), v1.end(), mem_fun(&Person::showPerson));
}

//���������ŵ��Ƕ���ָ�룬  ��ô��mem_fun
//��������д�ŵ��Ƕ���ʵ�壬��ô��mem_fun_ref

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}