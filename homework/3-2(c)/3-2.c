/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("������뾶�͸߶�\n");
	int r, h;
	scanf("%d%d", &r, &h);
	printf("Բ�ܳ�     : %.2lf\n", 2*pi*r);
	printf("Բ���     : %.2lf\n", pi*r*r);
	printf("Բ������ : %.2lf\n", 4*pi*r*r);
	printf("Բ�����   : %.2lf\n", 4.0/3*pi*r*r*r);
	printf("Բ�����   : %.2lf\n", pi*r*r*h);
	return 0;
}