#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
class Person
{
public:
	Person(const char* name, int age)
	{
		cout << "有参构造" << endl;
		this->pName = new char[strlen(name) + 1];
		strcpy(this->pName, name);

		this->mAge = age;
	}
#if 1
	Person(const Person& p)
	{
		cout << "拷贝构造" << endl;
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
		cout << "析构函数" << endl;

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
	//函数参数：值传递的方式，给函数参数传值，会调用拷贝构造函数
	//void doWork(Person p);doWork(p1);Person p = p1 即Person p = Person(p1);调用拷贝构造函数
	Person p("aaa", 20);//有参 析构
	vector<Person> person;
	person.push_back(p);//拷贝 析构
	person.push_back(p);
	//由于Person类中有维护堆区开辟的数据
	//此时将p放入vector<>容器中，即：将原来数据的拷贝放入容器中。会调用简单的值拷贝构造函数
	//导致对象p和容器中的p都指向同一块空间
	//当Person p("aaa", 20);运行结束，p对象自动调用~Person()函数，delete指向堆区的指针数据
	//当vector<Person> person;运行结束，容器中的person会调用~自己的Person()函数，再一次delete指向堆区的指针数据
	//对同一块空间delete两次，导致程序崩溃

	//解决方法：在Person类中重写拷贝构造和等号操作符进行深拷贝

	//思考：结果为什么有三个拷贝构造调用？
	return 0;
}
