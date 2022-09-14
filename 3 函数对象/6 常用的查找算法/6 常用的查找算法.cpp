#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#if 0
/*
	find�㷨 ����Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param value ���ҵ�Ԫ��
	@return ���ز���Ԫ�ص�λ��
*/
find(iterator beg, iterator end, value)
#endif
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
		cout << "�ҵ���Ԫ��" << *pos << endl;
	else
		cout << "δ�ҵ�" << endl;
}

#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	/*bool operator==(Person& p)//������Ԫ�� == ��: û���ҵ����ܡ�const _Ty�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)
	{
		return m_name == p.m_name && m_age == p.m_age;
	}*/
	bool operator==(const Person& p)//�ײ�Դ������Ա��� const _Ty & _Val
	{
		return m_name == p.m_name && m_age == p.m_age;
	}
	string m_name;
	int m_age;
};
void test2()
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

	Person p5("bbb", 10);
	vector<Person>::iterator pos = find(v.begin(), v.end(), p5);//find�ײ�Դ��Ҳ��==�Ƚϣ������Զ����������Ͳ�֪����ô�Ƚϣ���Ҫ����==��
	if (pos != v.end())
		cout << "�ҵ���Ԫ�� ������" << pos->m_name << " ���䣺" << pos->m_age << endl;
	else
		cout << "δ�ҵ�" << endl;
#if 0
	//findԴ�룺
	template <class _InIt, class _Ty>
	_NODISCARD _CONSTEXPR20 _InIt _Find_unchecked(const _InIt _First, const _InIt _Last, const _Ty & _Val) {
		// find first matching _Val; choose optimization
		// activate optimization for contiguous iterators to (const) bytes and integral values
		return _Find_unchecked1(_First, _Last, _Val, bool_constant<_Memchr_in_find_is_safe<_InIt, _Ty>>{});
	}

	template <class _InIt, class _Ty>
	_NODISCARD _CONSTEXPR20 _InIt find(_InIt _First, const _InIt _Last, const _Ty & _Val) { // find first matching _Val
		_Adl_verify_range(_First, _Last);
		_Seek_wrapped(_First, _Find_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Val));
		return _First;
}
	template <class _InIt, cl ass _Ty>
	_NODISCARD constexpr _InIt _Find_unchecked1(_InIt _First, const _InIt _Last, const _Ty & _Val, false_type) {
		// find first matching _Val
		for (; _First != _Last; ++_First) {
			if (*_First == _Val) {//find�ײ�Դ��Ҳ��==�Ƚϣ������Զ����������Ͳ�֪����ô�Ƚϣ���Ҫ����==��
				break;				//*_First == p ����p5�Ƚϣ�����==����������
			}
		}

		return _First;
	}
#endif
}

#if 0
/*
	find_if�㷨 ��������
	@param beg ������ʼ������
	@param end ��������������
	@param  callback �ص���������ν��(����bool���͵ĺ�������)
	@return ���ص�һ�����������ĵ�������λ��
*/
find_if(iterator beg, iterator end, _callback);
#endif
#include <functional>
class MyComparePerson : public binary_function<Person*, Person* ,bool>
{
public:
	bool operator()(Person *p1,Person* p2) const//ע�⣺������Person*Ԫ�أ��ȽϵĲ���ҲӦ����Person*
	{
		return p1->m_name == p2->m_name && p1->m_age == p2->m_age;
	}
};
void test3()
{
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	//ָ�����Ƚ���û�������
	Person* p = new Person("bbb", 20);
	//find_if(v.begin(), v.end(), p)//��������ʹ��

	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyComparePerson(),p));//*_Fist == p1
	if (pos != v.end())
		cout << "�ҵ���Ԫ�� ������" << (*pos)->m_name << " ���䣺" << (*pos)->m_age << endl;
	else
		cout << "δ�ҵ�" << endl;
}

#if 0
/*
	adjacent_find�㷨 ���������ظ�Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param  _callback �ص���������ν��(����bool���͵ĺ�������)
	@return ��������Ԫ�صĵ�һ��λ�õĵ�����
*/
adjacent_find(iterator beg, iterator end, _callback);
#endif
void test4()
{
	vector<int> v;

	v.push_back(3);
	v.push_back(2);
	v.push_back(30);
	v.push_back(30);
	v.push_back(6);
	v.push_back(3);

	vector<int>::iterator ret = adjacent_find(v.begin(), v.end());//���ص�һ������Ԫ�ص�ָ��
	//_FwdIt adjacent_find(const _FwdIt _First, const _FwdIt _Last)
	//����_First���ͣ���֪_FwdItΪ����������
	if (ret != v.end())
		cout << "�ҵ������ڵ��ظ�Ԫ�أ�" << *ret << endl;
	else
		cout << "δ�ҵ�" << endl;
}

#if 0
/*
	binary_search�㷨 ���ֲ��ҷ�
	ע��: �����������в�����
	@param beg ������ʼ������
	@param end ��������������
	@param value ���ҵ�Ԫ��
	@return bool ���ҷ���true ����false
*/
bool binary_search(iterator beg, iterator end, value);
#endif
void test5()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
		cout << "�ҵ�������2"<< endl;
	else
		cout << "δ�ҵ�����2" << endl;
}

#if 0
/*
	count�㷨 ͳ��Ԫ�س��ִ���
	@param beg ������ʼ������
	@param end ��������������
	@param  value�ص���������ν��(����bool���͵ĺ�������)
	@return int����Ԫ�ظ���
*/
count(iterator beg, iterator end, value);
/*
	count_if�㷨 ͳ��Ԫ�س��ִ���
	@param beg ������ʼ������
	@param end ��������������
	@param  callback �ص���������ν��(����bool���͵ĺ�������)
	@return int����Ԫ�ظ���
*/
count_if(iterator beg, iterator end, _callback);
#endif
class GreaterThan3
{
public:
	bool operator()(int val)
	{
		return val >= 3;
	}
};
void test6()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 3);
	cout << "3�ĸ���Ϊ��" << num << endl;

	//ͳ�ƴ��ڵ���3�ĸ���
	num = count_if(v.begin(), v.end(), GreaterThan3());
	//0 1 2 3 4 5 6 7 8 9 3 3 3 
	cout << "���ڵ���3�ĸ���Ϊ��" << num << endl;
}

//�Զ�����������
class Person2
{
public:
	Person2(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person2& p)//������Ԫ�� == ��: û���ҵ����ܡ�const _Ty�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)
		//���صײ�Դ����Ҫ�ϸ���Ʊ������ͣ����ﲻ��const���β���p���ᱨ��
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test7()
{
	vector<Person2> v;

	Person2 p1("����", 35);
	Person2 p2("����", 35);
	Person2 p3("�ŷ�", 35);
	Person2 p4("����", 30);
	Person2 p5("�ܲ�", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person2 p("�����", 35);

	int num = count(v.begin(), v.end(), p);//count�ײ�Դ��Ҳ��==�Ƚϣ������Զ����������Ͳ�֪����ô�Ƚϣ���Ҫ����==��
	cout << "num = " << num << endl;
}
class AgeLess35
{
public:
	bool operator()(const Person2& p)
	{
		return p.m_Age < 35;
	}
};
void test8()
{
	vector<Person2> v;

	Person2 p1("����", 35);
	Person2 p2("����", 35);
	Person2 p3("�ŷ�", 35);
	Person2 p4("����", 30);
	Person2 p5("�ܲ�", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "С��35��ĸ�����" << num << endl;
}

int main()
{
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	test8();
	return 0;
}

//���ɣ���ʹ��STL�еĺ���������ͨ��ת������鿴����Դ��Ĳ����ͷ�������