/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("����������������n(10-20)\n");
	int n;
	scanf("%d", &n);
	int a[25] = {0};
	printf("������%d������\n", n);
	int i = 0;
	while (i < n) {
		scanf("%d", a+i);
		++ i;
	}
	printf("�������������Ϊ\n");
	printf("%d", *a);
	i = 1;
	while (i < n) {
		printf(" %d", *(a + i));
		++i;
	}
	putchar(10);
	printf("����������ƶ���λ��m(1~2^31-1)\n");
	int m;
	scanf("%d", &m);
	printf("�ƶ������������Ϊ\n");
	m = m % n;
	while (m--) {
		int t = *(a + n - 1);
		i = n - 2;
		while (i >= 0) {
			*(a + i + 1) = *(a + i);
			--i;
		}
		*a = t;
	}
	i = 0;
	while(i < n) {
		printf("%d", *(a + i));
		if (i != n - 1)
			putchar(32);
		++i;
	}
	putchar(10);
	return 0;
}
