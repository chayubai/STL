#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
class Person
{
public:
	Person(const char* name, int age)
	{
		cout << "�вι���" << endl;
		this->pName = new char[strlen(name) + 1];
		strcpy(this->pName, name);

		this->mAge = age;
	}
#if 1
	Person(const Person& p)
	{
		cout << "��������" << endl;
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);

		this->mAge = p.mAge;
	}
	Person& operator=(const Person& p)
	{
		if (this->pName != NULL)
			delete[] this->pName;

		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);

		this->mAge = p.mAge;

		return *this;
	}
#endif
	~Person()
	{
		cout << "��������" << endl;

		if (this->pName != NULL)
		{
			delete[] this->pName;
		}
	}
public:
	char* pName;
	int mAge;
};

int main()
{
	//����������ֵ���ݵķ�ʽ��������������ֵ������ÿ������캯��
	//void doWork(Person p);doWork(p1);Person p = p1 ��Person p = Person(p1);���ÿ������캯��
	Person p("aaa", 20);//�в� ����
	vector<Person> person;
	person.push_back(p);//���� ����
	person.push_back(p);
	//����Person������ά���������ٵ�����
	//��ʱ��p����vector<>�����У�������ԭ�����ݵĿ������������С�����ü򵥵�ֵ�������캯��
	//���¶���p�������е�p��ָ��ͬһ��ռ�
	//��Person p("aaa", 20);���н�����p�����Զ�����~Person()������deleteָ�������ָ������
	//��vector<Person> person;���н����������е�person�����~�Լ���Person()��������һ��deleteָ�������ָ������
	//��ͬһ��ռ�delete���Σ����³������

	//�����������Person������д��������͵ȺŲ������������

	//˼�������Ϊʲô����������������ã�
	return 0;
}
