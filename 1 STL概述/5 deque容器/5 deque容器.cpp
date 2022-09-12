#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//deque������������һ��˫�����飬vector�ǵ�������
//�ײ��Ƕ�̬˳���֧��������ʣ��ֶ��������ڴ�ռ�
//�����ܽ�:
//˫�˲����ɾ��Ԫ��Ч�ʽϸ�.
//ָ��λ�ò���Ҳ�ᵼ������Ԫ���ƶ�,����Ч��.
//�������ȡ, Ч�ʸ�.

//deque������ʵ��ԭ���������ά���飬���������ָ�룬�ڲ�����Ԫ�أ��ڴ�Ԫ�ظ�����ͬ
//����Ҫͷ�����ݵ�ʱ�򣬷����һ���������ָ����ڲ������У�
//��ͷ��ռ䲻�㣬�ڵ�һ���������ǰ����ָ��
//����Ҫβ�����ݵ�ʱ�򣬷������һ���������ָ����ڴ�������
//��β��ռ䲻�㣬�����һ���������󿪱�ָ��

#include <deque>
//ע�⣺pos�ǵ�����ָ���λ�ã�begin�ǵ�����ָ��ĵ�һ��Ԫ�ص�λ�ã�end�ǵ�����ָ������һ��Ԫ�ص���һ��λ��

#if 0
1��deque���캯��
deque<T> deqT;//Ĭ�Ϲ�����ʽ
deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
deque(n, elem);//���캯����n��elem����������
deque(const deque& deq);//�������캯����
#endif

#if 0
2��deque��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
deque& operator=(const deque& deq); //���صȺŲ����� 
swap(deq);// ��deq�뱾���Ԫ�ػ���


#endif

#if 0
3��deque��С����
deque.size();//����������Ԫ�صĸ���
deque.empty();//�ж������Ƿ�Ϊ��
deque.resize(num);//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ��,���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
#endif
void printDeque(const deque<int> &d)
{
	//iterator ��ͨ������
	//reverse_iterator ���������
	//const_iterator ֻ��������
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 1000;//ʹ��const����d����ֹ*d.�����������
		//ע�⣺������ʹ��const_iterator
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	deque<int> d2;
	d2 = d;// = ��ֵ

	printDeque(d2);

	if (d2.empty())
	{
		cout << "d2Ϊ��" << endl;
	}
	else
	{
		cout << "d2��Ϊ�գ���СΪ��" << d2.size() << endl;
	}

	deque<int> d3(d);//��������

	printDeque(d3);
}

#if 0
4��deque˫�˲����ɾ������
push_back(elem);//������β�����һ������
push_front(elem);//������ͷ������һ������
pop_back();//ɾ���������һ������
pop_front();//ɾ��������һ������

#if 0
5��deque���ݴ�ȡ
at(idx);//��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
operator[];//��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
front();//���ص�һ�����ݡ�
back();//�������һ������
#endif
#endif
void test2()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	d.push_front(40);
	d.push_front(50);
	printDeque(d);

	//ע������pop_front()��pop_back()û�з���ֵ��ɾ��ǰ��Ҫȷ���Ƿ����Լ���Ҫɾ����ֵ
	int val = d.front();
	d.pop_front();
	printDeque(d);

	//ע������pop_front()��pop_back()û�з���ֵ��ɾ��ǰ��Ҫȷ���Ƿ����Լ���Ҫɾ����ֵ
	val = d.back();
	d.pop_back();
	printDeque(d);

	cout << d.front() << endl;
	cout << d.back() << endl;

}
#if 0
6��deque������� posΪ������
insert(pos, elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
#endif

#if 0
7��dequeɾ������
clear();//�Ƴ���������������
erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
#endif
void test3()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	d.push_back(40);
	d.push_front(30);
	
	printDeque(d);

	//d.insert(d.begin(), 100);
	//d.insert(d.begin(), 2,100);
	//printDeque(d);

	//d.insert(d.begin()++, 2, 100);
	printDeque(d);

	//ע�⣺ʹ��ǰ��++�������ݣ�������ȷ����
	d.insert(++d.begin(), 2, 100);
	printDeque(d);

	//������100ɾ��
	//d.erase(++d.begin());
	//d.erase(++d.begin());
	//printDeque(d);
	
	//erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	d.erase(d.begin()+1, d.begin() + 3);//ע��end�ǿ�����
	printDeque(d);
}
int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}