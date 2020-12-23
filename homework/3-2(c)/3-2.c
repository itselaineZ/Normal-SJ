/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("请输入半径和高度\n");
	int r, h;
	scanf("%d%d", &r, &h);
	printf("圆周长     : %.2lf\n", 2*pi*r);
	printf("圆面积     : %.2lf\n", pi*r*r);
	printf("圆球表面积 : %.2lf\n", 4*pi*r*r);
	printf("圆球体积   : %.2lf\n", 4.0/3*pi*r*r*r);
	printf("圆柱体积   : %.2lf\n", pi*r*r*h);
	return 0;
}