/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int Zeller(int y, int m, int d) {
	int c;
	if (m < 3) {
		m += 12;
		--y;
	}
	c = y / 100;
	y %= 100;
	return ((y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7 + 7) % 7;
}

int main()
{
	printf("请输入年份(1900-2100)、月份(1-12)和日期 : \n");
	int y, m, d;
	int flg = 1;
	do {
		while (scanf("%d%d%d", &y, &m, &d) != 3) {
			while (getchar() != '\n')
				;
			printf("输入错误，请重新输入:\n");
		}
		flg = 1;
		if (y < 1900 || y > 2100 || m < 1 || m > 12 || d < 1 || d > 31)
			flg = 0;
		if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
			flg = 0;
		if (m == 2) {
			if (!(y % 400 == 0 || (y % 100 && y % 4 == 0)) && d > 28)
				flg = 0;
		}
		if (!flg)
			printf("输入错误，请重新输入:\n");
	} while (!flg);
	int rt = Zeller(y, m, d);
	printf("星期");
	switch (rt) {
		case 0: {
			printf("日");
			break;
		}
		case 1: {
			printf("一");
			break;
		}
		case 2: {
			printf("二");
			break;
		}
		case 3: {
			printf("三");
			break;
		}
		case 4: {
			printf("四");
			break;
		}
		case 5: {
			printf("五");
			break;
		}
		case 6: {
			printf("六");
			break;
		}
	}
	printf("\n");
	return 0;
}