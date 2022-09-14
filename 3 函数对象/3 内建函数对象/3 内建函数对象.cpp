#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>

//����һЩ�㷨�Ĳ�����Ҫʹ�ú�������ʱ�����Կ����ڽ��������󣬾Ͳ���Ҫ�Լ���ʵ�ַº�����

//STL�ڽ���һЩ�������󡣷�Ϊ:�����ຯ������,��ϵ�����ຯ�������߼�������º�����
//ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>��

#if 0
6�������ຯ������, ����negate��һԪ���㣬�������Ƕ�Ԫ���㡣
template<class T> T plus<T>//�ӷ��º���
template<class T> T minus<T>//�����º���
template<class T> T multiplies<T>//�˷��º���
template<class T> T divides<T>//�����º���
template<class T> T modulus<T>//ȡģ�º���
template<class T> T negate<T>//ȡ���º���

6����ϵ�����ຯ������, ÿһ�ֶ��Ƕ�Ԫ���㡣
template<class T> bool equal_to<T>//����
template<class T> bool not_equal_to<T>//������
template<class T> bool greater<T>//����
template<class T> bool greater_equal<T>//���ڵ���
template<class T> bool less<T>//С��
template<class T> bool less_equal<T>//С�ڵ���

�߼����������㺯��, notΪһԪ���㣬����Ϊ��Ԫ���㡣
template<class T> bool logical_and<T>//�߼���
template<class T> bool logical_or<T>//�߼���
template<class T> bool logical_not<T>//�߼���
#endif
/*
//�Զ����ģ�庯������ - ������
template<class T>
class Print
{
public:
	void operator()(T num)
	{
		cout << "num = " << num << end;
	}
};
void test()
{
	//void Print<T>//�Զ���Ĵ�ӡ�º���
	Print<int> p;
	p(10);
}
*/
void test1()
{
	//template<class T>
	//T negate<T>//ȡ���º���
	negate<int> n;
	cout << n(10) << endl;

	//template<class T> 
	//T plus<T>//�ӷ��º���
	plus<int> p;//��Ԫ���� �ڽ��������������������һ�µ�
	cout << p(10,10) << endl;
}

void test2()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);

	//�Ӵ�С
	sort(v.begin(), v.end(), greater<int>());//greater<int>()��������

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	//sortԴ��
#if 0
	template <class _RanIt, class _Pr>
	_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last, _Pr _Pred) { // order [_First, _Last)
		_Adl_verify_range(_First, _Last);
		const auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		_Sort_unchecked(_UFirst, _ULast, _ULast - _UFirst, _Pass_fn(_Pred));
	}

	template <class _RanIt>
	_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last) { // order [_First, _Last)
		_STD sort(_First, _Last, less<>{});//Ĭ����������ʱ������less<>{}
	}
#endif
}

void test3()
{
	vector<bool> v;
	v.push_back(true);//1
	v.push_back(false);//0
	v.push_back(true);
	v.push_back(false);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
	//�����߼��� ������v���˵�����v2�У���ִ��ȡ������
	vector<bool> v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
}
int main()
{
	//test2();
	test3();
	return 0;
}