#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//C++ 11����������̳л���Ĺ��캯����Ĭ�Ϲ��캯�������ƹ��캯�����ƶ����캯�����⣩��
#if 0
class A
{
public:
    A(int i) { cout << "i = " << i << endl; }
    A(double d, int i) {}
    A(float f, int i, const char* c) {}
    // ...
};

class B : public A
{
public:
    using A::A; // �̳й��캯��
    // ...
    virtual void ExtraInterface() {}
};
#endif
class A
{
public:
    A(int x, int y)
    {
        a = x;
        b = y;
    }
protected:
    int a;
    int b;
};

class B :public A
{
public:
#if 0
    //1��ͨ�������б�����๹�캯������
    B(int x, int y) :A(x, y)
    {

    }
#endif

    //2���ȼ�usingָ��
    using A::A;//�̳��вι��캯��

    void dispaly()
    {
        cout << "a = " << a << ", b=" << b << endl;
    }
    //û�������µĳ�Ա����

    //������������ĳ�Ա����������ʹ���вι����ʼ��
};

//ע�⣺
//1���̳еĹ��캯��ֻ�ܳ�ʼ�������еĳ�Ա���������ܳ�ʼ��������ĳ�Ա����
//2���������Ĺ��캯��������Ϊ˽�У������������Ǵӻ�������̳У���ô���ܼ̳й��캯��
//3��һ��ʹ�ü̳й��캯����������������Ϊ����������Ĭ�Ϲ��캯��

int main()
{
    //B b;//��Bû�й��캯��ʱ���ᱨ����Ϊb�̳���A�����ԣ�û�ж�A���г�ʼ��
    B b(10,20);
    b.dispaly();
	return 0;
}