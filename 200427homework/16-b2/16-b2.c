/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000

typedef int ElemType;

typedef struct {
	ElemType data;
	int cur;
}space;

void InitSpace_SL(space* L)
{
	for (int i = 0; i < MAXN - 1; ++i)
		L[i].cur = i + 1;
	L[MAXN - 1].cur = 0;
}

void Free_SL(space* L, int k)
{
	L[k].cur = L[0].cur;
	L[0].cur = k;
}

int Malloc_SL(space* L)
{
	int i = L[0].cur;
	if (i)
		L[0].cur = L[i].cur;
	return i;
}

void Cout_SL(space* L, int S)
{
	int tot = 0;
	for (int i = L[S].cur; i; i = L[i].cur) {
		printf("%d->", L[i].data);
		if (tot == 9)
			tot = 0, putchar(10);
	}
}

void difference(space* La, space* Lb, space* L)
{
	InitSpace_SL(L);
	int S = Malloc_SL(L);
	int r = S;
	for (int j = La[0].cur; j; j = La[j].cur) {
		int i = Malloc_SL(L);
		L[i].data = La[j].data;
		L[r].cur = i;
		r = i;
	}
	L[r].cur = 0;
	int p, k;
	for (int j = Lb[0].cur; j; j = Lb[j].cur) {
		p = S;
		k = L[S].cur;
		while (k != L[r].cur && L[k].data != Lb[j].data) {
			p = k;
			k = L[k].cur;
		}
		if (k == L[r].cur) {
			int i = Malloc_SL(L);
			L[i].data = Lb[j].data;
			L[i].cur = L[r].cur;
			L[r].cur = i;
		}
		else {
			L[p].cur = L[k].cur;
			Free_SL(L, k);
			if (r == k)
				r = p;
		}
	}
}

int Keyboardin_SL(space* L)
{
	int x, N = 0;
	for (int i = 0; ; ) {
		scanf("%d", &x);
		if (x == -1) {
			L[i].cur = 0;
			break;
		}
		else {
			i = L[i].cur;
			L[i].data = x;
			++N;
		}
	}
	return N;
}

int main()
{
	space La[MAXN], Lb[MAXN], Lc[MAXN*2];
	InitSpace_SL(La);
	InitSpace_SL(Lb);
	printf("请输入La、Lb的内容（int型，以-1作为一个集合的结束标志）\n");
	Keyboardin_SL(La);
	Keyboardin_SL(Lb);
	printf("\n\nLa的内容为：\n");
	Cout_SL(La, 0);
	printf("\n\nLb的内容为：\n");
	Cout_SL(Lb, 0);
	difference(La, Lb, Lc);
	printf("\n\nLc的内容为：\n");
	Cout_SL(Lc, 1);
	return 0;
}
/*
1 3 5 7 9 -1
2 4 5 7 8 -1

*/