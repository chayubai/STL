#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <typeinfo>
#include <vector>

void test1()
{
	int i;
	decltype(i) j = 0;//ͨ��i������ȡ��Ӧ�����ͣ��ٶ������

	cout << typeid(j).name() << endl;

	float a;
	double b;
	decltype(a + b) c;
	cout << typeid(j).name() << endl;

	vector<int> tmp;
	decltype(tmp.begin()) k;
	for (k = tmp.begin(); k != tmp.end(); k++)
	{
		//......
	}
	//auto���Զ���ȡ���ͣ�decltype���Ȼ�ȡ������ʹ��������Ͷ������

	enum
	{
		Ok,
		Error
	}flag;//flag������ö�����͵ı���
	//��C�У������ṹ�壬���������壬����ö�٣�ֻ�ܴ���һ�α�����֮�����ٴ�������
	decltype(flag) f;//decltypeʹ�ÿ����ٴ�������
}
int main()
{
	return 0;
}