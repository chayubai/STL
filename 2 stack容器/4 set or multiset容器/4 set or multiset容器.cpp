#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
using namespace std;
//Set������ʽ�������������ǡ�����Ԫ�ض������Ԫ�ص� ��ֵ �Զ�������
//Set��Ԫ�ز���map��������ͬʱӵ��ʵֵ�ͼ�ֵ��set��Ԫ�ؼ��Ǽ�ֵ��
//Set����������Ԫ������ͬ�ļ�ֵ��
//ע�⣺�Զ�������������ΪԪ�ؼ�key����Ҫָ���������

//ע�⣺ʵֵ��valueֵ����ֵ��keyֵ��set��multisetֻ�м�ֵ
//set��iterator��һ��ֻ��iterator.

//multiset���Լ��÷���set��ȫ��ͬ��Ψһ�Ĳ�������������ֵ�ظ���
//set��multiset�ĵײ�ʵ���Ǻ�����������Ϊƽ��������������һ�֡�

//���ǿ���ͨ��set�ĵ������ı�setԪ�ص�ֵ��
//���У���ΪsetԪ��ֵ�������ֵ����ϵ��setԪ�ص��������
//�������ı�setԪ��ֵ���������ƻ�set��֯��
//���仰˵��set��iterator��һ��const_iterator.
//���ڸ�set������ƽ�������������������������ݣ��ͻ�������ݵ�˳��ʹ�ò���������������������

#if 0
1 set���캯��
set<T> st;//setĬ�Ϲ��캯����
mulitset<T> mst; //multisetĬ�Ϲ��캯��: 
set(const set& st);//�������캯��
3.7.2.2 set��ֵ����
set & operator=(const set & st);//���صȺŲ�����
swap(st);//����������������
3.7.2.3 set��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

3.7.2.4 set�����ɾ������
insert(elem);//�������в���Ԫ�ء�
clear();//�������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
#endif
void printSet(set<int> &s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	//ע�⣺set�����Ĳ���ֻ��insert
	set<int> s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	//s[2];��֧���������
	
	//����������ظ�����
	//��keyֵ�Զ���������
	printSet(s);
	if (s.empty())
	{
		cout << "setΪ��" << endl;
	}
	else
	{
		cout << "set��Ϊ�գ���СΪ" << s.size() << endl;
	}

	s.erase(30);//��Ϊ�������ظ�������������remove
	printSet(s);
}
#if 0
3.7.2.5 set���Ҳ���
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key);//���Ҽ�key��Ԫ�ظ���
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ��������������ڣ�����set.end();
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ��������������ڣ�����set.end();
equal_range(keyElem);//����������key��keyElem��ȵ������޵��������������������ڣ�����set.end();
#endif
void test2()
{
	set<int> s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);

	set<int>::iterator pos = s.find(30);
	if (pos != s.end())//ע�⣺string���find���ص���int���ݣ��Ҳ�������-1
	{
		cout << "�ҵ���Ԫ�أ�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ�أ�" << endl;
	}

	//����set���ԣ�count�Ľ����Ҫô��0��Ҫô��1����Ϊset�����ļ�ֵ�����ظ�
	int num = s.count(40);
	cout << "keyΪ40�ĸ���Ϊ��" << num << endl;

	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	set<int>::iterator pos2 = s.lower_bound(30);

	if (pos2 != s.end())
	{
		cout << "lower_bound��ֵΪ��" << *pos2 << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ�أ�" << endl;
	}
	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	pos2 = s.upper_bound(30);

	if (pos2 != s.end())
	{
		cout << "upper_bound��ֵΪ��" << *pos2 << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ�أ�" << endl;
	}

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	pair<set<int>::iterator, set<int>::iterator> ret = s.equal_range(30);//equal_rangeԴ��ķ�������Ϊpair<iterator, iterator>
	//ret�Ƕ��������ret.first��һ��������
	if(ret.first !=s.end())
		cout << "equal_range�е�lower_bound��ֵΪ��" << *(ret.first) << endl;
	else
		cout << "δ�ҵ�Ԫ�أ�" << endl;
	//ret.second�ڶ���������
	if(ret.second!=s.end())
		cout << "equal_range�е�upper_bound��ֵΪ��" << *(ret.second) << endl;
	else
		cout << "δ�ҵ�Ԫ�أ�" << endl;
	//insert���ص���pair<iterator,bool>
}

void test3()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);//insert��������pair<iterator, bool>
	//ͨ�����鴴�����󣬶������а�����������first��second
	//iterator�����λ�ã�����ʧ�ܻ᷵��end()
	//bool �Ƿ����ɹ�
	if (ret.second)
		cout << "��һ�β���ɹ�" << endl;
	else
		cout << "��һ�β���ʧ��" << endl;

	ret = s.insert(10);
	if (ret.second)
		cout << "�ڶ��β���ɹ�" << endl;
	else
		cout << "�ڶ��β���ʧ��" << endl;
	
	printSet(s);

	//insertԴ�룺
#if 0
	pair<iterator, bool> insert(value_type&& _Val) {
	const auto _Result = _Emplace(_STD move(_Val));
	return { iterator(_Result.first, _Get_scary()), _Result.second };
	}
#endif
}

void test4()
{
	//set��multiset������ͷ�ļ�����#include <set>
	//multiset��������ظ���keyֵ
	multiset<int> ms;
	ms.insert(10);//�����insert����������iterator
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}
}


class myCompareInt
{
public:
	bool operator()(int v1,int v2) const//����Ҫ��const���������ͨ����
	{//�����������͡�const myCompareInt���ı��ʽ�ᶪʧһЩ const - volatile �޶����Ե���bool myCompareInt::operator ()(int, int)
		return v1 > v2;
	}
};
void test5()
{
	set<int> s;//Ĭ�ϴ�С��������
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	printSet(s);
	//����set�ĵ�������ֻ���ģ������ָ����������ڲ���ǰ����ָ��

	set<int,myCompareInt> s2;//�ṩ�º����������ǻص����������������͡�ָ�����Զ����������͵��������
	//ע�⣺set<int,myCompareInt>���Ƕ���
	s2.insert(10);
	s2.insert(50);
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);
	for (set<int, myCompareInt>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
}

//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
class myComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const//����Ҫ��const���������ͨ����
	{//�������͡�const myComparePerson���ı��ʽ�ᶪʧһЩ const - volatile �޶����Ե���bool myComparePerson::operator ()(const Person, const Person)

		//���������� ��С����
		return p1.m_age < p2.m_age;
	}
};
void test6()
{
	//һ�����÷º���ָ������
	set<Person,myComparePerson> s;
	Person p1("aaa", 10);
	Person p2("bbb", 40);
	Person p3("ccc", 20);
	Person p4("ddd", 30);
	Person p5("eee", 50);

	//�����Զ����������ͣ�ʹ��set��������ʱ����֪����ʲô�������������˻ᱨ��
	//һ�����÷º���ָ������
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Person,myComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������" << (*it).m_name << " ���䣺" << it->m_age << endl;
	}

	Person p6("fff", 20);
	set<Person, myComparePerson>::iterator pos = s.find(p6);//�����ָ���Ĺ�����в���
	if (pos == s.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << pos->m_name << " " << pos->m_age << endl;
	}

}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();

	return 0;
}