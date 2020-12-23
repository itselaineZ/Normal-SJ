/*1952339 信08 张馨月*/
#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

int Zeller(int y, int m, int d) {
	int c;
	if (m < 3) {
		m += 12;
		--y;
	}
	c = y / 100;
	y %= 100;
	return ((y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7 + 7) % 7;
}

int main()
{
	cout << "请输入年份(2000-2030)和月份(1-12) : ";
	int y, m, x, dy;
	bool flg = 0;
	do {
		flg = 1;
		cin >> y >> m;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入:\n";
			cin >> y >> m;
		}
		if (y < 1900 || y > 2100 || m < 1 || m > 12)
			flg = 0;
	} while (! flg);
	for (int i = 0; i <= 6; ++i) {
		cout << "星期";
		switch (i) {
			case 1: {
				cout << "一  ";
				break;
			}
			case 2: {
				cout << "二  ";
				break;
			}
			case 3: {
				cout << "三  ";
				break;
			}
			case 4: {
				cout << "四  ";
				break;
			}
			case 5: {
				cout << "五  ";
				break;
			}
			case 6: {
				cout << "六\n";
				break;
			}
			default: {
				cout << "日  ";
				break;
			}
		}
	}
	if (m == 2) {
		if (y % 400 == 0 || (y % 100 && y % 4 == 0))
			dy = 29;
		else
			dy = 28;
	}
	else {
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			dy = 31;
		else
			dy = 30;
	}
	int tot = 0;
	x = Zeller(y, m, 1);
	if (x != 0) {
		cout << setw(4) << ' ';
		for (int i = 1; i < x; ++i)
			cout << setw(8) << ' ';
		for (int i = x; i <= 6; ++i)
			cout << setw(8) << ++tot;
		cout << '\n';
	}
	while (tot < dy) {
		cout << setw(4) << ++tot;
		for (int i = 1; i <= 6 && tot < dy; ++i)
			cout << setw(8) << ++tot;
		cout << '\n';
	}
	return 0;
}
