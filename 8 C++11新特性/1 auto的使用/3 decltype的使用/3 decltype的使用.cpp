#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <typeinfo>
#include <vector>

void test1()
{
	int i;
	decltype(i) j = 0;//通过i变量获取对应的类型，再定义变量

	cout << typeid(j).name() << endl;

	float a;
	double b;
	decltype(a + b) c;
	cout << typeid(j).name() << endl;

	vector<int> tmp;
	decltype(tmp.begin()) k;
	for (k = tmp.begin(); k != tmp.end(); k++)
	{
		//......
	}
	//auto是自动获取类型，decltype是先获取类型再使用这个类型定义变量

	enum
	{
		Ok,
		Error
	}flag;//flag是匿名枚举类型的变量
	//在C中，匿名结构体，匿名共用体，匿名枚举，只能创建一次变量，之后不能再创建变量
	decltype(flag) f;//decltype使得可以再创建变量
}
int main()
{
	return 0;
}