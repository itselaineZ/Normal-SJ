/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main() 
{
	printf("�������꣬�£���\n");
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	if (m > 12) {
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}
	if (m != 2) {
		if ((m & 1) && d > 31) {
			printf("�������-�����µĹ�ϵ�Ƿ�");
			return 0;
		}
		else if ((m & 1) == 0 && d > 30) {
			printf("�������-�����µĹ�ϵ�Ƿ�");
			return 0;
		}
	}
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100)) {
		if (m == 2) {
			if (d >= 29)
				printf("�������-�����µĹ�ϵ�Ƿ�");
			else 
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, 31+d);
		}
		else if (m == 1) 
			printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, d);
		else if (m <= 7) {
			if (m & 1)
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, (m >> 1) * 61 - 1 + d);
			else
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, (m >> 1) * 61 - 1 - 30 + d);
		}
		else {
			if (m & 1)
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, 212 + ((m - 7) >> 1) * 61 - 1 + d);
			else
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, 212 + ((m - 7) >> 1) * 61 - 1 - 30 + d);
		}
	}
	else {
		if(m == 1)
			printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, d);
		else if (m == 2) {
			if (d >= 29)
				printf("�������-�����µĹ�ϵ�Ƿ�");
			else 
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, 31 + d);
		}
		else if (m <= 7) {
			if (m & 1)
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, (m >> 1) * 61 - 2 + d);
			else
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, (m >> 1) * 61 - 2 - 30 + d);
		}
		else {
			if(m & 1)
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, 212 + ((m-7)>>1) * 61 - 30 + d);
			else 
				printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, 212 + ((m-7)>>1) * 61 + d);
		}
	}
	return 0;
}