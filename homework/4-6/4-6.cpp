/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<limits>
using namespace std;

const double eps = 1e-6;

double diferential_coefficient(double x) {
	return 3.0 * x * x + 4.0 * x + 3.0;
}

double function(double x) {
	return x * x * x + 2.0 * x * x + 3.0 * x + 4.0;
}

double Cal(int a, int b, int c, int d) {
	double rt = 1.0, x = 0.0;
	while (fabs(rt - x) > eps) {
		x = rt;
		rt = x - function(x) / diferential_coefficient(x);
	}
	return rt;
}

int main()
{
	int a = 1, b = 2, c = 3, d = 4;
	cout << "x=" << Cal(a, b, c, d) << '\n';
	return 0;
}
