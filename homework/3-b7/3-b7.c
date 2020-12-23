/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("请输入三角形的三条边长度\n");
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a >= b + c || b >= a + c || c >= a + b)
		printf("不构成三角形\n");
	else {
		double p = (a + b + c) / 2;
		printf("三角形的面积 : %lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	return 0;
}
