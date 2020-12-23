/*1952339 信08 张馨月*/
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
	printf("请输入第几天桃子数为1\n");
	int n;
	scanf("%d", &n);
	printf("第1天的桃子数=%d", Peach(n, 1));
	return 0;
}