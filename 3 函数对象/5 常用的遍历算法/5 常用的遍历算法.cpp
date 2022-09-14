#define _CRT_SECURE_NO_WARNINGS 1
//�㷨��Ҫ����ͷ�ļ�<algorithm> <functional> <numeric>��ɡ�
//<algorithm>������STLͷ�ļ�������һ��, ���г��õĹ����漰���Ƚϣ����������ң����������ƣ��޸ģ���ת�����򣬺ϲ���...
//<numeric>�����С��ֻ�����ڼ������������Ͻ��еļ������ģ�庯��.
//<functional> ������һЩģ����, ����������������

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#if 0
/*
	�����㷨 ��������Ԫ��
	@param beg ��ʼ������
	@param end ����������
	@param _callback  �ص��������ߺ�������
	@return ��������
*/
for_each(iterator beg, iterator end, _callback);
#endif
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << endl;
		m_count++;
	}
	int m_count = 0;
};
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for_each���ڱ���
	for_each(v.begin(), v.end(), MyPrint());

	//for_each�з���ֵ�������󷵻�
	MyPrint print = for_each(v.begin(), v.end(), MyPrint());

	cout << "print.m_count = " << print.m_count << endl;
}

#include <functional>
class MyPrint2:public binary_function<int,int,void>
{
public:
	void operator()(int val,int start) const
	{
		cout << val + start<< endl;
	}
};
void test2()
{
	//for_each���԰󶨲����������
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(MyPrint2(),1000));
}

#if 0
/*
	transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
	ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
	@param beg1 Դ������ʼ������
	@param end1 Դ��������������
	@param beg2 Ŀ��������ʼ������
	@param _callback �ص��������ߺ�������
	@return ����Ŀ������������
*/
transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
#endif

class MyTransform
{
public:
	int operator()(int val)
	{
		return val + 1000;
	}
};
void test3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> v2;
	//��ʼvector��û�������ġ���û�������������з������ǻᱨ���
	//v2.reserve(v.size());//�ᱨ��Ԥ���˿ռ䣬�൱�ڻĵز���ֱ��ʹ�ã������Դ���push_backʹ��
	v2.resize(v.size());//����v2�����Ĵ�С

	transform(v.begin(), v.end(), v2.begin(), MyTransform());
	//��[begin,end)�����ֵ���α�����ͨ���ص���������º����ķ���ֵ��������v1�е����ݷ���v2��

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
	//transformԴ��1��
#if 0
	template <class _InIt, class _OutIt, class _Fn>
	_CONSTEXPR20 _OutIt transform(const _InIt _First, const _InIt _Last, _OutIt _Dest, _Fn _Func) {
		// transform [_First, _Last) with _Func
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		auto _UDest = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		for (; _UFirst != _ULast; ++_UFirst, (void) ++_UDest) {
			*_UDest = _Func(*_UFirst);
		}

		_Seek_wrapped(_Dest, _UDest);
		return _Dest;
	}
#endif
}

//������1������2�е�Ԫ����ӷ��뵽������������
struct transformTest02 
{
	int operator()(int v1, int v2) 
	{
		return v1 + v2;
	}
};
void test4()
{
	vector<int> vSource1;
	vector<int> vSource2;
	for (int i = 0; i < 10; i++) 
	{
		vSource1.push_back(i + 1);
		vSource2.push_back(i + 1);
	}
	for_each(vSource1.begin(), vSource1.end(), [](int val) {cout << val << " "; });
	cout << endl;
	for_each(vSource2.begin(), vSource2.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//Ŀ������
	vector<int> vTarget;
	//��vTarget���ٿռ�
	vTarget.resize(vSource1.size());

	transform(vSource1.begin(), vSource1.end(), vSource2.begin(), vTarget.begin(), transformTest02());
	//��ӡ
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });
	//transformԴ��2��
#if 0
	template <class _InIt1, class _InIt2, class _OutIt, class _Fn>
	_CONSTEXPR20 _OutIt transform(
		const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, _OutIt _Dest, _Fn _Func) {
		// transform [_First1, _Last1) and [_First2, ...) with _Func
		_Adl_verify_range(_First1, _Last1);
		auto _UFirst1 = _Get_unwrapped(_First1);
		const auto _ULast1 = _Get_unwrapped(_Last1);
		const auto _Count = _Idl_distance<_InIt1>(_UFirst1, _ULast1);
		auto _UFirst2 = _Get_unwrapped_n(_First2, _Count);
		auto _UDest = _Get_unwrapped_n(_Dest, _Count);
		for (; _UFirst1 != _ULast1; ++_UFirst1, (void) ++_UFirst2, ++_UDest) {
			*_UDest = _Func(*_UFirst1, *_UFirst2);
		}

		_Seek_wrapped(_Dest, _UDest);
		return _Dest;
	}

#endif
}
int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}

//���ɣ���ʹ��STL�еĺ���������ͨ��ת������鿴����Դ��Ĳ����ͷ�������