/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int Peach(int n, int rt) {
	if (n == 1)
		return rt;
	return Peach(n-1, (rt+1)*2);
}

int main()
{
	printf("������ڼ���������Ϊ1\n");
	int n;
	scanf("%d", &n);
	printf("��1���������=%d", Peach(n, 1));
	return 0;
}