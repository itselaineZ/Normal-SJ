/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int A[25];
	cout << "���������������������������20��������-1����\n";
	int N = 0, x;
	while (1) {
		cin >> A[++ N];
		if (A[N] == -1)
			break;
	}
	-- N;
	cout << "ԭ����Ϊ��\n";
	cout << A[1];
	for (int i = 2; i <= N; ++i)
		cout << ' ' << A[i];
	cout << '\n';
	cout << "������Ҫ�����������\n";
	cin >> x;
	cout << "����������Ϊ��\n";
	if (x <= A[1])
		cout << x << ' ';
	cout << A[1];
	for (int i = 2; i <= N; ++i) {
		if (A[i - 1] < x && x <= A[i])
			cout << ' ' << x;
		cout << ' ' << A[i];
	}
	if (x > A[N])
		cout << ' ' << x;
	cout << '\n';
	return 0;
}