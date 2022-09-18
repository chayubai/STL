#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 1024;
	char b = { a };//类型收窄。无法编译通过，报错：从“int”转换到“char”需要收缩转换

	cout << "b = " << b << endl;
	//因此使用列表初始化，可以防止了类型收窄

	return 0;
}

//注意：并不是所有的编译器都会防止类型收窄，qt可以编译通过