/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int A[25];
	cout << "请输入任意多个正整数（升序，最多20个），以-1结束\n";
	int N = 0, x;
	while (1) {
		cin >> A[++ N];
		if (A[N] == -1)
			break;
	}
	-- N;
	cout << "原数组为：\n";
	cout << A[1];
	for (int i = 2; i <= N; ++i)
		cout << ' ' << A[i];
	cout << '\n';
	cout << "请输入要插入的正整数\n";
	cin >> x;
	cout << "插入后的数组为：\n";
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