/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

bool Check_y(int y)
{
	return y % 400 == 0 || (y % 100 && y % 4 == 0);
}

int Cal_day(bool ru, int m, int d)
{
	int dy[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int rt = 0;
	for (int i = 1; i < m; ++i)
		rt += dy[ru][i];
	return rt + d;
}

int main()
{
	cout << "请输入年，月，日(年份在2000-2030之间)\n";
	int y, m, d;
	cin >> y >> m >> d;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f, '\n');
		cout << "输入错误，请重新输入:)\n";
		cin >> y >> m >> d;
	}
	if (m > 12) {
		cout << "输入错误-月份不正确\n";
		return 0;
	}
	bool ru = Check_y(y);
	if (m != 2) {
		if ((m & 1) && d > 31) {
			cout << "输入错误-日与月的关系非法\n";
			return 0;
		}
		else if ((m & 1) == 0 && d > 30) {
			cout << "输入错误-日与月的关系非法\n";
			return 0;
		}
	}
	else if((!ru && d >= 29) || (ru && d > 29))
		cout << "输入错误-日与月的关系非法\n";

	cout << y << '-' << m << '-' << d << "是" << y << "年的第" << Cal_day(ru, m, d) << "天\n";
	return 0;
}