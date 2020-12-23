/*1952339 信08 张馨月*/
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
	cout << "请输入sinxdx的下限、上限及区间划分数量\n";
	cin >> low >> high >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "数据输入错误，请重新输入\n请输入sinxdx的下限、上限及区间划分数量\n";
		cin >> low >> high >> n;
	}
	value = defineite_integration(sin, low, high, n);
	cout << "sinxdx[" << low << '~' << high << "/n=" << n << "] : " << value << '\n';

	cout << "请输入cosxdx的下限、上限及区间划分数量\n";
	cin >> low >> high >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "数据输入错误，请重新输入\n请输入cosxdx的下限、上限及区间划分数量\n";
		cin >> low >> high >> n;
	}
	value = defineite_integration(cos, low, high, n);
	cout << "cosxdx[" << low << '~' << high << "/n=" << n << "] : " << value << '\n';

	cout << "请输入e^xdx的下限、上限及区间划分数量\n";
	cin >> low >> high >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "数据输入错误，请重新输入\n请输入e^xdx的下限、上限及区间划分数量\n";
		cin >> low >> high >> n;
	}
	value = defineite_integration(exp, low, high, n);
	cout << "e^xdx[" << low << '~' << high << "/n=" << n << "] : " << value << '\n';

	return 0;
}