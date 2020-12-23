/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<limits>
using namespace std;

const double eps = 1e-6;

int main()
{
	int x;
	cout << "������x��ֵ(-10~+65)\n";
	cin >> x;
	while (cin.fail() || x < -10 || x > 65) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����Ƿ�������������\n";
		cout << "������x��ֵ(-10~+65)\n";
		cin >> x;
	}
	double sum = 1.0, fac = 1.0, t = 1.0;
	for (int i = 1; t/fac >= eps; ++i) {
		fac *= i;
		t *= x;
		sum += t / fac;
	}
	cout << "e^" << x << '=' << setiosflags(ios::fixed) << setprecision(7) << sum << '\n';
	return 0;
}
