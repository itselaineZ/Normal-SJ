/*1952339 ��08 ��ܰ��*/
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
	printf("�������꣬�£���\n");
	while (scanf("%d%d%d", &X.y, &X.m, &X.d) != 3) {
		while (getchar() != '\n')
			;
		printf("�������꣬�£���\n");
	}
	int ans = days(&X);
	if (ans == -1)
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
	else if (ans == 0)
		printf("�������-�·ݲ���ȷ\n");
	else
		printf("%d-%d-%d��%d��ĵ�%d��\n", X.y, X.m, X.d, X.y, ans);
	return 0;
}
