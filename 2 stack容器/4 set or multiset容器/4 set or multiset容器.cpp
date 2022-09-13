#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
using namespace std;
//Set（关联式容器）的特性是。所有元素都会根据元素的 键值 自动被排序。
//Set的元素不像map那样可以同时拥有实值和键值，set的元素即是键值。
//Set不允许两个元素有相同的键值。
//注意：自定义数据类型作为元素即key，需要指定排序规则

//注意：实值即value值，键值即key值，set和multiset只有键值
//set的iterator是一种只读iterator.

//multiset特性及用法和set完全相同，唯一的差别在于它允许键值重复。
//set和multiset的底层实现是红黑树，红黑树为平衡搜索二叉树的一种。

//我们可以通过set的迭代器改变set元素的值吗？
//不行，因为set元素值就是其键值，关系到set元素的排序规则。
//如果任意改变set元素值，会严重破坏set组织。
//换句话说，set的iterator是一种const_iterator.
//由于该set容器是平衡的搜索二叉树，如果插入数据，就会打乱数据的顺序，使得不符合搜索二叉树的特性

#if 0
1 set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数: 
set(const set& st);//拷贝构造函数
3.7.2.2 set赋值操作
set & operator=(const set & st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。
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
	//注意：set容器的插入只有insert
	set<int> s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	//s[2];不支持随机访问
	
	//不允许插入重复的数
	//按key值自动进行排序
	printSet(s);
	if (s.empty())
	{
		cout << "set为空" << endl;
	}
	else
	{
		cout << "set不为空，大小为" << s.size() << endl;
	}

	s.erase(30);//因为不能有重复的数，类似与remove
	printSet(s);
}
#if 0
3.7.2.5 set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。若不存在，返回set.end();
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。若不存在，返回set.end();
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。若不存在，返回set.end();
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
	if (pos != s.end())//注意：string类的find返回的是int数据，找不到返回-1
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到元素：" << endl;
	}

	//对于set而言，count的结果，要么是0，要么是1，因为set容器的键值不能重复
	int num = s.count(40);
	cout << "key为40的个数为：" << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	set<int>::iterator pos2 = s.lower_bound(30);

	if (pos2 != s.end())
	{
		cout << "lower_bound的值为：" << *pos2 << endl;
	}
	else
	{
		cout << "未找到元素：" << endl;
	}
	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	pos2 = s.upper_bound(30);

	if (pos2 != s.end())
	{
		cout << "upper_bound的值为：" << *pos2 << endl;
	}
	else
	{
		cout << "未找到元素：" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair<set<int>::iterator, set<int>::iterator> ret = s.equal_range(30);//equal_range源码的返回类型为pair<iterator, iterator>
	//ret是对组类对象，ret.first第一个迭代器
	if(ret.first !=s.end())
		cout << "equal_range中的lower_bound的值为：" << *(ret.first) << endl;
	else
		cout << "未找到元素：" << endl;
	//ret.second第二个迭代器
	if(ret.second!=s.end())
		cout << "equal_range中的upper_bound的值为：" << *(ret.second) << endl;
	else
		cout << "未找到元素：" << endl;
	//insert返回的是pair<iterator,bool>
}

void test3()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);//insert返回类型pair<iterator, bool>
	//通过对组创建对象，对组类中包含两个属性first和second
	//iterator插入的位置，插入失败会返回end()
	//bool 是否插入成功
	if (ret.second)
		cout << "第一次插入成功" << endl;
	else
		cout << "第一次插入失败" << endl;

	ret = s.insert(10);
	if (ret.second)
		cout << "第二次插入成功" << endl;
	else
		cout << "第二次插入失败" << endl;
	
	printSet(s);

	//insert源码：
#if 0
	pair<iterator, bool> insert(value_type&& _Val) {
	const auto _Result = _Emplace(_STD move(_Val));
	return { iterator(_Result.first, _Get_scary()), _Result.second };
	}
#endif
}

void test4()
{
	//set和multiset容器的头文件都是#include <set>
	//multiset允许插入重复的key值
	multiset<int> ms;
	ms.insert(10);//这里的insert返回类型是iterator
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}
}


class myCompareInt
{
public:
	bool operator()(int v1,int v2) const//这里要加const，否则编译通不过
	{//报错：具有类型“const myCompareInt”的表达式会丢失一些 const - volatile 限定符以调用bool myCompareInt::operator ()(int, int)
		return v1 > v2;
	}
};
void test5()
{
	set<int> s;//默认从小到大排序
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	printSet(s);
	//由于set的迭代器是只读的，如果想指定排序规则，在插入前进行指定

	set<int,myCompareInt> s2;//提供仿函数，而不是回调函数，即数据类型。指定出自定义数据类型的排序规则
	//注意：set<int,myCompareInt>不是对组
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

//自定义数据类型
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
	bool operator()(const Person& p1, const Person& p2) const//这里要加const，否则编译通不过
	{//具有类型“const myComparePerson”的表达式会丢失一些 const - volatile 限定符以调用bool myComparePerson::operator ()(const Person, const Person)

		//按年龄升序 从小到大
		return p1.m_age < p2.m_age;
	}
};
void test6()
{
	//一般利用仿函数指定规则
	set<Person,myComparePerson> s;
	Person p1("aaa", 10);
	Person p2("bbb", 40);
	Person p3("ccc", 20);
	Person p4("ddd", 30);
	Person p5("eee", 50);

	//对于自定义数据类型，使用set容器插入时，不知道按什么规则进行排序，因此会报错
	//一般利用仿函数指定规则
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Person,myComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << it->m_age << endl;
	}

	Person p6("fff", 20);
	set<Person, myComparePerson>::iterator pos = s.find(p6);//会根据指定的规则进行查找
	if (pos == s.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到：" << pos->m_name << " " << pos->m_age << endl;
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