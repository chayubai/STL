#define _CRT_SECURE_NO_WARNINGS 1
/*
����ת�������������ĳ�������Ҫ��һ�����ԭ�ⲻ���Ĵ��ݸ���һ��������
��ԭ�ⲻ�����������ǲ�����ֵ���䣬�� C++ �У����˲���ֵ֮�⣬
���������������ԣ���ֵ����ֵ�� const/non-const��
����ת�������ڲ������ݹ����У�������Щ���ԺͲ���ֵ�����ܸı䣬
ͬʱ��������������Ŀ������ͺ���ת���߲�����һ�����ڷ��ͺ����У�����������ǳ��ձ顣

��ͨ������ת�����β�Ϊ��ֵ�������ʵ��Ҳ����ֵ���β�Ϊ��ֵ�������ʵ��Ҳ����ֵ
�β�Ϊconstֵ�������ʵ��Ҳ��constֵ���β�Ϊ��constֵ�������ʵ��Ҳ�Ƿ�constֵ
*/

#include <iostream>
using namespace std;

#if 0
template<class T> void func(const T&)
{
	cout << "const T&" << endl;
}

template<class T> void func(T&)
{
	cout << "T&" << endl;
}

template<class T> void forward_val(const T& tmp)//const T&�汾
{
	func(tmp);
}

template<class T> void forward_val(T& tmp)//T&�汾
{
	func(tmp);
}

void test1()
{
	int a = 0;
	const int& b = 1;

	//��Ҫ���������汾
	forward_val(a);//aΪ��ֵ������forward_val(T& tmp)
	forward_val(b);//bΪconst���ã�forward_val(const T& tmp)
	forward_val(111);//bΪconst���ã�forward_val(const T& tmp)

	//����ÿһ��func(tmp)�����β����Ͳ�ͬ����Ҫ�ṩһ��forward_val()�������أ�ֻ���β����Ͳ�ͬ�����඼��ͬ�����´������ܴ�

	//Ϊ�˼��ٴ����������ʵ�ַ���������ת���� -- �����۵�
}
#endif

template<class T> void func(const T&)
{
	cout << "const T&" << endl;
}

template<class T> void func(T&)
{
	cout << "T&" << endl;
}

template<class T> void func(T&&)
{
	cout << "T&&" << endl;
}

template <typename T> void func(const T&& val)
{
	cout << "const T &&" << endl;
}

template<class T> void forward_val(T&& tmp)//����Ϊ��ֵ����
{
	//std::forward����ģ������ã����ֲ�������ֵ����ֵ����
	func( std::forward<T>(tmp) );
}

void test2()
{
	int a = 0;
	const int& b = 1;

	forward_val(a);//aΪ��ֵ������func(T&)
	forward_val(b);//bΪconst���ã�func(const T&)
	forward_val(111);//func(T&&)�����û��void func(T&&)�����func(const T&)
	forward_val( std::move(b) );//const T &&
}
int main()
{
	//test1();
	test2();

	return 0;
}
/*
test(T&)
{
	func(TR&)
}

TR�����Ͷ���	����v������		v��ʵ������
T &				TR				T &
T &				TR &			T &
T &				TR &&			T &
T &&			TR				T &&
T &&			TR &			T &
T &&			TR &&			T &&
һ�������г�������ֵ���ã������۵��������Ƚ����۵�Ϊ��ֵ����
*/