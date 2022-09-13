#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
using namespace std;
//Map（关联式容器）的特性是，所有元素都会根据元素的键值自动排序。
//Map所有的元素都是pair,同时拥有实值和键值，pair的第一元素被视为键值，第二元素被视为实值，
//map不允许两个元素有相同的键值。可以有重复的value值
//注意：自定义数据类型作为元素即key，需要指定排序规则

//可以通过map的迭代器改变map的键值。如果想要修改元素的实值，那么是可以的。
//也是只读迭代器

//Multimap和map的操作类似，唯一区别multimap键值可重复。
//Map和multimap都是以红黑树为底层实现机制。

//set/multiset<T> 该容器的元素不是对组
//map/multimap<T1,T2> 第一个是key 第二个是value

#if 0
1 map构造函数
map<T1, T2> mapTT;//map默认构造函数: 
map(const map& mp);//拷贝构造函数
2 map赋值操作
map & operator=(const map & mp);//重载等号操作符
swap(mp);//交换两个集合容器
3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空
4 map插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.insert(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";
Person{ name,age };
map<int, Person> m;
m[1].name = "小华";m[1].age = 20;
#endif
void test1()
{
	//第一个参数key的类型，第二个参数value的类型
	map<int, int> m;
	//第一种插入方式pair<int, int>(1, 10)匿名对组对象
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	//第二种插入方式 推荐
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式 不推荐
	m[4] = 40;//内部重载了[]，不是随机访问，而vector<int> v;v[10]是可以随机访问的
	//注意：m[key] = value;
	//注意：map/multimap可以根据key值，使用"[]"赋值和输出value值
	cout << m[4] << endl;

	//cout << m[10] << endl;//注意：不推荐这种方式初始化，如果误操作，导致会插入一个数据，value==0

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		//pair.first ke值，pair.second value值
		//*it == pair
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

void test()
{
	map<int, int> m;
	pair<map<int, int>::iterator, bool> ret = m.insert(pair<int, int>(1, 10));//insert返回类型pair<iterator, bool>
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	if (ret.second)
		cout << "第一次插入成功" << endl;
	else
		cout << "第一次插入失败" << endl;

	ret = m.insert(make_pair(2, 40));
	if (ret.second)
		cout << "第二次插入成功" << endl;
	else
		cout << "第二次插入失败" << endl;

	m[4] = 40;//如果发现key不存在，创建pair插入到map容器中
	m[5] = 40;
	//如果发现key存在，会修改key对应的value值
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		//pair.first ke值，pair.second value值
		//*it == pair
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	//如果通过[]访问map中存在的key，会打印key对应的value值
	//如果访问的key不存在，会将访问的key值插入到map容器中，value默认为0
	cout << m[5] << " " << m[7] << endl;

	//注意：key值不是map容器的下标，不支持随机访问
}
#include <string>
#include <vector>
class Person
{
public:
	string m_name;
	int m_age;
};
void test12()
{
	map<int, Person> m;
	m[0].m_name = "小夏";//注意key不是map容器的下标，仅仅是一个编号
	m[0].m_age = 22;
	m[1].m_name = "小华";
	m[1].m_age = 20;
	
	vector<int> v;
	for (map<int, Person>::iterator it = m.begin(); it != m.end(); it++)
	{//*it = key  m[key] == value  
		v.push_back(it->first);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{//m[*it] == Person
		cout << "key = " << *it << " value name = " << m[*it].m_name 
			<< " value age = " << m[*it].m_age << endl;
	}
}

void test13()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	cout << v[0] << " " << v[1] << endl;
}

void test14()
{
	string s1 = "111";
	string s2 = "222";
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);

	map<int, vector<string>> m;
	m.insert(make_pair(1, v));

	//m[1];
	map<int, vector<string>>::iterator it = m.begin();

	cout << m[1][0] << endl;
	cout << m[1][1] << endl;

}

#if 0
3.8.2.5 map删除操作
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。
#endif
void test2()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	m.erase(3);//传入key值
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

#if 0
3.8.2.6 map查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
#endif
void test3()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	map<int, int>::iterator ret = m.find(3);//传入key值
	if (ret != m.end())
		cout << "找到了 key为" << ret->first << "value为" << ret->second << endl;
	else
		cout << "未找到的" << endl;

	int num = m.count(4);
	cout << "key为4的对组个数为：" << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	map<int, int>::iterator pos = m.lower_bound(3);
	if(pos != m.end())
		cout << "找到了lower_bound key为" << pos->first << "value为" << pos->second << endl;
	else
	cout << "未找到的" << endl;

	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	pos = m.upper_bound(3);
	if (pos != m.end())
		cout << "找到了upper_bound key为" << pos->first << "value为" << pos->second << endl;
	else
		cout << "未找到的" << endl;

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair<map<int,int>::iterator,map<int,int>::iterator> ret2 = m.equal_range(3);//返回类型:pair<iterator, iterator>
	//ret是对组类对象
	if (ret2.first != m.end())
		cout << "找到了equal_range中的lower_bound key为" << ret2.first->first << "value为" << ret2.first->second << endl;
	else
		cout << "未找到的" << endl;

	if (ret2.second != m.end())
		cout << "找到了equal_range中的upper_bound key为" << ret2.second->first << "value为" << ret2.second->second << endl;
	else
		cout << "未找到的" << endl;

	//注意：ret2.first表示map<int,int>::iterator，而ret2.first->first表示第一个int，ret2.first->second表示第二个int
	//insert返回的是pair<iterator,bool>
}

class myCompareInt
{
public:
	bool operator()(int v1, int v2) const//这里需要加上const，否则编译不通过
	{//具有类型“const myCompareInt”的表达式会丢失一些 const - volatile 限定符以调用bool myCompareInt::operator ()(int, int)		

		return v1 > v2;
	}
};
void test4()
{
	map<int, int> m;//默认按key从小到大排序
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m.insert(make_pair(3, 30));
	m.insert(map<int, int>::value_type(2, 20));
	m[4] = 40;

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}

	//利用仿函数，如果需要指定规则进行排序，要在插入之前进行指定
	map<int, int, myCompareInt> m2;
	m2.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m2.insert(make_pair(2, 20));
	m2.insert(map<int, int>::value_type(3, 30));
	m2[4] = 40;

	for (map<int, int, myCompareInt>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	//注意：只能按key来排序
}

//实现自定义数据类型的map排序
class MyKey
{
public:
	MyKey(int index,int id)
	{
		this->mindex = index;
		this->mid = id;
	}
	int mindex;
	int mid;
};
struct mycompare
{
	bool operator()(MyKey k1, MyKey k2) const
	{
		return k1.mindex > k2.mindex;
	}
};
void test5()
{
	map<MyKey, int, mycompare> m;
	m.insert(make_pair(MyKey(1, 2), 10));
	m.insert(make_pair(MyKey(3, 4), 20));
	m.insert(make_pair(MyKey(5, 6), 30));

	for (map<MyKey, int, mycompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		//*it == pair对象
		cout << "key = " << it->first.mindex << " " << it->first.mid << " value = " << it->second << endl;
	}
}
int main()
{
	//test1();
	//test();
	//test12();
	//test13();
	//test14();
	//test3();
	//test4();
	test5();
	return 0;
}