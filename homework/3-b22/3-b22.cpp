/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int x = 0;
	char flg, c;
	bool tg = 1;
	cout << "请输入x的值(0-100)：";
	while (1 && tg) {
		flg = getchar();
		if (flg >= '0' && flg <= '9')
			x = flg - '0';
		while ((c = getchar()) && c != '\n') {
			if (c < '0' || c > '9')
				tg = 0;
			else
				x = x * 10 + c - '0';
		}
		if (flg == '-')
			x = -x;
		if (!tg) {
			tg = 1;
			cout << "输入含有非法字符，请重新输入\n";
		}
		else if (x > 100 || x < 0)
			cout << "整型值不在指定范围内，请重新输入\n";
		else if (x >= 0 && x <= 100)
			break;
	}
	cout << "x=" << x << endl;
	return 0;
}
