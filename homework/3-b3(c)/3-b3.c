/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define eps 0.0001

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	double a;
	scanf("%lf", &a);
	printf("ʮ��λ : %d\n", (int)(a / 1e9) % 10);
	a -= (int)(a / 1e9) * 1e9;
	printf("��λ   : %d\n", (int)(a / 1e8) % 10);
	a -= (int)(a / 1e8) * 1e8;
	printf("ǧ��λ : %d\n", (int)(a / 1e7) % 10);
	a -= (int)(a / 1e7) * 1e7;
	printf("����λ : %d\n", (int)(a / 1e6) % 10);
	a -= (int)(a / 1e6) * 1e6;
	printf("ʮ��λ : %d\n", (int)(a / 1e5) % 10);
	a -= (int)(a / 1e5) * 1e5;
	printf("��λ   : %d\n", (int)(a / 1e4) % 10);
	a -= (int)(a / 1e4) * 1e4;
	printf("ǧλ   : %d\n", (int)(a / 1e3) % 10);
	a -= (int)(a / 1e3) * 1e3;
	printf("��λ   : %d\n", (int)(a / 100) % 10);
	a -= (int)(a / 1e2) * 1e2;
	printf("ʮλ   : %d\n", (int)(a / 10) % 10);
	a -= (int)(a / 10.0) * 10.0;
	printf("Բ     : %d\n", (int)(a));
	a -= (int)(a);
	printf("��     : %d\n", (int)((a + eps)*10));
	a -= (int)((a + eps) / 0.1) * 0.1;
	printf("��     : %d\n", (int)((a + eps)*100));
	return 0;
}
/*
8307238123.07
9999999999.99
9999999999.90
9999999999.09
9900000000
8912003005.78
2501200350.03
1203056740.00
203056740.20
23000056.82
3051200.72
301000.35
10001.34
8070.23
9876.54
803.03
12.30
10.03
9.30
7.03
0.35
0.30
0.07
0.03
0

*/