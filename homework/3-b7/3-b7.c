/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("�����������ε������߳���\n");
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a >= b + c || b >= a + c || c >= a + b)
		printf("������������\n");
	else {
		double p = (a + b + c) / 2;
		printf("�����ε���� : %lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	return 0;
}
