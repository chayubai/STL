#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

# if 0
int main()
{
	int a = 1024;
	char b = a;//数据丢失，就叫做类型收窄
	printf("b = %d\n", b);//可以正常打印，但数据不一致，数据精度丢失了

	return 0;
}
#endif