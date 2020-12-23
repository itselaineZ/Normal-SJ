/*1952339 ��08 ��ܰ��*/
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
	cout << "�����뺺ŵ���Ĳ���(1-64):\n";
	int n;
	cin >> n;
	while (cin.fail() || n < 1 || n > 64) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����Ƿ�������������\n";
		cin >> n;
	}
	cout << "��������ʼ��(A-C):\n";
	char bgn, ed;
	cin >> bgn;
	while (cin.fail() || !((bgn >= 'a' && bgn <= 'c')||(bgn >= 'A' && bgn <= 'C'))) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����Ƿ�������������\n";
		cin >> bgn;
	}
	cout << "������Ŀ����(A-C):\n";
	cin >> ed;
	while (cin.fail() || !((ed >= 'a' && ed <= 'c') || (ed >= 'A' && ed <= 'C')) || ed == bgn) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����Ƿ�������������\n";
		cin >> ed;
	}
	cout << "�ƶ�����Ϊ\n";
	if (bgn > 'C')
		bgn -= 'a' - 'A';
	if (ed > 'C')
		ed -= 'a' - 'A';
	Hano(n, bgn, ed);
	return 0;
}