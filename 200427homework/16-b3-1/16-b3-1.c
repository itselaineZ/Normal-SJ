/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node, *List;

void InitList(List* L)
{
	*L = (List)malloc(sizeof(Node));
	if (L == NULL) {
		puts("ERROR! OVERFLOW!");
		exit(0);
	}
	(*L)->next = (*L);
	return;
}

void InsertList(List L, int value)
{
	List s;
	s = (List)malloc(sizeof(Node));
	if (s == NULL) {
		puts("ERROR! OVERFLOW!");
		exit(0);
	}
	s->data = value;
	s->next = L->next;
	L->next = s;
}

void DeleteNext(List L, List p)
{
	List q = p->next;
	if (q == L)
		p = L, q = q->next;
	p->next = q->next;
	free(q);
}

int main()
{
	printf("请输入人数: ");
	int N, M, K;
	scanf("%d", &N);
	printf("请输入起始人编号: ");
	scanf("%d", &K);
	printf("请输入出列序数: ");
	scanf("%d", &M);
	List L;
	InitList(&L);
	for (int i = N; i >= 1; --i)
		InsertList(L, i);
	int tot = 0;
	List p = L->next, q = L;
	K %= N;
	for (int i = 1; i < K; ++i)
		q = p, p = p->next;
	printf("删除顺序为：\n");
	while (tot < N) {
		for (int i = 1; i < M; ++i) {
			q = p;
			p = p->next;
			if (p == L)
				p = p->next;
		}
		++tot;
		printf("%d->", p->data);
		if (tot % 10 == 0)
			putchar(10);
		p = p->next;
		if (p == L)
			p = p->next;
		DeleteNext(L, q);
	}
	return 0;
}