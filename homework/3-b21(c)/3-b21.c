/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif 

int main()
{
	int x;
	char c;

	while (1) {
		printf("������x��ֵ(0-100)��");
		while (scanf("%d", &x) != 1 || x < -100 || x > 100) {
			c = getchar();
		}
		if (x >= -100 && x <= 100)
			break;
	}
	if (c == '-')
		x = -x;

	printf("x=%d\n", x);

	return 0;
}
