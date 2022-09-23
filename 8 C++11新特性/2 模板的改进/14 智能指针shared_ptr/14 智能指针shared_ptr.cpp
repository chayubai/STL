#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*
shared_ptr������������ָ�빲��ڡ�ӵ�С�ͬһ�ѷ��������ڴ棬
��ͨ�����ü�����reference counting��ʵ�֣����¼�ж��ٸ�shared_ptr��ָͬ��һ������
һ�����һ��������ָ�뱻���٣�Ҳ����һ��ĳ����������ü�����Ϊ0���������Żᱻ�Զ�ɾ����
*/
#include <memory>//����ָ�������ͷ�ļ�

void test1()
{
	shared_ptr<int> sp1(new int(11));
	shared_ptr<int> sp2 = sp1;//���Ե��ÿ������죬����������Ͷ����ռ��

	cout << "num = " << sp2.use_count() << endl;//���ó�Ա��������ӡ������

	//�ͷ�sp1��ֻ�Ǽ�����-1�������ռ�û���ͷ�
	sp1.reset();
	cout << "num = " << sp2.use_count() << endl;

	cout << *sp2 << endl;
	//cout << *sp1 << endl;//err���ͷŶ����ռ�İ󶨣��޷�ͨ��sp1���������ڴ�

	//�ͷ�sp2��ֻ�Ǽ�����-1�������ռ�û���ͷţ�ֻ�е���������ֵΪ0�������ռ�ͻ��ͷ�
	sp2.reset();
	cout << "num = " << sp2.use_count() << endl;
}
int main()
{
	return 0;
}