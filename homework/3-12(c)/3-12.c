/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("������һ����������λ������\n");
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
	printf("%dλ��\n", cnt);
	printf("ÿλ���ֱַ��ǣ�\n");
	switch (cnt) {
		case 1: {
			printf("%d\n", a);
			printf("���������ÿλ���ֱַ��ǣ�\n");
			printf("%d\n", a);
			break;
		}
		case 2: {
			printf("%d %d\n", b, a);
			printf("���������ÿλ���ֱַ��ǣ�\n");
			printf("%d %d\n", a, b);
			break;
		}
		case 3: {
			printf("%d %d %d\n", c, b, a);
			printf("���������ÿλ���ֱַ��ǣ�\n");
			printf("%d %d %d\n", a, b, c);
			break;
		}
		case 4: {
			printf("%d %d %d %d\n", d, c, b, a);
			printf("���������ÿλ���ֱַ��ǣ�\n");
			printf("%d %d %d %d\n", a, b, c, d);
			break;
		}
		default: {
			printf("%d %d %d %d %d\n", e, d, c, b, a);
			printf("���������ÿλ���ֱַ��ǣ�\n");
			printf("%d %d %d %d %d\n", a, b, c, d, e);
			break;
		}
	}
	return 0;
}