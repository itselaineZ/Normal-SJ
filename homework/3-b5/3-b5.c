/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	double x, y;
	printf("请输入坐标:\n");
	scanf("%lf%lf", &x, &y);
	printf("该点高度为：\n");
	if (!x && !y)
		printf("0\n");
	if (x > 0 && y > 0) {
		if (x + y - 3 < 0)
			printf("1\n");
		else
			printf("0\n");
	}
	if (x > 0 && y < 0) {
		if (x - y - 3 < 0)
			printf("4\n");
		else
			printf("0\n");
	}
	if (x < 0 && y > 0) {
		if (x - y + 3 > 0)
			printf("2\n");
		else
			printf("0\n");
	}
	if (x < 0 && y < 0) {
		if (x + y + 3 > 0)
			printf("3\n");
		else
			printf("0\n");
	}
	return 0;
}
