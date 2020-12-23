/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int merge(int* list_a, int* list_b, int* list_c)
{
	int len, i, j;
	len = 0, i = j = 1;
	while (*(list_a + i) != -1 || *(list_b + j) != -1) {
		while (*(list_a + i) != -1 && (*(list_a + i) >= *(list_b + j) || *(list_b + j) == -1)) {
			if (*(list_c + len) != *(list_a + i))
				*(list_c + (++len)) = *(list_a + (i++));
			else
				++i;
		}
		while (*(list_b + j) != -1 && (*(list_a + i) < *(list_b + j) || *(list_a + i) == -1)) {
			if (*(list_c + len) != *(list_b + j))
				*(list_c + (++len)) = *(list_b + (j++));
			else
				++j;
		}
	}
	return len;
}

int main()
{
	int a[25] = { 0 }, b[25] = { 0 };
	int N = 0, M = 0;
	printf("请输入第1个数组，升序序列（最多20个），以-1结束（-1不计入）\n");
	while (scanf("%d", (a + (++N))) && *(a + N) != -1)
		;
	printf("请输入第2个数组，升序序列（最多20个），以-1结束（-1不计入）\n");
	while (scanf("%d", (b + (++M))) && *(b + M) != -1)
		;
	printf("第1个数组的内容为：\n");
	if(N > 1)
		printf("%d", *(a + 1));
	int i = 2;
	while (i < N){
		printf(" %d", *(a + i));
		++ i;
	}
	printf("\n第2个数组的内容为：\n");
	if(M > 1)
		printf("%d", *(b + 1));
	i = 2;
	while (i < M){
		printf(" %d", *(b + i));
		++ i;
	}
	int an[45] = { 0 };
	printf("\n合并后数组的内容为：\n");
	int sum = merge(a, b, an);
	if(sum)
		printf("%d", *(an + 1));
	i = 2;
	while (i <= sum){
		printf(" %d", *(an + i));
		++ i;
	}
	putchar(10);
	return 0;
}
