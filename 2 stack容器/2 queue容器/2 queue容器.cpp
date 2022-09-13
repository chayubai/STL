#define _CRT_SECURE_NO_WARNINGS 1
//Queue����Ԫ�صĽ�����������ϡ��Ƚ��ȳ�����������ֻ��queue�Ķ���Ԫ�أ����л��ᱻ���ȡ�á�
//Queue���ṩ�������ܣ�Ҳ���ṩ��������

//queue�����������ǵ�����
//��ͷ-���� ��β-���
//�����ܽ᣺
//��֧�ֱ��������ṩ����������֧���������
//����ʱ������empty��pop����ʹ��


#include <iostream>
#include <queue>
using namespace std;

#if 0
1��queue���캯��
queue<T> queT;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ��
queue(const queue& que);//�������캯��
2��queue��ȡ�������ɾ������
push(elem);//����β���Ԫ��
pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
back();//�������һ��Ԫ��
front();//���ص�һ��Ԫ��
3��queue��ֵ����
queue & operator=(const queue & que);//���صȺŲ�����
4��queue��С����
empty();//�ж϶����Ƿ�Ϊ��
size();//���ض��еĴ�С
#endif

#include <string>

class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
int main()
{
	queue<int> m;
	m.push(1);
	m.push(2);
	//m[1];��֧���������

	queue<Person> q;
	Person p1("01", 15);
	Person p2("02", 17);
	Person p3("03", 18);
	Person p4("04", 16);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "size = " << q.size() << endl;
	//���Ҫ���ʷǶ�ͷ��Ԫ�أ���Ҫ��pop����ͷ��Ԫ��
	while (!q.empty())
	{
		cout << "��ͷ������ " << q.front().m_name << " ���� " << q.front().m_age << endl;
		cout << "��β������ " << q.back().m_name << " ���� " << q.back().m_age << endl;
		
		q.pop();
	}
	cout << "size = " << q.size() << endl;

	return 0;
}

//��ҵ1 queue������Ŷ���ָ��
//��ҵ2 queue�������stack����