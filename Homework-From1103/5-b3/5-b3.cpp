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
		cin >> law[++ N];
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
	if(N % 10)
		cout << '\n';
	cout << "�����������Ķ�Ӧ��ϵΪ:\n";
	for (int i = 100; i >= 0; --i)
		if (score[i])
			cout << i << ' ' << score[i] << '\n';
	return 0;
}