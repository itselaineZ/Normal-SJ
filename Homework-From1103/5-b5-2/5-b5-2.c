/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int p[3];
int stk[3][10];

void Print_int(int x, int num)
{
	if (num == 4) {
		if (x < 10)
			printf("   %d", x);
		else if (x < 100)
			printf("  %d", x);
		else if (x < 1000)
			printf(" %d", x);
		else 
			printf("%d", x);
	}
	else {
		if (x < 10)
			printf(" %d", x);
		else
			printf("%d", x);
	}
}

void cout_table(char st_pos, char ed_pos,int stp)
{
	printf("第");
	Print_int(stp, 4);
	printf(" 步(");
	Print_int(stk[st_pos-'A'][p[st_pos-'A']], 2);
	printf("):");
	printf(" %c-->%c", st_pos, ed_pos);
	printf(" A:");
	int i = 0;
	while (i < p[0]) {
		Print_int(stk[0][i], 2);
		++i;
	}
	i = 20 - 2 * p[0];
	while (i) {
		putchar(32);
		--i;
	}
	printf(" B:");
	i = 0;
	while (i < p[1]) {
		Print_int(stk[1][i], 2);
		++i;
	}
	i = 20 - 2 * p[1];
	while (i) {
		putchar(32);
		--i;
	}
	printf(" C:");
	i = 0;
	while (i < p[2]) {
		Print_int(stk[2][i], 2);
		++i;
	}
	i = 20 - 2 * p[2];
	while (i) {
		putchar(32);
		--i;
	}
	putchar(10);
}

void stk_move(char st_pos, char ed_pos)
{
	st_pos -= 'A';
	ed_pos -= 'A';
	stk[1*ed_pos][p[1*ed_pos] ++] = stk[1*st_pos][--p[1*st_pos]];
}

int Hano(int n, char now_pos, char aim_pos, int stp)
{
	if (n == 0) {
		if (stp == -1)
			return 0;
		return stp;
	}
	char spare_pos = 65 + 66 + 67 - now_pos - aim_pos;
	stp = Hano(n - 1, now_pos, spare_pos, stp);
	++stp;
	stk_move(now_pos, aim_pos);
	cout_table(now_pos, aim_pos, stp);
	stp = Hano(n - 1, spare_pos, aim_pos, stp);
	return stp;
}

int main()
{
	printf("请输入汉诺塔的层数(1-10)：\n");
	int N;
	while (scanf("%d", &N) != 1 || N < 1 || N > 64) {
		while (getchar() != '\n')
			;
		printf("输入非法，请重新输入\n");
	}
	while (getchar() != '\n')
		;
	printf("请输入起始柱(A-C)：\n");
	char bgn, ed;
	while (scanf("%c", &bgn) != 1 || !((bgn >= 'a' && bgn <= 'c') || (bgn >= 'A' && bgn <= 'C'))) {
		while (getchar() != '\n')
			;
		putchar('*');
		printf("输入非法，请重新输入\n");
	}
	while (getchar() != '\n')
		;
	printf("请输入目标柱(A-C)：\n");
	while (scanf("%c", &ed) != 1 || !((ed >= 'a' && ed <= 'c') || (ed >= 'A' && ed <= 'C')) || ed == bgn) {
		while (getchar() != '\n')
			;
		printf("输入非法，请重新输入\n");
	}
	if (bgn > 'C')
		bgn -= 'a' - 'A';
	if (ed > 'C')
		ed -= 'a' - 'A';
	printf("初始:               ");
	bgn -= 'A';
	int i = N;
	while (i) {
		stk[1*bgn][p[1*bgn] ++] = i;
		--i;
	}
	printf(" A:");
	i = 0;
	while (i < p[0]) {
		Print_int(stk[0][i], 2);
		++i;
	}
	i = 20 - 2 * p[0];
	while (i) {
		putchar(32);
		--i;
	}
	printf(" B:");
	i = 0;
	while (i < p[1]) {
		Print_int(stk[1][i], 2);
		++i;
	}
	i = 20 - 2 * p[1];
	while (i) {
		putchar(32);
		--i;
	}
	printf(" C:");
	i = 0;
	while (i < p[2]) {
		Print_int(stk[2][i], 2);
		++i;
	}
	i = 20 - 2 * p[2];
	while (i) {
		putchar(32);
		--i;
	}
	printf("\n");
	bgn += 'A';
	Hano(N, bgn, ed, -1);
	return 0;
}