/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int Cal(int x) {
	if (x == 1)
		return 1;
	return x * Cal(x - 1);
}

int main()
{
	int a, b, c;
	printf("����a!+b!+c!��������a,b,c��ֵ(�Ǹ�����)\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("%d!+%d!+%d!=%d\n", a, b, c, Cal(a)+Cal(b)+Cal(c));
	return 0;
}