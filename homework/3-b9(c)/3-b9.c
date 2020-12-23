/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main() 
{
	printf("请输入年，月，日\n");
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	if (m > 12) {
		printf("输入错误-月份不正确\n");
		return 0;
	}
	if (m != 2) {
		if ((m & 1) && d > 31) {
			printf("输入错误-日与月的关系非法");
			return 0;
		}
		else if ((m & 1) == 0 && d > 30) {
			printf("输入错误-日与月的关系非法");
			return 0;
		}
	}
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100)) {
		if (m == 2) {
			if (d >= 29)
				printf("输入错误-日与月的关系非法");
			else 
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, 31+d);
		}
		else if (m == 1) 
			printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d);
		else if (m <= 7) {
			if (m & 1)
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, (m >> 1) * 61 - 1 + d);
			else
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, (m >> 1) * 61 - 1 - 30 + d);
		}
		else {
			if (m & 1)
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, 212 + ((m - 7) >> 1) * 61 - 1 + d);
			else
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, 212 + ((m - 7) >> 1) * 61 - 1 - 30 + d);
		}
	}
	else {
		if(m == 1)
			printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d);
		else if (m == 2) {
			if (d >= 29)
				printf("输入错误-日与月的关系非法");
			else 
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, 31 + d);
		}
		else if (m <= 7) {
			if (m & 1)
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, (m >> 1) * 61 - 2 + d);
			else
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, (m >> 1) * 61 - 2 - 30 + d);
		}
		else {
			if(m & 1)
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, 212 + ((m-7)>>1) * 61 - 30 + d);
			else 
				printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, 212 + ((m-7)>>1) * 61 + d);
		}
	}
	return 0;
}