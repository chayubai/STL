#define _CRT_SECURE_NO_WARNINGS 1
//List������һ����ͷ˫��ѭ������
//����list��һ��˫�����������������ܹ��߱�ǰ�ơ����Ƶ�����������list�����ṩ����Bidirectional Iterators.
//List��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ��
//����vector�ǲ������ģ���Ϊvector�Ĳ������������ɼ������������ã�����ԭ�еĵ�����ȫ��ʧЧ��
//����ListԪ�ص�ɾ����Ҳֻ�б�ɾ�����Ǹ�Ԫ�صĵ�����ʧЧ�����������������κ�Ӱ�졣

//�����ܽ�:
//���ö�̬�洢���� ,��������ڴ��˷Ѻ����
//����ִ�в����ɾ������ʮ�ַ��� ,�޸�ָ�뼴��,����Ҫ�ƶ�����Ԫ��
//���������ڲ�֧��������ʣ�Ϊ�˱���ڵ�ͽڵ�֮���ǰ���ͺ�̣���˿ռ��ʱ�����ķѽϴ�
//ע�⣺�Լ��ṩ��sort������find���������Զ����������ͣ���Ҫ�ṩָ������(�ص�����/�º���)

//��֧��������ʣ������ɽṹ�������ģ�����list�������ײ�����ݽṹ��(˫��)������˲�֧���������

#include <iostream>
#include <list>
using namespace std;
void test()
{
	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}
	//cout << myList[0];//�޷��������
#if 0
	//��֤˫��ѭ������ע�⣺vs2013���У��߰汾�ὫһЩ��Ա�������ص����޷�����

	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead)
		{
			node = node->_Next;
			//node = node->_Prev;
		}
	}
#endif
}

#if 0
1��list���캯��
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n, elem);//���캯����n��elem����������
list(const list& lst);//�������캯����
2��list����Ԫ�ز����ɾ������
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos, elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
#endif
void printList(const list<int>& l)//�ʣ�Ϊʲôconst list<int> l����
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}

	//�������  
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
	{
		cout << *it << endl;
	}

	//list��������֧��������ʣ�֧��˫�����
	list<int>::iterator it = l.begin();
	//it = it + 1;
}
void test2()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);
	
	printList(l);//200 100 10 20 30

	l.pop_back();
	l.pop_front();
	printList(l);//10 20 30

	l.insert(l.begin(), 10000);
	printList(l);
	l.erase(l.begin());
	printList(l);//10 20 30

	l.push_back(20);
	l.push_back(20);
	printList(l);//10 20 30 20 20

	l.remove(20);
	printList(l);//10 30
}
#if 0

3��list��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
4��list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list& lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����
5��list���ݵĴ�ȡ
front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�
#endif

void test3()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);

	list<int> l2;
	l2.assign(10, 100);
	printList(l2);

	l.swap(l2);
	printList(l2);

	//l[0];//��������[]����list�����е�Ԫ��
	//l.at(0);//��������at��ʽ����list�����е�Ԫ��
	
	//������Ҳ��֧���������
	list<int>::iterator it = l.begin();
	//it = it + 1;//����
	it++;
	it--;//֧��˫��
}

#if 0
6��list��ת���� - �ʱ��㷨��ע�⣺�����Ƿ��ʱ��㷨
reverse();//��ת��������list����1,3,5Ԫ�أ����д˷�����list�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
#endif
#include <algorithm>
bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
void test4()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);
	printList(l);
	l.reverse();
	printList(l);

	//sort(l.begin(), l.end());//sort��ȫ�ֺ����������ᱨ��
	//��������ĵ�����֧��������ʣ�����ֱ��ʹ��ϵͳ�ṩ�ı�׼�㷨

	//���ڲ�֧��������ʵĵ�����������������ʹ��ϵͳ�ṩ���㷨����������(����)�����ṩ��Ӧ���㷨�ӿ�
	l.sort();//Ĭ�ϴ�С����
	printList(l);

	//�Ӵ�С����
	l.sort(myCompare);//Pred �ص�����
	printList(l);
}

#include <string>
//�Զ����������͵�����
class Person
{
public:
	Person(string name, int age,int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}

	bool operator==(const Person& p) const//����Ҫ��const��������벻ͨ��
	{
		if (m_name == p.m_name && m_age == p.m_age && m_height == p.m_height)
		{
			return true;
		}
		return false;
	}

	string m_name;
	int m_age;
	int m_height;
};
bool myComparePerson(Person& p1, Person& p2)
{
	if(p1.m_age == p2.m_age)
		return p1.m_height < p2.m_height;
	return p1.m_age > p2.m_age;
}
void test5()
{
	list<Person> l;
	Person p1("��ɪ", 14,170);
	Person p2("����", 19,179);
	Person p3("����", 22, 185);
	Person p4("槼�", 11,160);
	Person p5("�����", 13,230);
	Person p6("����", 22,170);
	Person p7("�ŷ�", 22,180);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	l.push_back(p7);

	//����������н��򣬴Ӵ�С�����������ȣ�����߽�������
	//�����Զ�����������ͣ�����Ҫָ���������
	//l.sort();//����
	l.sort(myComparePerson);

	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "������" << (*it).m_name << " ���䣺" << (*it).m_age << " ��ߣ�" << it->m_height << endl;
	}

	l.remove(p4);//����ֱ��remove�Զ��������ͣ�����ᱨ����Ҫ����==������
	//remove�ı����ǣ�����������
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "������" << (*it).m_name << " ���䣺" << (*it).m_age << " ��ߣ�" << it->m_height << endl;
	}
#if 0
	//removeԴ�룺
	void remove(const _Ty & _Val)
	{	//erase each element matching _val
		iterator _Val_it = end();
		for (iterator _First = begin(); _First != end(); )
			if (*_First == _Val)//���ֱ��l.remove(p4);��Ҫ����==����������֪����αȽ��Զ����������͵ı���
				if (_STD addressof(*_First) == _STD addressof(_Val))
					_Val_it = _First++;
				else
					_First = erase(_First);
			else
				++_First;
		if (_Val_it != end())
			erase(_Val_it);
	}
#endif
}

int main() 
{
	//test4();

	test5();
	return 0;
}