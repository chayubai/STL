#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <memory>//����ָ�������ͷ�ļ�

void test1()
{
	shared_ptr<int> sp1(new int(11));
	shared_ptr<int> sp2 = sp1;//���Ե��ÿ������죬����������Ͷ����ռ��

	weak_ptr<int> wp = sp1;
	cout << "num = " << sp1.use_count() << endl;//���ó�Ա��������ӡ������
	cout << "num = " << wp.use_count() << endl;//���ó�Ա��������ӡ������

	//weak_ptr��Ȼ���Ͷ����ռ�󶨣�������ͨ����Ա����lock������ȡshared_ptr<T>����
	shared_ptr<int> sp3 = wp.lock();//��3������󶨶����ռ�
	cout << "num = " << sp1.use_count() << endl;//���ó�Ա��������ӡ������
	cout << "num = " << wp.use_count() << endl;//���ó�Ա��������ӡ������

	cout << *sp1 << " , " << *sp2 << " , " << *sp3 << endl;
	//cout << *wp << endl;//err, û������ * �� -> ������ʹ��lock���һ�����õ�shared_ptr����

	sp1.reset();
	sp2.reset(); 
	sp3.reset();

	cout << "num = " << sp1.use_count() << endl;//���ó�Ա��������ӡ������
	cout << "num = " << wp.use_count() << endl;//���ó�Ա��������ӡ������

	//�������ռ��ͷź�wp.lock()��ȡ�ĵķ���ֵΪ��
	shared_ptr<int> tmp = wp.lock();
	if (tmp == nullptr)
	{
		cout << "�����ռ��Ѿ��ͷ�" << endl;
	}
}
int main()
{
	return 0;
}