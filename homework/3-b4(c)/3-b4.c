/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

#define pi 3.14159

int main()
{
	printf("请输入三角形的两边及其夹角（角度）: ");
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("三角形面积为 : %.3lf\n", 0.5 * a * b * sin(c / 180.0 * pi));
	return 0;
}