/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	cout << "����������������n(10-20)\n";
	int N;
	cin >> N;
	cout << "������" << N << "������\n";
	int a[25] = {0};
	for (int i = 0; i < N; i++)
		cin >> *(a+i);
	cout << "�������������Ϊ\n";
	cout << *a;
	for (int i = 1; i < N; ++i)
		cout << ' ' << *(a+i);
	putchar(10);
	cout << "����������ƶ���λ��m(1~2^31-1)\n";
	int M;
	cin >> M;
	cout << "�ƶ������������Ϊ\n";
	M = M%N;
	while (M--) {
		int t = *(a+ N-1);
		for (int i = N-2; i >= 0; i--)
			*(a + i + 1) = *(a+i);
		*a = t;
	}
	for (int i = 0; i < N; ++i) {
		cout << *(a+i);
		if(i!=N-1)
			putchar(32);
	}
	putchar(10);
	return 0;
}