/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 9;

int main()
{
	cout << "请输入9*9矩阵，值为1-9之间\n";
	int suduku[15][15];
	for(int i = 1; i <= N; ++ i)
		for (int j = 1; j <= N; ++j) {
			cin >> suduku[i][j];
			while (cin.fail() || suduku[i][j] < 1 || suduku[i][j] > 9) {
				cin.clear();
				cin.ignore(0x3f3f3f3f, '\n');
				cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值\n";
				cin >> suduku[i][j];
			}
		}
	int cnt[10];
	memset(cnt, 0, sizeof cnt );
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			++cnt[suduku[i][j]];
			if (cnt[suduku[i][j]] != i) {
				cout << "不是数独的解\n";
				return 0;
			}
		}
	memset(cnt, 0, sizeof cnt );
	for (int j = 1; j <= N; ++j)
		for (int i = 1; i <= N; ++i) {
			++cnt[suduku[i][j]];
			if (cnt[suduku[i][j]] != j) {
				cout << "不是数独的解\n";
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
						cout << "不是数独的解\n";
						return 0;
					}
				}
		}
	cout << "是数独的解\n";
	return 0;
}