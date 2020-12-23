/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 9;

int main()
{
	cout << "������9*9����ֵΪ1-9֮��\n";
	int suduku[15][15];
	for(int i = 1; i <= N; ++ i)
		for (int j = 1; j <= N; ++j) {
			cin >> suduku[i][j];
			while (cin.fail() || suduku[i][j] < 1 || suduku[i][j] > 9) {
				cin.clear();
				cin.ignore(0x3f3f3f3f, '\n');
				cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ\n";
				cin >> suduku[i][j];
			}
		}
	int cnt[10];
	memset(cnt, 0, sizeof cnt );
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			++cnt[suduku[i][j]];
			if (cnt[suduku[i][j]] != i) {
				cout << "���������Ľ�\n";
				return 0;
			}
		}
	memset(cnt, 0, sizeof cnt );
	for (int j = 1; j <= N; ++j)
		for (int i = 1; i <= N; ++i) {
			++cnt[suduku[i][j]];
			if (cnt[suduku[i][j]] != j) {
				cout << "���������Ľ�\n";
				return 0;
			}
		}
	memset(cnt, 0, sizeof cnt );
	for (int x = 1; x <= 7; x += 3) 
		for (int y = 1; y <= 7; y += 3) {
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) {
					int xx = x + i, yy = y + j;
					++cnt[suduku[xx][yy]];
					if (cnt[suduku[xx][yy]] != 3 * (x / 3) + y / 3 + 1) {
						cout << "���������Ľ�\n";
						return 0;
					}
				}
		}
	cout << "�������Ľ�\n";
	return 0;
}