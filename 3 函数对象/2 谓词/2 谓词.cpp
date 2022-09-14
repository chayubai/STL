#define _CRT_SECURE_NO_WARNINGS 1
//ν����ָ ��ͨ���� �� ���ص�operator() ����ֵ��bool���͵ĺ�������(�º���)��
//���operator����һ����������ô����һԪν��, �������������������ô������Ԫν�ʣ�ν�ʿ���Ϊһ���ж�ʽ��
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//һԪν��
class GreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};
void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//���ҵ�һ������20������

	//���������� �������� ��������Ҳ����ʹ�ö�����
	//GreaterThan20 greaterThan20;
	//vector<int>::iterator ret = find_if(v.begin(), v.end(), greaterThan20);//GreaterThan20()��������pred�º�������ص��������ú������ص�����

	vector<int>::iterator ret = find_if(v.begin(), v.end(), GreaterThan20());//GreaterThan20()��������pred�º�������ص��������ú������ص�����
	if (ret != v.end())
		cout << "�ҵ��˴���20������Ϊ��" << *ret << endl;
	else
		cout << "δ�ҵ�" << endl;
	//ע�⣺�����д���20���������Լ�һ��ѭ��
	//find_ifԴ�룺
#if 0
	// FUNCTION TEMPLATE find_if
	template <class _InIt, class _Pr>
	_NODISCARD _CONSTEXPR20 _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred) { // find first satisfying _Pred
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		for (; _UFirst != _ULast; ++_UFirst) {
			if (_Pred(*_UFirst)) {//GreaterThan20()(*_UFirst) *_UFirst == val
				break;
			}
		}

		_Seek_wrapped(_First, _UFirst);
		return _First;//���ص�����������������������ظ�λ�õĵ����������û�����������������end()������
	}
#endif
}

//��Ԫν��
void myPrintInt(int val)
{
	cout << val << " ";
}
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	sort(v.begin(), v.end());//��С����

	//����
	for_each(v.begin(), v.end(), myPrintInt);
	cout << endl;

	//ʹ�ú������󣬸ı��㷨����
	sort(v.begin(), v.end(),MyCompare());//�Ӵ�С

	//ע�⣺�º�����Ҫ��(),�ص�����ֻ��Ҫ������
	
	//lambda���ʽ
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	//[](int val) {cout << val << " "; }����������[]����lambda���ʽ��־
	cout << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}