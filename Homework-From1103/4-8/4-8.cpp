/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

double P(double x, int n) {
	if (n == 0)
		return 1.0;
	if (n == 1)
		return x;
	return ((2 * n - 1) * x * P(x, n - 1) - (n - 1) * P(x, n - 2)) / n;
}

int main()
{
	cout << "����legendre��������x��n\n";
	double x;
	int n;
	cin >> x >> n;
	cout << "Lengendre[" << n << "](" << x << ")=" << P(x, n) << '\n';
	return 0;
}