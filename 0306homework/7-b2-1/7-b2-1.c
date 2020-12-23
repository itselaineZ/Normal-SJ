/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

struct student {
	int no;
	char name[9];
	int score;
	int rank;
};

int cmp1(const struct student a, const struct student b)
{
	if (a.score == b.score)
		return a.no - b.no;
	return b.score - a.score;
}

int cmp2(const struct student a, const struct student b)
{
	return a.no - b.no;
}

int main()
{
	FILE* infile;
	infile = fopen("student.txt", "r");
	if (infile == NULL) {
		printf("打开文件失败\n");
		return -1;
	}
	int N;
	fscanf(infile, "%d", &N);
	struct student * q, * p, * head = (struct student*) malloc(N * sizeof(struct student));
	if (head == NULL) {
		printf("申请失败\n");
		return -1;
	}
	p = head;
	int i = 1; 
	while(i <= N){
		fscanf(infile, "%d %s %d", &p->no, p->name, &p->score);
		++ i, ++ p;
	}

	struct student* t = (struct student*)malloc(sizeof(struct student));
	if (t == NULL) {
		printf("申请失败\n");
		return -1;
	}
	p = head;
	i = 1;
	while(i < N) {
		q = p + 1;
		int j = i + 1;
		while(j <= N){
			if (cmp1(*p, *q) > 0) {
				*t = *p;
				*p = *q;
				*q = *t;
			}
			++ j;
			++ q;
		}
		++ i;
		++ p;
	}
	head->rank = 1;
	p = head+1;
	i = 2;
	while(i <= N){
		if (p->score == (p - 1)->score)
			p->rank = (p - 1)->rank;
		else
			p->rank = i;
		++ i;
		++ p;
	}
	p = head;
	i = 1;
	while(i < N) {
		q = p + 1;
		int j = i + 1;
		while(j <= N){
			if (cmp2(*p, *q) > 0) {
				*t = *p;
				*p = *q;
				*q = *t;
			}
			++ j;
			++ q;
		}
		++ i;
		++ p;
	}
	p = head;
	i = 1;
	while (i <= N){
		printf("%d %s %d %d\n", p->no, p->name, p->score, p->rank);
		++ i;
		++ p;
	}
	free(head);
	return 0;
}
