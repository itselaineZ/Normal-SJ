/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

const int N = 10;

int main()
{
	int id[11], score[11], guake[11];
	char name[11][10];
	memset(guake, 0, sizeof guake );
	for (int i = 1; i <= 10; ++i) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i);
		scanf("%d", &id[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
		if (score[i] < 60)
			guake[i] = 1;
	}
	printf("\n不及格名单:\n");
	for(int i = 1; i <= 10 ; ++ i)
		if (guake[i])
			printf("%s %d %d\n", name[i], id[i], score[i]);
	return 0;
}