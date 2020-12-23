/*1952339 ��08 ��ܰ��*/
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
	cout << "�������꣬�£���(�����2000-2030֮��)\n";
	int y, m, d;
	cin >> y >> m >> d;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f, '\n');
		cout << "�����������������:)\n";
		cin >> y >> m >> d;
	}
	if (m > 12) {
		cout << "�������-�·ݲ���ȷ\n";
		return 0;
	}
	bool ru = Check_y(y);
	if (m != 2) {
		if ((m & 1) && d > 31) {
			cout << "�������-�����µĹ�ϵ�Ƿ�\n";
			return 0;
		}
		else if ((m & 1) == 0 && d > 30) {
			cout << "�������-�����µĹ�ϵ�Ƿ�\n";
			return 0;
		}
	}
	else if((!ru && d >= 29) || (ru && d > 29))
		cout << "�������-�����µĹ�ϵ�Ƿ�\n";

	cout << y << '-' << m << '-' << d << "��" << y << "��ĵ�" << Cal_day(ru, m, d) << "��\n";
	return 0;
}