#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <functional>
using namespace std::placeholders;
class Test
{
public:
	void func(int x, int y)
	{
		cout << x << " " << y << endl;
	}
	int a;
};
int main()
{
	Test obj;//��������

	//�󶨳�Ա����
	function<void(int, int)> f1 = bind(&Test::func, &obj, _1, _2);

	f1(11, 22);//�ȼ��� obj.func(11,22);

	//�󶨳�Ա����
	function<int& ()> f2 = bind(&Test::a, &obj);
	f2() = 111;//�ȼ���obj.a = 111;
	cout << "obj.a = " << obj.a << endl;

	return 0;
}