#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//���غ������ò��������࣬����󳣳�Ϊ��������function object��������������Ϊ���ƺ����Ķ���
//Ҳ�зº���(functor),��ʵ�������ء�()����������ʹ���������������������á�

//ע�⣺��������(�º���)��һ���࣬����һ��������
//�Ѻ����������Ϊ��һ���࣬��������������()����ͨ�����ഴ���������()����һ����������
class MyPrint
{
public:
	MyPrint()
	{
		m_count = 0;
	}
	void operator()(int num)
	{
		cout << num << endl;
		m_count++;
	}
public:
	int m_count;//���ô�����״̬
};
void myPrint1(int num)
{
	cout << num << endl;
}
void test1()
{
	MyPrint myPrint;
	myPrint(100);//��������һ����Ķ������Ҳ��Ϊ��������Ҳ�зº���
	//���������������ͨ�����������ղ���

	myPrint1(100);//��������

	MyPrint()(100);//�����������
}

int num = 0;//ȫ�ֱ��������������У���������ȥʹ��ȫ�ֱ���
//����ȫ�ֱ������ڶ��߳������ڹ�����Դ���ܶ��˶���ʹ���������²�ȷ��
void myPrint2(int num)
{
	num++;

	cout << num << endl;
}
void test2()
{
	//�������� ��������ͨ�����ĸ������ӵ���Լ���״̬
	MyPrint myPrint;
	myPrint(100);
	myPrint(100);
	myPrint(100);
	cout << "ͬһ�����󣬵��ô�����" << myPrint.m_count << endl;//���溯�����õ�״̬
	
	//������ͨ�����������ͳ�Ʋ�������Ҫ����ȫ�ֱ�����̬����
	myPrint2(1); 
	myPrint2(2);
	cout << "���������ô�����" << num << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	MyPrint mp;
	MyPrint p = for_each(v.begin(), v.end(), mp);//����������ʹ�÷º�����ص�������for_each�������ͻ����������������
	//������������ʹ�÷º���ʱ������(����)���󼴿ɡ�ʹ�ûص����������뺯�����á�
	cout << "myPrint�����ô�����" << mp.m_count << endl;//0��for_each�ײ�Դ��û��ʹ���������ͣ�����ֵ�����������ڵĸı䲻��Ӱ�캯����ı���
	cout << "myPrint�����ô�����" << p.m_count << endl;//4

#if 0
	// FUNCTION TEMPLATE for_each
	template <class _InIt, class _Fn>
	_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { //_Fn _Func�����������ͣ����ÿ������죬������mp���뷵������Ϊ�ö��������
		// perform function for each element [_First, _Last)
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		for (; _UFirst != _ULast; ++_UFirst) {
			_Func(*_UFirst);
		}

		return _Func;
	}
#endif
}

void doPrint(MyPrint myPrint, int num)
{
	myPrint(num);
}
void test3()
{
	//�����������������Ϊ��������
	doPrint(MyPrint(), 1000);
}
//�ܽ᣺
//1����������ͨ�������幹�캯�������������������ڹ��������ʱ���ᷢ���κ����⣬�����˺������õ�����ʱ���⡣
//2���������󳬳���ͨ�����ĸ����������������Լ���״̬
//3����������� �������� inline�����ܺ�(��Դ��)���ú���ָ�뼸�������ܣ���ջ��ջ����
//4��ģ�溯������ʹ�����������ͨ���ԣ���Ҳ����������֮һ

int main()
{
	test3();
	return 0;
}