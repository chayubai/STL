#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//������ �������ܣ���ָ�����
//ԭ��ָ��Ҳ��һ�ֵ�����
void test1()
{
	int arr[5] = { 1,2,3,4,5 };
	
	int* p = arr;//ָ��ָ�������׵�ַ��&array[0]
	for (int i = 0; i < 5; i++)
	{
		//cout << arr[i] << endl;
		cout << *(p++) << endl;
	}
}

#include <vector>
#include <algorithm>

void myPrint(int val)
{
	cout << val << endl;
}
void test2()
{
	//����
	vector<int> v;//vector��̬���飬����һ��vector����v�������д��Ԫ��������int���ͣ�ʹ��������Ҫ����ͷ�ļ�#include<vector>
	
	//myArray<int> arr;

	//����v�в���Ԫ��
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//�㷨ͨ�����������ܷ��������е�Ԫ�ء�
	//��������v�е�Ԫ�أ�ʹ�õ�����
	
	//������ʹ�÷ǳ�������ָ�룬��ѧ�׶����ǿ�������������Ϊָ��

	//��Ҫ�������򣬱�ʾʹ�þ�����ģ���������µĵ���������ÿ�����������Լ�ר���ĵ�����
	vector<int>::iterator itBegin = v.begin();//v.begin()��ʼ��������(ָ��)ָ�������е�һ������

	vector<int>::iterator itEnd = v.end();//v.end()������������(ָ��)ָ�����������һ��Ԫ�ص���һ��λ��

	//��һ�ֱ���
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//�ڶ��ֱ���
	//vector<int>::iterator����������
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it��ʾ��������<int>
		cout << *it << endl;
	}

	//�����ֱ���
	for_each(v.begin(), v.end(), myPrint);//_Func�ص�������ʹ�ñ�׼�㷨����Ҫ����ͷ�ļ�#include <algorithm>
	
	//for_each()��Դ�룺
	/*
	template <class _InIt, class _Fn>
	_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) 
	{ // perform function for each element [_First, _Last)
    
		_Adl_verify_range(_First, _Last);
		auto _UFirst      = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);

		for (; _UFirst != _ULast; ++_UFirst) //for (; _First != _Last; ++_First) for (; it != v.end(); it++)
		{
			_Func(*_UFirst);//_Func(*_First)�ص�������ͨ��*_First�ҵ�Ԫ�أ�����myPrint��val
		}

		return _Func;
	}
	*/
}

#include <string>
//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void PrintPerson1(Person& p)
{
	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
}
void test3()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//ÿ��������Ҫ�Լ�ר���ĵ����� vector<int>::iterator  vector<Person>::iterator
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it��ʾPerson���͵Ķ���<Person>��it�������Ϊָ��
		cout << "������" << (*it).m_Name << " ���䣺" << (*it).m_Age << endl;
		//cout << "������" << it->m_Name << " ���䣺" << it->m_Age << endl;
	}

	for_each(v.begin(), v.end(), PrintPerson1);//_Func(*_First)�ص�������ͨ��*_First�ҵ�Person���󣬴���PrintPerson1��p
}

void PrintPerson2(Person*& p)
{
	cout << "������" << p->m_Name << " ���䣺" << p->m_Age << endl;
}
//����Զ����������͵�ָ��
void test4()
{
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it��ʾPerson���͵Ķ����ָ��<Person*>
		cout << "������" << (*it)->m_Name << " ���䣺" << (*it)->m_Age << endl;
	}

	for_each(v.begin(), v.end(), PrintPerson2);//_Func(*_First)�ص�������ͨ��*_First�ҵ�Person*�����ָ�룬����PrintPerson2��p
}

//����Ƕ������
void test5()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++) 
	{
		v1.push_back(i + 1);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}

	//��С�������뵽��������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it��ʾvector<int>���͵�С����<vector<int>>
		for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
			cout << *vit << " ";
		cout << endl;
	}
}

int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	return 0;
}