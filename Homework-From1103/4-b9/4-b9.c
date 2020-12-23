/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

void Divide(int x) {
	if (fabs(x) < 10) {
		if (x < 0)
			printf("%d -", -x);
		else
			printf("%d", x);
		return;
	}
	if (x < 0)
		printf("%d ", -x % 10);
	else
		printf("%d ", x % 10);
	Divide(x / 10);
}

int main()
{
	printf("请输入一个整数\n");
	int x;
	scanf("%d", &x);
	Divide(x);
	putchar('\n');
	return 0;
}