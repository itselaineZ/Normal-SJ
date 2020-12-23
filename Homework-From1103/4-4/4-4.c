/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int Cal(int x) {
	if (x == 1)
		return 1;
	return x * Cal(x - 1);
}

int main()
{
	int a, b, c;
	printf("计算a!+b!+c!，请输入a,b,c的值(非负整数)\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("%d!+%d!+%d!=%d\n", a, b, c, Cal(a)+Cal(b)+Cal(c));
	return 0;
}