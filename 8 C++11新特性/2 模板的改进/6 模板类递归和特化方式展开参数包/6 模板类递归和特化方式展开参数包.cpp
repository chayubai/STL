#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�̳з�ʽ�ݹ鷽ʽչ���ɱ����ģ����
//1���䳤ģ���ඨ��
//2���߽��������
//3���䳤ģ��������

//3���䳤ģ��������
template<int...last>
class Test
{
};

//1���䳤ģ���ඨ��
template<int first,int...last>
class Test<first, last...>
{
public:
	static const int val = first * Test<last...>::val;
};

//2���߽��������
template<> 
class Test<> 
{
public:
	static const int val = 1;
};

int main()
{
	cout << Test<2, 3, 4, 5>::val << endl;
	/*
	Test<2, 3, 4, 5>::val
	Test<3, 4, 5>::val
	Test<4, 5>::val
	Test<5>::val
	Test<>::val

	�����2 * 3 * 4 * 5 * 1
	*/
	return 0;
}