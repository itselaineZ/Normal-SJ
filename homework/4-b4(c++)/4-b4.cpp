/*1952339 ��08 ��ܰ��*/
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
	cout << "���������(1900-2100)���·�(1-12)������ : \n";
	int y, m, d;
	bool flg = 1;
	do {
		cin >> y >> m >> d;
		while (cin.fail()) {
			cout << 1 << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������������:\n";
			cin >> y >> m >> d;
		}
		flg = 1;
		if (y < 1900 || y > 2100 || m < 1 || m > 12 || d < 1 || d > 31)
			flg = 0;
		if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
			flg = 0;
		if (m == 2) {
			if (!(y % 400 == 0 || (y % 100 && y % 4 == 0)) && d > 28)
				flg = 0;
		}
		if(! flg)
			cout << "�����������������:\n";
	} while (! flg);
	int rt = Zeller(y, m, d);
	cout << "����";
	switch(rt) {
		case 0: {
			cout << "��";
			break;
		}
		case 1: {
			cout << "һ";
			break;
		}
		case 2: {
			cout << "��";
			break;
		}
		case 3: {
			cout << "��";
			break;
		}
		case 4: {
			cout << "��";
			break;
		}
		case 5: {
			cout << "��";
			break;
		}
		case 6: {
			cout << "��";
			break;
		}
	}
	cout << '\n';
	return 0;
}