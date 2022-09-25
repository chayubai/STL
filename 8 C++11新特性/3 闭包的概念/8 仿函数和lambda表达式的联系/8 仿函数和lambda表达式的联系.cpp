#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�º���������operator()
class MyFunctor
{
public:
    MyFunctor(int tmp) : round(tmp) {}
    int operator()(int tmp)
    {
        return tmp + round;
    }
private:
    int round;//״̬
};

void test1()
{
    int round = 2;
    MyFunctor f(round);//���ù��캯��
    cout << "result = " << f(10) << endl; //operator()(int tmp)
}
void test2()
{
    int round = 2;
    //lambda���ʽ
    auto f = [round](int tmp)
    {
        return round + tmp;
    };

    cout << "result = " << f(1) << endl;
    //��ʵ�ϣ��º����Ǳ�����ʵ��lambda��һ�ַ�ʽ��
    //ͨ�����������ǰ�lambda���ʽת��Ϊһ���º�������
    //��ˣ���C++11�У�lambda������Ϊ�º�����һ�ֵȼ���ʽ��
}
int main()
{

    return 0;
}
