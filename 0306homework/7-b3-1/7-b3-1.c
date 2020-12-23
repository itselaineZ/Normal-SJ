/*1952339 ��08 ��ܰ��*/
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
	struct student* next;
};

int main()
{
	FILE* infile;
	infile = fopen("list.txt", "r");
	if (infile == NULL) {
		printf("���ļ�ʧ��\n");
		return -1;
	}
	int x;
	struct student* q = NULL, * p = NULL, * head = NULL;
	int i = 1;
	while(1){
		fscanf(infile, "%d", &x);
		if (x == 9999999)
			break;
		if (i > 1)
			q = p;
		p = (struct student*)malloc(sizeof(struct student));
		if (p == NULL)
			return -1;
		if (i == 1)
			head = p;
		else
			q->next = p;
		p->no = x;
		fscanf(infile, "%s %d", p->name, &p->score);
		p->next = NULL;
		++ i;
	}
	
	p = head;
	while(p){
		printf("%d %s %d\n", p->no, p->name, p->score);
		p = p->next;
	}

	p = head;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}
