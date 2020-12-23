/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<limits>
using namespace std;

void Hano(int n, char now_pos, char aim_pos) {
	if (n == 0)
		return;
	char spare_pos = 65 + 66 + 67 - now_pos - aim_pos;
	Hano(n-1, now_pos, spare_pos);
	cout << n << "# " << now_pos << "-->" << aim_pos << '\n';
	Hano(n-1, spare_pos, aim_pos);
}

int main()
{
	cout << "请输入汉诺塔的层数(1-64):\n";
	int n;
	cin >> n;
	while (cin.fail() || n < 1 || n > 64) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入\n";
		cin >> n;
	}
	cout << "请输入起始柱(A-C):\n";
	char bgn, ed;
	cin >> bgn;
	while (cin.fail() || !((bgn >= 'a' && bgn <= 'c')||(bgn >= 'A' && bgn <= 'C'))) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入\n";
		cin >> bgn;
	}
	cout << "请输入目标柱(A-C):\n";
	cin >> ed;
	while (cin.fail() || !((ed >= 'a' && ed <= 'c') || (ed >= 'A' && ed <= 'C')) || ed == bgn) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入\n";
		cin >> ed;
	}
	cout << "移动步骤为\n";
	if (bgn > 'C')
		bgn -= 'a' - 'A';
	if (ed > 'C')
		ed -= 'a' - 'A';
	Hano(n, bgn, ed);
	return 0;
}