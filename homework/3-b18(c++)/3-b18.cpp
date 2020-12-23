/*1952339 信08 张馨月*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "请输入年份(2000-2030)和月份(1-12) : ";
	int y, m, x, dy;
	cin >> y >> m;
	while (y < 2000 || y > 2030 || m < 1 || m > 12) {
		cout << "输入错误，请重新输入\n";
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
	}
	cout << "请输入2018年3月1日的星期(0-6表示星期日-星期六) : ";
	cin >> x;
	while (x < 0 || x > 6) {
		cout << "输入错误，请重新输入\n";
		cout << "请输入2018年3月1日的星期(0-6表示星期日-星期六) : ";
		cin >> x;
	}
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
	if (x != 0) {
		cout << setw(4) << ' ';
		for (int i = 1; i < x; ++i)
			cout << setw(8) << ' ';
		for (int i = x; i <= 6; ++i)
			cout << setw(8) << ++tot;
		cout << '\n';
	}
	while (tot < dy) {
		cout << setw(4) << ++ tot;
		for (int i = 1; i <= 6 && tot < dy; ++i)
			cout << setw(8) << ++tot;
		cout << '\n';
	}
	return 0;
}