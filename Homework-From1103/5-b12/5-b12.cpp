/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;

int Zeller(int y, int m, int d)
{
	int c;
	if (m < 3) {
		m += 12;
		--y;
	}
	c = y / 100;
	y %= 100;
	return ((y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7 + 7) % 7;
}

bool Check_run(int y)
{
	return (y % 400 == 0) || (y % 100 && y % 4 == 0);
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	cout << "请输入年份（1900-2100） : ";
	int Y;
	cin >> Y;
	while (cin.fail() || Y < 1900 || Y > 2100) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "请输入年份（1900-2100） : ";
		cin >> Y;
	}
	system("mode con cols=120 lines=45");
	cout << Y << "年的日历：\n";
	cout << '\n';
	int mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int st_weekdy[13];
	st_weekdy[1] = Zeller(Y, 1, 1);
	if (Check_run(Y))
		mth[2]++;
	for (int i = 2; i <= 12; ++i)
		st_weekdy[i] = (st_weekdy[i - 1] + mth[i - 1]) % 7;
	int pt_mth[13] = {0};
	bool tg[13] = {0};
	int mxrow[4] = {0};
	for (int row = 0; row < 4; ++row)
		mxrow[row] = max(int((st_weekdy[row*3+1]*1.0+mth[row*3+1]*1.0)/7.0+0.9), max(int(st_weekdy[row*3+2]*1.0+mth[row*3+2]*1.0)/7.0+0.9, int(st_weekdy[row*3+3]*1.0+mth[row*3+3]*1.0)/7.0+0.9));
	for (int row = 0; row < 4; ++row) {
		cout << "           " << setw(2) << row * 3 + 1 << "月            ";
		cout << "     ";
		cout << "           " << setw(2) << row * 3 + 2 << "月            ";
		cout << "     ";
		cout << "           " << setw(2) << row * 3 + 3 << "月\n";
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		for (int t = 1; t < 3; ++t)
			cout << "     Sun Mon Tue Wed Thu Fri Sat";
		putchar(10);
		for(int t = 1; t <= mxrow[row]; ++ t)
			for (int i = 1; i <= 3; ++i) {
				int month = row * 3 + i;
				for (int wk = 0; wk <= 6; ++wk) {
					if (wk == st_weekdy[month])
						tg[month] = 1;
					if (tg[month] && pt_mth[month] < mth[month])
						cout << setw(4) << setiosflags(ios ::left) << ++pt_mth[month];
					else
						cout << "    ";
				}
				if (i != 3)
					cout << "    ";
				else
					putchar(10);
			}
		putchar(10);
	}
	putchar(10);
	return 0;
}
