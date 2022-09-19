#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	enum Status
	{
		Ok,
		Error
	};
	/*enum Status2
	{
		Ok,
		Error
	};*/

	//��test1::Ok��: �ض��壻��ǰ�Ķ����ǡ�ö������
	//��test1::Error��: �ض��壻��ǰ�Ķ����ǡ�ö������

	Status flag = Ok;//Ok��һ��ȫ�ֱ�����ֻ�ܶ���һ��

	cout << sizeof(Ok) << endl;//4
	//ö��ֵĬ����0��ʼ������˵������������ֵ���϶���int��С
}

void test2()
{
	//1��ǿ����ö�٣�enum�������class��struct����
	enum class Status
	{
		Ok,
		Error
	};
	enum struct Status2
	{
		Ok,
		Error
	};

	//ע�⣺ǿ����ö����Ȼ��class/struct���Σ�������û��˽�У�����֮��

	//Status flag = Ok;//����δ�����ʶ�� "Ok"

	//2��ǿ����ö�ٶ�������������������
	Status flag = Status::Ok;

	//Ĭ������£�ǿ����ö�ٶ���ĳ�Ա��������Ϊint����
	cout << sizeof(Status2::Ok) << endl;

	//3��ǿ����ö�٣�����ָ����Ա����������
	enum struct Status3 : char
	{
		Ok,
		Error
	};

	cout << sizeof(Status3::Ok) << endl;
	enum struct Status4 : long long
	{
		Ok,
		Error
	};

	cout << sizeof(Status4::Ok) << endl;
}
int main()
{
	test1();
	test2();
	return 0;
}