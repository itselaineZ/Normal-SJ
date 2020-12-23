/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main() 
{
	printf("请输入当月利润：\n");
	int x;
	scanf("%d", &x);
	printf("应发奖金数：\n");
	if (x <= 100000)
		printf("%d\n", (int)(0.1 * x));
	else if (x <= 200000)
		printf("%d\n", (int)(10000 + (x - 100000.0)*0.075));
	else if (x <= 400000)
		printf("%d\n", (int)(17500 + (x - 200000.0)*0.05));
	else if (x <= 600000)
		printf("%d\n", (int)(27500 + (x - 400000.0)*0.03));
	else if (x <= 1000000)
		printf("%d\n", (int)(27500 + (x - 600000.0)*0.015));
	else
		printf("%d\n", (int)(33500 + (x - 1000000.0)*0.01));
	return 0;
 }