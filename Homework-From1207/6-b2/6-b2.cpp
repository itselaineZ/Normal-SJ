/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

void merge(int* list_a, int* list_b, int* list_c)
{
	int len, i, j;
	len = 0, i = j = 1;
	while (*(list_a + i) != -1 || *(list_b + j) != -1) {
		while (*(list_a + i) != -1 && (*(list_a + i) <= *(list_b + j) || *(list_b + j) == -1))
			*(list_c + (++len)) = *(list_a + (i++));
		while (*(list_b + j) != -1 && (*(list_a + i) > * (list_b + j) || *(list_a + i) == -1))
			*(list_c + (++len)) = *(list_b + (j++));
	}
}

int main()
{
	int a[25] = { 0 }, b[25] = { 0 };
	int N = 0, M = 0;
	cout << "请输入第1个数组，升序序列（最多20个），以-1结束（-1不计入）\n";
	while (cin >> *(a + (++N)) && *(a + N) != -1)
		;
	cout << "请输入第2个数组，升序序列（最多20个），以-1结束（-1不计入）\n";
	while (cin >> *(b + (++M)) && *(b + M) != -1)
		;
	cout << "第1个数组的内容为：\n";
	cout << *(a + 1);
	for (int i = 2; i < N; ++i)
		cout << ' ' << *(a + i);
	cout << "\n第2个数组的内容为：\n";
	cout << *(b + 1);
	for (int i = 2; i < M; ++i)
		cout << ' ' << *(b + i);
	int an[45] = { 0 };
	merge(a, b, an);
	cout << "\n合并后数组的内容为：\n";
	cout << *(an + 1);
	int sum = N + M - 2;
	for (int i = 2; i <= sum; ++i)
		cout << ' ' << *(an + i);
	putchar(10);
	return 0;
}
