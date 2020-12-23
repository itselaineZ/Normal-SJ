/*1952339 信08 张馨月*/
#include<iostream>
#include<cmath>
using namespace std;

const double eps = 0.000000001;

void Case3(double a, double b, double delta)
{
	delta = sqrt(-delta);
	cout << "有两个虚根：" << endl;
	double xx = delta / (2 * a);
	if ((b < eps && b >= 0) || (b <= 0 && b > eps)) {
		if ((xx - 1.0 < eps && xx - 1.0 >= 0) || (xx - 1.0 > eps&& xx - 1.0 <= 0)) {
			cout << "x1=i" << endl;
			cout << "x2=-i" << endl;
		}
		else {
			cout << "x1=" << xx << 'i' << endl;
			cout << "x2=" << '-' << xx << 'i' << endl;
		}
	}
	else {
		cout << "x1=" << -b / (2 * a) << '+' << delta / (2 * a) << 'i' << endl;
		cout << "x2=" << -b / (2 * a) << '-' << delta / (2 * a) << 'i' << endl;
	}
}
