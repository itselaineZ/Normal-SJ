/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	printf("���������(2000-2030)���·�(1-12) : ");
	int y, m, x, dy;
	scanf("%d%d", &y, &m);
	while (y < 2000 || y > 2030 || m < 1 || m > 12) {
		printf("�����������������\n");
		printf("���������(2000-2030)���·�(1-12) : ");
		scanf("%d%d", &y, &m);
	}
	printf("������2018��3��1�յ�����(0-6��ʾ������-������) : ");
	scanf("%d", &x);
	while (x < 0 || x > 6) {
		printf("�����������������\n");
		printf("������2018��3��1�յ�����(0-6��ʾ������-������) : ");
		scanf("%d", &x);
	}
	int i = 0; 
	while (i <= 6) {
		printf("����");
		switch (i) {
			case 1: {
				printf("һ  ");
				break;
			}
			case 2: {
				printf("��  ");
				break;
			}
			case 3: {
				printf("��  ");
				break;
			}
			case 4: {
				printf("��  ");
				break;
			}
			case 5: {
				printf("��  ");
				break;
			}
			case 6: {
				printf("��\n");
				break;
			}
			default: {
				printf("��  ");
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
