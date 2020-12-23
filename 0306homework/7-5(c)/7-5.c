/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
#define M 3

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

struct student {
	int no;
	char name[9];
	float score[M];
	float ave, sum;
};

int main()
{
	struct student stu[N + 5];
	float maxsc = 0.0f;
	int i = 1;
	while (i <= N) {
		printf("�������%2d��ѧ������Ϣ��", i);
		while (scanf("%d%s%f%f%f", &stu[i].no, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]) != 5) {
			while (getchar() != '\n')
				;
			printf("�������%2d��ѧ������Ϣ��", i);
		}
		stu[i].sum = 0.0f;
		int j = 0;
		while (j < M){
			stu[i].sum += stu[i].score[j];
			++ j;
		}
		stu[i].ave = stu[i].sum / M;
		maxsc = maxsc > stu[i].sum ? maxsc : stu[i].sum;
		++ i;
	}
	printf("\n10��ѧ���ĳɼ�Ϊ��\n");
	printf("��� ѧ��    ����     ���ſγɼ�     ƽ���ɼ�\n");
	printf("=============================================\n");
	i = 1;
	while (i <= N) {
		printf("%-5d", i);
		printf("%-8d", stu[i].no);
		printf("%-9s", stu[i].name);
		int j = 0;
		while (j < M){
			printf("%-5.1f", stu[i].score[j]);
			++ j; 
		} 
		printf("%-5.2f\n", stu[i].ave);
		++ i;
	}
	printf("\n��߷�ѧ����Ϣ��\n");
	printf("��� ѧ��    ����     ���ſγɼ�     �ܳɼ�\n");
	printf("=============================================\n");
	i = 1;
	while (i <= N){
		if (stu[i].sum == maxsc) {
			printf("%-5d", i);
			printf("%-8d", stu[i].no);
			printf("%-9s", stu[i].name);
			int j = 0;
			while (j < M){
				printf("%-5.1f", stu[i].score[j]);
				++ j;
			}
			printf("%-.1f\n", stu[i].sum);
		}
		++ i;
	}
	return 0;
}
