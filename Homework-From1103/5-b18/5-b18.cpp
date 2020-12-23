/*1952339 пе08 уеэ╟тб*/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;

const int N = 10;
const int M = 26;
const int dd[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

bool in_map_check(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	srand(time(0));
	char mp[N][M];
	memset(mp, 0, sizeof mp );
	for (int i = 0; i < 50; ++i) {
		int xx = rand() % N, yy = rand() % M;
		while (mp[xx][yy]) {
			xx = rand() % N;
			yy = rand() % M;
		}
		mp[xx][yy] = '*';
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (!mp[i][j])
				mp[i][j] = '0';
	for(int i = 0; i < N; ++ i)
		for (int j = 0; j < M; ++j)
			if (mp[i][j] == '*')
				for (int t = 0; t < 8; ++t) {
					int xx = i + dd[t][0];
					int yy = j + dd[t][1];
					if (in_map_check(xx, yy) && mp[xx][yy] != '*')
						++mp[xx][yy];
				}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << mp[i][j] << ' ';
		putchar(10);
	}
}