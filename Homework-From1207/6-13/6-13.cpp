/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double defineite_integration(double (*f)(double x), double low, double high, int n)
{
	double dx = (high - low)/n;
	double rt = 0.0;
	for (int i = 1; i <= n; ++i) 
		rt += dx*f(i*dx+low);
	return rt;
}

int main() 
{
	int n;
	double low, high, value;
	cout << "������sinxdx�����ޡ����޼����仮������\n";
	cin >> low >> high >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "���������������������\n������sinxdx�����ޡ����޼����仮������\n";
		cin >> low >> high >> n;
	}
	value = defineite_integration(sin, low, high, n);
	cout << "sinxdx[" << low << '~' << high << "/n=" << n << "] : " << value << '\n';

	cout << "������cosxdx�����ޡ����޼����仮������\n";
	cin >> low >> high >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "���������������������\n������cosxdx�����ޡ����޼����仮������\n";
		cin >> low >> high >> n;
	}
	value = defineite_integration(cos, low, high, n);
	cout << "cosxdx[" << low << '~' << high << "/n=" << n << "] : " << value << '\n';

	cout << "������e^xdx�����ޡ����޼����仮������\n";
	cin >> low >> high >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "���������������������\n������e^xdx�����ޡ����޼����仮������\n";
		cin >> low >> high >> n;
	}
	value = defineite_integration(exp, low, high, n);
	cout << "e^xdx[" << low << '~' << high << "/n=" << n << "] : " << value << '\n';

	return 0;
}