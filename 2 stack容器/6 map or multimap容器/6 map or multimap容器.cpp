#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
using namespace std;
//Map������ʽ�������������ǣ�����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
//Map���е�Ԫ�ض���pair,ͬʱӵ��ʵֵ�ͼ�ֵ��pair�ĵ�һԪ�ر���Ϊ��ֵ���ڶ�Ԫ�ر���Ϊʵֵ��
//map����������Ԫ������ͬ�ļ�ֵ���������ظ���valueֵ
//ע�⣺�Զ�������������ΪԪ�ؼ�key����Ҫָ���������

//����ͨ��map�ĵ������ı�map�ļ�ֵ�������Ҫ�޸�Ԫ�ص�ʵֵ����ô�ǿ��Եġ�
//Ҳ��ֻ��������

//Multimap��map�Ĳ������ƣ�Ψһ����multimap��ֵ���ظ���
//Map��multimap�����Ժ����Ϊ�ײ�ʵ�ֻ��ơ�

//set/multiset<T> ��������Ԫ�ز��Ƕ���
//map/multimap<T1,T2> ��һ����key �ڶ�����value

#if 0
1 map���캯��
map<T1, T2> mapTT;//mapĬ�Ϲ��캯��: 
map(const map& mp);//�������캯��
2 map��ֵ����
map & operator=(const map & mp);//���صȺŲ�����
swap(mp);//����������������
3 map��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��
4 map��������Ԫ�ز���
map.insert(...); //����������Ԫ�أ�����pair<iterator,bool>
map<int, string> mapStu;
// ��һ�� ͨ��pair�ķ�ʽ�������
mapStu.insert(pair<int, string>(3, "С��"));
// �ڶ��� ͨ��pair�ķ�ʽ�������
mapStu.insert(make_pair(-1, "У��"));
// ������ ͨ��value_type�ķ�ʽ�������
mapStu.insert(map<int, string>::value_type(1, "С��"));
// ������ ͨ������ķ�ʽ����ֵ
mapStu[3] = "С��";
mapStu[5] = "С��";
Person{ name,age };
map<int, Person> m;
m[1].name = "С��";m[1].age = 20;
#endif
void test1()
{
	//��һ������key�����ͣ��ڶ�������value������
	map<int, int> m;
	//��һ�ֲ��뷽ʽpair<int, int>(1, 10)�����������
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	//�ڶ��ֲ��뷽ʽ �Ƽ�
	m.insert(make_pair(2, 20));
	//�����ֲ��뷽ʽ
	m.insert(map<int, int>::value_type(3, 30));
	//�����ֲ��뷽ʽ ���Ƽ�
	m[4] = 40;//�ڲ�������[]������������ʣ���vector<int> v;v[10]�ǿ���������ʵ�
	//ע�⣺m[key] = value;
	//ע�⣺map/multimap���Ը���keyֵ��ʹ��"[]"��ֵ�����valueֵ
	cout << m[4] << endl;

	//cout << m[10] << endl;//ע�⣺���Ƽ����ַ�ʽ��ʼ�����������������»����һ�����ݣ�value==0

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		//pair.first keֵ��pair.second valueֵ
		//*it == pair
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

void test()
{
	map<int, int> m;
	pair<map<int, int>::iterator, bool> ret = m.insert(pair<int, int>(1, 10));//insert��������pair<iterator, bool>
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	if (ret.second)
		cout << "��һ�β���ɹ�" << endl;
	else
		cout << "��һ�β���ʧ��" << endl;

	ret = m.insert(make_pair(2, 40));
	if (ret.second)
		cout << "�ڶ��β���ɹ�" << endl;
	else
		cout << "�ڶ��β���ʧ��" << endl;

	m[4] = 40;//�������key�����ڣ�����pair���뵽map������
	m[5] = 40;
	//�������key���ڣ����޸�key��Ӧ��valueֵ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		//pair.first keֵ��pair.second valueֵ
		//*it == pair
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	//���ͨ��[]����map�д��ڵ�key�����ӡkey��Ӧ��valueֵ
	//������ʵ�key�����ڣ��Ὣ���ʵ�keyֵ���뵽map�����У�valueĬ��Ϊ0
	cout << m[5] << " " << m[7] << endl;

	//ע�⣺keyֵ����map�������±꣬��֧���������
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
	m[0].m_name = "С��";//ע��key����map�������±꣬������һ�����
	m[0].m_age = 22;
	m[1].m_name = "С��";
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
3.8.2.5 mapɾ������
clear();//ɾ������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(keyElem);//ɾ��������keyΪkeyElem�Ķ��顣
#endif
void test2()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	m.erase(3);//����keyֵ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

#if 0
3.8.2.6 map���Ҳ���
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
#endif
void test3()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	map<int, int>::iterator ret = m.find(3);//����keyֵ
	if (ret != m.end())
		cout << "�ҵ��� keyΪ" << ret->first << "valueΪ" << ret->second << endl;
	else
		cout << "δ�ҵ���" << endl;

	int num = m.count(4);
	cout << "keyΪ4�Ķ������Ϊ��" << num << endl;

	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	map<int, int>::iterator pos = m.lower_bound(3);
	if(pos != m.end())
		cout << "�ҵ���lower_bound keyΪ" << pos->first << "valueΪ" << pos->second << endl;
	else
	cout << "δ�ҵ���" << endl;

	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	pos = m.upper_bound(3);
	if (pos != m.end())
		cout << "�ҵ���upper_bound keyΪ" << pos->first << "valueΪ" << pos->second << endl;
	else
		cout << "δ�ҵ���" << endl;

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	pair<map<int,int>::iterator,map<int,int>::iterator> ret2 = m.equal_range(3);//��������:pair<iterator, iterator>
	//ret�Ƕ��������
	if (ret2.first != m.end())
		cout << "�ҵ���equal_range�е�lower_bound keyΪ" << ret2.first->first << "valueΪ" << ret2.first->second << endl;
	else
		cout << "δ�ҵ���" << endl;

	if (ret2.second != m.end())
		cout << "�ҵ���equal_range�е�upper_bound keyΪ" << ret2.second->first << "valueΪ" << ret2.second->second << endl;
	else
		cout << "δ�ҵ���" << endl;

	//ע�⣺ret2.first��ʾmap<int,int>::iterator����ret2.first->first��ʾ��һ��int��ret2.first->second��ʾ�ڶ���int
	//insert���ص���pair<iterator,bool>
}

class myCompareInt
{
public:
	bool operator()(int v1, int v2) const//������Ҫ����const��������벻ͨ��
	{//�������͡�const myCompareInt���ı��ʽ�ᶪʧһЩ const - volatile �޶����Ե���bool myCompareInt::operator ()(int, int)		

		return v1 > v2;
	}
};
void test4()
{
	map<int, int> m;//Ĭ�ϰ�key��С��������
	m.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m.insert(make_pair(3, 30));
	m.insert(map<int, int>::value_type(2, 20));
	m[4] = 40;

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}

	//���÷º����������Ҫָ�������������Ҫ�ڲ���֮ǰ����ָ��
	map<int, int, myCompareInt> m2;
	m2.insert(pair<int, int>(1, 10));//key == 1 value == 10
	m2.insert(make_pair(2, 20));
	m2.insert(map<int, int>::value_type(3, 30));
	m2[4] = 40;

	for (map<int, int, myCompareInt>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	//ע�⣺ֻ�ܰ�key������
}

//ʵ���Զ����������͵�map����
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
		//*it == pair����
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