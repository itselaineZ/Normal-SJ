/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	int a;
	scanf("%d", &a);
	printf("万位 : %d\n", a / 10000);
	printf("千位 : %d\n", a / 1000 % 10);
	printf("百位 : %d\n", a / 100 % 10);
	printf("十位 : %d\n", a / 10 % 10);
	printf("个位 : %d\n", a % 10);
	return 0;
}