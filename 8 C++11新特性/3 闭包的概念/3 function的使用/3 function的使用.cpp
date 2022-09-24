#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <functional> //std::function
void func(void)
{//��ͨȫ�ֺ���
    cout << __func__ << endl;
}

class Test
{
public:
    static int test_func(int a)
    {//���о�̬����
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

class MyFunctor
{
public:
    int operator()(int a)
    {//�º���
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

int main()
{
    //function< ��������(�β��б�����) >
    
    //��һ����ͨ����
    function< void(void) > f1 = func;//f1�����뺯��ָ��
    f1();//�ȼ���func()

    //�����еľ�̬����
    function< int(int) > f2 = Test::test_func;
    cout << f2(111) << endl;//�ȼ���Test::test_func(111)

    //��һ���º������󶨶��󣬷º�������obj()
    MyFunctor obj;
    function< int(int) > f3 = obj;
    cout << f3(222) << endl;////�ȼ���obj(222)

    /*
   std::function���������ô�������ʵ�ֺ����ص���
   ʹ������Ҫע�⣬�����ܱ����������Ȼ��߲���ȣ�
   ���ǿ�����NULL����nullptr���бȽϡ�
    */

    return 0;
}
