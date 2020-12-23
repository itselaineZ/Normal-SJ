/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("请输入年份(2000-2030)和月份(1-12) : ");
	int y, m, x, dy;
	scanf("%d%d", &y, &m);
	while (y < 2000 || y > 2030 || m < 1 || m > 12) {
		printf("输入错误，请重新输入\n");
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		scanf("%d%d", &y, &m);
	}
	printf("请输入2018年3月1日的星期(0-6表示星期日-星期六) : ");
	scanf("%d", &x);
	while (x < 0 || x > 6) {
		printf("输入错误，请重新输入\n");
		printf("请输入2018年3月1日的星期(0-6表示星期日-星期六) : ");
		scanf("%d", &x);
	}
	int i = 0; 
	while (i <= 6) {
		printf("星期");
		switch (i) {
			case 1: {
				printf("一  ");
				break;
			}
			case 2: {
				printf("二  ");
				break;
			}
			case 3: {
				printf("三  ");
				break;
			}
			case 4: {
				printf("四  ");
				break;
			}
			case 5: {
				printf("五  ");
				break;
			}
			case 6: {
				printf("六\n");
				break;
			}
			default: {
				printf("日  ");
				break;
			}
		}
		++ i;
	}
	if (m == 2) {
		if (y % 400 == 0 || (y % 100 && y % 4 == 0))
			dy = 29;
		else
			dy = 28;
	}
	else {
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			dy = 31;
		else
			dy = 30;
	}
	int tot = 0;
	if (x != 0) {
		printf("    ");
		i = 1;
		while (i < x){
			printf("        ");
			++ i;
		}
		i = x;
		while (i <= 6){
			printf("       %d", ++tot);
			++ i;
		}
		printf("\n");
	}
	while (tot < dy) {
		if (tot >= 9)
			printf("  %d", ++tot);
		else
			printf("   %d", ++ tot);
		i = 1;
		while (i <= 6 && tot < dy) {
			if (tot >= 9)
				printf("      %d", ++tot);
			else
				printf("       %d", ++tot);
			++ i;
		}
		printf("\n");
	}
	return 0;
}
