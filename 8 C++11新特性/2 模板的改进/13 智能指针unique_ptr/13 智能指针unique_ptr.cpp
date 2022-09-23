#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <memory>//����ָ�������ͷ�ļ�

class Test
{
public:
	~Test()
	{
		cout << "����" << endl;
	}
};
void test1()
{
	unique_ptr<int> up1(new int(11));//��������ָ�����

	cout << "*up1 = " << *up1 << endl;//������operator*()��operator->()

	{
		unique_ptr<Test> up2(new Test);
		//�����ͷţ��Զ��ͷ�

		//��Ϊָ���ͷŶ����ռ�
		//up2 = nullptr;//����1
		up2 = NULL;//����2
		up2.reset();//����3����Ա����
		//�����ͷŶ�Σ����ᵼ�¶δ���

		cout << "**********" << endl;
	}
	cout << "����������������" << endl;
}

void test2()
{
	unique_ptr<int> up1(new int(11));//��������ָ�����
	//unique_ptr<int> up2 = up1;//err�����ÿ�������

	//��up1��ʹ��Ȩת�Ƹ���up2��֮��up1�����ٲ��������ռ�
	unique_ptr<int> up2 = std::move(up1);//ʹ���ƶ�����
	cout << "*up2 = " << *up2 << endl;
	//cout << "*up1 = " << *up1 << endl;//err���Ƿ����ʣ�����Ұָ��ָ����ڴ�
}

void test3()
{
	unique_ptr<int> up1(new int(11));//��������ָ�����
	//up1.reset();//������޲Σ���������ʽ�ͷŶ�������

	//����вΣ����ͷ�ԭ���������ݣ����¸�up1��һ���µĶ�������
	up1.reset(new int(22));

	cout << "*up1 = " << *up1 << endl;
}

void test4()
{
	unique_ptr<int> up1(new int(11));//��������ָ�����
	
	//�ͷſ���Ȩ�������ͷŶ����ڴ�
	int* p = up1.release();
	cout << *p << endl;
	//cout << *up1 << endl;//err

	//��ʱ��Ҫ�ֶ��ͷ�
	delete p;
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}