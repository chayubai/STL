#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <iterator>

#if 0
/*
	copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
	@param beg ������ʼ������
	@param end ��������������
	@param dest Ŀ����ʼ������
*/
copy(iterator beg, iterator end, iterator dest)
#endif
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	v2.resize(v1.size());//ע�⣺���յ���������ֱ�ӷ����ݣ��ᱨ��
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//����copy��ӡ,ostream_iterator��ͷ�ļ���#include <iterator>
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));//�����������ݣ��ŵ����������У�ͨ��cout�������
}

#if 0
/*
	replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param oldvalue ��Ԫ��
	@param newvalue ��Ԫ��
*/
replace(iterator beg, iterator end, oldvalue, newvalue)
#endif
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	replace(v.begin(), v.end(), 3, 3000);
	//replace(v.begin(), v.end(), 23, 3000);//�Ҳ������滻
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

#if 0
/*
	replace_if�㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param callback�����ص�����ν��(����Bool���͵ĺ�������)
	@param newvalue ��Ԫ��
*/
replace_if(iterator beg, iterator end, _callback, newvalue)
#endif
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val == 3;
	}
};
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);

	//�����е���3��Ԫ���滻��3000
	replace_if(v.begin(), v.end(), MyReplace(), 3000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

#if 0
/*
	ע��: ����������Ҫͬ������
	swap�㷨 ��������������Ԫ��
	@param c1����1
	@param c2����2
*/
swap(container c1, container c2)
#endif
void test4()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2(10, 100);
	cout << "����ǰV1������" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	swap(v1, v2);
	cout << "������V1������" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

//���ɣ���ʹ��STL�еĺ���������ͨ��ת������鿴����Դ��Ĳ����ͷ�������