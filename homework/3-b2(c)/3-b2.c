/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	int a;
	scanf("%d", &a);
	printf("��λ : %d\n", a / 10000);
	printf("ǧλ : %d\n", a / 1000 % 10);
	printf("��λ : %d\n", a / 100 % 10);
	printf("ʮλ : %d\n", a / 10 % 10);
	printf("��λ : %d\n", a % 10);
	return 0;
}