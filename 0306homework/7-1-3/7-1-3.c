/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

struct date{
	int y, m, d;
};

int days(struct date *X)
{
	int mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((X->y % 100 && X->y % 4 == 0) || (X->y % 400 == 0))
		++mth[2];
	if (X->m > 12 || X->m < 1)
		return 0;
	if (X->d > mth[X->m])
		return -1;
	int cnt = X->d;
	int i = 1; 
	while (i < X->m){
		cnt += mth[i];
		++ i;
	}
	return cnt;
}

int main()
{
	struct date X;
	printf("请输入年，月，日\n");
	while (scanf("%d%d%d", &X.y, &X.m, &X.d) != 3) {
		while (getchar() != '\n')
			;
		printf("请输入年，月，日\n");
	}
	int ans = days(&X);
	if (ans == -1)
		printf("输入错误-日与月的关系非法\n");
	else if (ans == 0)
		printf("输入错误-月份不正确\n");
	else
		printf("%d-%d-%d是%d年的第%d天\n", X.y, X.m, X.d, X.y, ans);
	return 0;
}
