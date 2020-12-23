/*1952339 ��08 ��ܰ��*/
/*����֤ 1953080 ���� 1952640 ������ 1951592 ������ 1951850 ������ 1953908 ���U֮*/
#include<stdio.h>

const int N = 10;
const int M = 26;
const int dd[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

int in_map_check(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	int src[10][26];
	int i, j;
	i = 0;
	while(i < N){
		j = 0;
		while(j < M){
			while ((src[i][j] = getchar()) == ' ' || src[i][j] == '\n')
				;
			++ j;
		}
		++ i;
	}
	int cnt = 0;
	i = 0;
	while(i < N){
		j = 0;
		while(j < M){
			cnt += (src[i][j] == '*');
			++ j;
		}
		++ i;
	}	
	if (cnt != 50) {
		printf("����\n");
		return 0;
	}
	i = 0;
	while(i < N){
		j = 0;
		while(j < M){
			if(src[i][j] == '*'){
				int t = 0;
				while(t < 8){
					int xx = i + dd[t][0];
					int yy = j + dd[t][1];
					if (in_map_check(xx, yy) && src[xx][yy] != '*')
						-- src[xx][yy];
					++ t;
				}
			}
			++ j;
		}
		++ i;
	}
	while(i < N){
		j = 0;
		while(j < M){
			if (src[i][j] != '*' && src[i][j] != '0') {
				printf("����\n");
				return 0;
			}
			++ j;
		}
		++ i;
	}	
	printf("��ȷ\n");
	return 0;
}
/*
0 1 1 1 0 0 0 1 3 * 2 1 1 2 * 1 0 0 1 * 1 0 0 0 0 0
0 1 * 1 0 0 0 1 * * 3 2 * 2 2 2 2 1 2 2 2 2 1 1 0 0
0 1 1 2 1 1 1 2 3 3 * 2 1 2 2 * 2 * 1 1 * 2 * 3 3 2
0 0 0 1 * 1 1 * 1 1 1 1 0 2 * 3 2 1 1 1 1 2 2 * * *
2 3 2 2 1 1 1 1 2 2 2 1 0 2 * 2 0 0 0 0 0 0 1 3 * 4
* * * 2 1 1 0 1 2 * * 2 0 1 1 2 1 2 1 2 2 2 1 1 3 *
2 3 2 2 * 2 1 3 * 5 * 3 2 3 2 2 * 2 * 2 * * 1 0 2 *
0 0 0 2 2 3 * 4 * 5 2 3 * * * 3 2 2 1 2 3 4 3 1 1 1
0 0 0 1 * 3 2 4 * * 2 2 * 4 3 * 2 2 2 1 1 * * 1 0 0
0 0 0 1 1 2 * 2 3 * 2 1 1 1 1 1 2 * * 1 1 2 2 1 0 0
*/
