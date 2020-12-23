/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("请输入华氏温度\n");
	int F;
	scanf("%d", &F);
	printf("摄氏温度 : %.2lf\n", 5.0 / 9.0 * (F - 32.0));
	return 0;
}