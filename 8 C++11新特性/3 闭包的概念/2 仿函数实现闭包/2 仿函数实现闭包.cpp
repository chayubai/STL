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

int main()
{
    int round = 2;
    MyFunctor f(round);//���ù��캯��
    cout << "result = " << f(10) << endl; //operator()(int tmp)

    return 0;
}
