/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

const int MAXINT = 0x3f3f3f3f;
const double eps = 0.000000001;

double a, b, c, delta;

void Case1()
{
	printf("不是一元二次方程\n");
}

void Case2()
{
	delta = sqrt(delta);
	printf("有两个相等实根：\n");
	printf("x1=x2=%lf\n", -b / (2 * a));
}

void Case3()
{
	delta = sqrt(-delta);
	printf("有两个虚根：\n");
	double xx = delta / (2 * a);
	if ((b < eps && b >= 0) || (b <= 0 && b > eps)) {
		if ((xx - 1.0 < eps && xx - 1.0 >= 0) || (xx - 1.0 > eps&& xx - 1.0 <= 0)) {
			printf("x1=i");
			printf("x2=-i");
		}
		else {
			printf("x1=%lfi\n", xx);
			printf("x2=-%lfi\n", xx);
		}
	}
	else {
		printf("x1=%lf+%lfi\n", -b / (2 * a), delta / (2 * a));
		printf("x2=%lf-%lfi\n", -b / (2 * a), delta / (2 * a));
	}
}

void Case4()
{
	delta = sqrt(delta);
	printf("有两个不相等实根：\n");
	printf("x1=%lf", (-b + delta) / (2 * a));
	printf("x2=%lf", (-b - delta) / (2 * a));
}

int main()
{
	printf("请输入一元二次方程的三个系数：\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a < 0)
		a = -a, b = -b, c = -c;
	delta = b * b - 4.0 * a * c;
	if (a < eps)
		Case1();
	else if (delta < eps && delta >= 0.0)
		Case2();
	else if (delta < 0)
		Case3();
	else
		Case4();
	return 0;
}