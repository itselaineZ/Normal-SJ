/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

#define pi 3.14159

int main()
{
	printf("�����������ε����߼���нǣ��Ƕȣ�: ");
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("���������Ϊ : %.3lf\n", 0.5 * a * b * sin(c / 180.0 * pi));
	return 0;
}