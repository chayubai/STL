#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
using namespace std;

//Stack����Ԫ�صĽ�����������ϡ��Ƚ��������������ֻ��stack���˵�Ԫ�أ����л��ᱻ���ȡ�á�
//Stack���ṩ�������ܣ�Ҳ���ṩ��������
//����ʱ������empty��pop����ʹ��

//stack�������������Ƕ�̬���� ע�⣺vectorҲ��һ����̬���飬�������������ṩ�ĺ����ӿ���������
//�����ܽ�:
//ջ���ܱ�������֧�������ȡ,ֻ��ͨ��top��ջ����ȡ��ɾ��Ԫ��. .

#if 0
1��stack���캯��
stack<T> stkT;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ�� 
stack(const stack& stk);//�������캯��
2��stack��ֵ����
stack & operator=(const stack & stk);//���صȺŲ�����
3��stack���ݴ�ȡ����
push(elem);//��ջ�����Ԫ��
pop();//��ջ���Ƴ���һ��Ԫ��
top();//����ջ��Ԫ��
4��stack��С����
empty();//�ж϶�ջ�Ƿ�Ϊ��
size();//���ض�ջ�Ĵ�С
#endif 

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	//s[1];��֧���������
	cout << "size = " << s.size() << endl;
	//���Ҫ���ʷ�ջ����Ԫ�أ���Ҫ��pop��ջ����Ԫ��
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << "size = " << s.size() << endl;

	return 0;
}

//����1 ջ������Ŷ���ָ��
//��ҵ2 ջ������Ŷ���