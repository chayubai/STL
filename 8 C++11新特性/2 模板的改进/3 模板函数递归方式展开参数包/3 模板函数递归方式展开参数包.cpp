#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
//递归终止函数1
void debug()
{
	cout << "empty" << endl;
}
#endif

//递归终止函数2
template<class T>
void debug(T tmp)
{
	cout << "tmp = " << tmp << endl;
}

//可变参数的模板函数
//参数包展开函数
template<class T1,class...T2>
void debug(T1 first, T2...last)
{
	cout << first << endl;
	//递归调用函数本身
	debug(last...);
}

int main()
{
	//debug();//void debug()

	debug(1, 2, 3, 4);
	
	/*
	函数递归调用过程：
	debug(1, 2, 3, 4);
	debug(2, 3, 4);
	debug(3, 4);
	debug(4);
	debug();
	*/

	debug(1, "mike", 3.14, 'a');
	/*
	函数递归调用过程：
	debug(1, "mike", 3.14, 'a');
	debug("mike", 3.14, 'a');
	debug(3.14, 'a');
	debug('a');
	*/
	return 0;
}