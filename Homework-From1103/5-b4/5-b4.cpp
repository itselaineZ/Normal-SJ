/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "������ɼ������1000��������-1����\n";
	int score[105], law[1005];
	for (int i = 0; i <= 100; ++i)
		score[i] = 0;
	int N = 0;
	while (1) {
		cin >> law[++N];
		if (law[N] == -1)
			break;
		++score[law[N]];
	}
	--N;
	cout << "���������Ϊ:\n";
	for (int i = 1; i <= N; ++i) {
		if (i % 10 != 1)
			cout << ' ';
		cout << law[i];
		if (i % 10 == 0)
			cout << '\n';
	}
	if (N % 10)
		cout << '\n';
	cout << "���������εĶ�Ӧ��ϵΪ:\n";
	int ord = 1;
	for (int i = 100; i >= 0; ord += score[i], --i)
		for(int j = 1; j <= score[i]; ++ j)
			cout << i << ' ' << ord << '\n';
	return 0;
}