#define _CRT_SECURE_NO_WARNINGS 1
//�������ʽ��Ҫ������һЩ���㷢���ڱ���ʱ���������ڴ��������������е�ʱ��

//���Ǻܴ���Ż���������Щ��������ڱ���ʱ��������ֻ��һ�Σ�������ÿ�γ�������ʱ�����㡣
#include <iostream>
using namespace std;
int GetNum()
{
	return 3;
}
const int GetNum2()
{
	return 3;
}
constexpr int GetNum3()
{//�������ʽ�������ڱ���׶�
	return 3;
}

//ע�⣺vs2013��֧�֣�qt��֧��
void test1()
{
	enum {
		//e1 = GetNum(),//�������ʽ���뺬�г���ֵ
		//e1 = GetNum2(),//�������ʽ���뺬�г���ֵ
		e1 = GetNum3(),
		e2
	};
	constexpr int tmp = GetNum3();//�����ڱ���׶�
	enum {
		a1 = tmp,
		a2
	};
}

int a = 3;//ȫ�ֱ���

void test2()
{
	//constexpr���������ƣ�
	//1.������ֻ����returnһ����䣨�м���������
	//2.���������з���ֵ��������void������
	//3.��ʹ��ǰ�������ж���
	//4.return���������ʽ�в���ʹ�÷ǳ������ʽ�ĺ�����ȫ�����ݣ��ұ�����һ���������ʽ
#if 0
	constexpr int func1()
	{
		//1��constexpr������ֻ����return���
		//err
		constexpr int a = 1;
		return a;
	}

	//vs 2019��֧�֣�qt�²���
	constexpr int func2()
	{
		//1���������typedef��usingָ���̬����
		static_assert(1, "fail");

		return 3;
	}

	//3�����������з���ֵ��������void������
	constexpr void func3()
	{
		//err
	}

	//4��return���������ʽ�в���ʹ�÷ǳ������ʽ�ĺ�����ȫ�����ݣ��ұ�����һ���������ʽ
	constexpr int func4()
	{
		//err
		return a;//����ȫ�ֱ���
	}
	int num()
	{
		return 10;//���н׶�
	}
	constexpr int func5()//����׶Σ�ì��
	{
		//err
		return test();//���طǳ������ʽ�ĺ���
	}
}
#endif

}
int main()
{
	constexpr int func6();//����

	constexpr int tmp = func6();//err����ʹ��ǰ�������ж��壬�봫ͳ�ĺ���ʹ�ò�ͬ
	return 0;
}

constexpr int func6()//����׶Σ�ì��
{
	//err
	return 10;//���طǳ������ʽ�ĺ���
}