/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("请输入一个不超过五位的整数\n");
	int x, a, b, c, d, e;
	a = b = c = d = e = 0;
	scanf("%d", &x);
	int cnt = 0;
	if (x) {
		++cnt;
		a = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		b = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		c = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		d = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		e = x % 10;
		x /= 10;
	}
	printf("%d位数\n", cnt);
	printf("每位数字分别是：\n");
	switch (cnt) {
		case 1: {
			printf("%d\n", a);
			printf("逆序输出的每位数字分别是：\n");
			printf("%d\n", a);
			break;
		}
		case 2: {
			printf("%d %d\n", b, a);
			printf("逆序输出的每位数字分别是：\n");
			printf("%d %d\n", a, b);
			break;
		}
		case 3: {
			printf("%d %d %d\n", c, b, a);
			printf("逆序输出的每位数字分别是：\n");
			printf("%d %d %d\n", a, b, c);
			break;
		}
		case 4: {
			printf("%d %d %d %d\n", d, c, b, a);
			printf("逆序输出的每位数字分别是：\n");
			printf("%d %d %d %d\n", a, b, c, d);
			break;
		}
		default: {
			printf("%d %d %d %d %d\n", e, d, c, b, a);
			printf("逆序输出的每位数字分别是：\n");
			printf("%d %d %d %d %d\n", a, b, c, d, e);
			break;
		}
	}
	return 0;
}