#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//vector������������һ����̬�����飨��̬˳�����ÿ�ζ�̬���ٵĿռ䲻�ǰ�2���Ĵ�С����
//�ײ��Ƕ�̬˳���֧���������

//��ν��̬���Ӵ�С����������ԭ�ռ�֮�������¿ռ�(��Ϊ�޷���֤ԭ�ռ�֮�����п����õĿռ�)��
//����һ�������ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬���ͷ�ԭ�ռ䡣
//��ˣ���vector���κβ�����һ������ռ���������ã�ָ��ԭvector�����е������Ͷ�ʧЧ�ˡ�
//���ǳ���Ա���׷���һ���������С�ġ�

//�����ܽ�:
//vector�Ƕ�̬���飬�����ڴ�ռ䣬���������ȡЧ�ʸߵ��ŵ㡣
//vector�ǵ����������ڶ�β�����ɾ��Ԫ��Ч�ʸߣ���ָ��λ�ò���ᵼ������Ԫ���ƶ�,Ч�ʵ͡�
void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
}
//ע�⣺pos�ǵ�����ָ���λ�ã�begin�ǵ�����ָ��ĵ�һ��Ԫ�ص�λ�ã�end�ǵ�����ָ������һ��Ԫ�ص���һ��λ��

#if 0
1��vector���캯��
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector& vec);//�������캯����

//���� ʹ�õ�2�����캯�� ���ǿ���...
int arr[] = { 2,3,4,1,9 };
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
#endif
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(v1.begin(), v1.end());//�����вι���
	printVector(v2);

	vector<int> v3(v2);//���ÿ�������
	printVector(v3);

	int arr[] = { 10,20,30,40,50 };
	vector<int> v4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> v5(v4.begin(), v4.end());
	printVector(v4);
}

#if 0
2��vector���ø�ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector& operator=(const vector& vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����
#endif
void test2()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.assign(v1.begin(), v1.end());//�����вι���
	printVector(v2);

	vector<int> v3(10,100);//vector(n, elem);//���캯����n��elem����������
	printVector(v3);
	
	cout << "�������v2��v3��" << endl;
	v3.swap(v2);//����������ָ����н���
	printVector(v2);
	printVector(v3);
}

#if 0
3��vector��С����
size();//����������Ԫ�صĸ���
boo1 empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
//ע�⣺reverse��ת
#endif
void test3()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	if (v1.empty())//����v1.size()=0
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ�գ���СΪ��" << v1.size() << endl;
	}

	v1.resize(10);//���ô�С
	printVector(v1);//Ĭ�����0

	v1.resize(3);
	printVector(v1);//�����ɾ��

	v1.resize(10, 100);
	printVector(v1);//ָ�����ֵ
}

#if 0
4��vector���ݴ�ȡ����
at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��
#endif
void test4()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << v1.front() << endl;
	cout << v1.back() << endl;
}

#if 0
5��vector�����ɾ������
insert(const_iterator pos, int count, ele);//������ָ��λ��pos����count��Ԫ��ele.
push_back(ele); //β������Ԫ��ele
pop_back();//ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��
//ע�⣺string������ɾ����string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ� 
#endif
void test5()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	//v1.insert(v1.begin(), 100);//����1��100
	v1.insert(v1.begin(), 2, 100);//����2��100

	v1.insert(v1.begin()+2,100);//vector��������֧���������
	//֧�������±꣬һ�㶼֧���������
	printVector(v1);

	v1.push_back(1000);
	printVector(v1);

	v1.pop_back();
	printVector(v1);

	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin(),v1.end());//�ȼ�clear()
	v1.clear();
	printVector(v1);
}

//����1������swap�����ڴ�
void test6()
{
	//vector���Ԫ�ػ������Զ�����������ɾ��Ԫ�����������Զ�����
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;

	//��ʱ ͨ��resize�ı�������С
	v.resize(10);

	cout << "capacity:" << v.capacity() << endl;//����û�иı䣬��ɿռ��˷�
	cout << "size:" << v.size() << endl;

	//�����ռ�
	vector<int>(v).swap(v);//v.resize(10);��ǰʮ�����ݱ���������vector<int>(v)ʹ��v.size��С��ʼ����������
	//��������.swap(v)��ͨ���������������ǽ���ָ�룩������������ִ���ָ꣬��������Զ��ͷ�
	cout << "capacity:" << v.capacity() << endl;
	cout << "size:" << v.size() << endl;
}

//����2������reserveԤ���ռ�
void test7()
{
	vector<int> v;

	//Ԥ�ȿ��ٿռ䣬û����һ�У���Ҫ����30�Σ����ܴ�100000������
	v.reserve(100000);//���ٶ�̬���ٴ���������

	int* pStart = NULL;
	int count = 0;
	for (int i = 0; i < 100000; i++) 
	{
		v.push_back(i);//��̬�����ǣ�������һ��ռ�
		if (pStart != &v[0])//ֻҪ�����¿ռ䣬pStart�Ͳ�һ��
		{
			pStart = &v[0];
			count++;//�����ܹ����ٵĶ��ٴοռ�
		}
	}

	cout << "count:" << count << endl;
	//�����֪���������Ҫ�洢��Ԫ�ظ�������ô������ǰԤ���ռ�
}

#include <list>
void test8()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//ע�⣺ʹ�����������reverse_iterator  it++
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << endl;
	}
	//vector�ĵ�������������ʵ�������֧����Ծ����
	vector<int>::iterator itBegin = v.begin();
	itBegin += 3;
	//С���ɣ�
	//ͨ��������+num�ж��Ƿ�֧����Ծ����

	cout << *itBegin << endl;//40

	//erase(const_iterator pos);//ɾ��������ָ���Ԫ��
	v.erase(v.begin() + 3);
	printVector(v);

#if 0
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	list<int>::iterator itBegin = l.begin();
	//֧��˫�����
	itBegin++;
	itBegin--;
	//itBegin = itBegin + 3;//list�������ǲ�֧��������ʵģ�����
#endif 
}

int main()
{
	//test6();
	//test7();
	test8();
	return 0;
}