/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

struct date {
	int y, m, d;
};

int days(date &X) 
{
	int mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((X.y % 100 && X.y % 4 == 0) || (X.y % 400 == 0))
		++mth[2];
	if (X.m > 12 || X.m < 1)
		return 0;
	if (X.d > mth[X.m])
		return -1;
	int cnt = X.d;
	for (int i = 1; i < X.m; ++i)
		cnt += mth[i];
	return cnt;
}

int main()
{
	date X;
	cout << "请输入年，月，日\n";
	cin >> X.y >> X.m >> X.d;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "请输入年，月，日\n";
		cin >> X.y >> X.m >> X.d;
	}
	int ans = days(X);
	if (ans == -1)
		cout << "输入错误-日与月的关系非法\n";
	else if (ans == 0)
		cout << "输入错误-月份不正确\n";
	else
		cout << X.y << '-' << X.m << '-' << X.d << "是" << X.y << "年的第" << ans << "天\n";
	return 0;
}