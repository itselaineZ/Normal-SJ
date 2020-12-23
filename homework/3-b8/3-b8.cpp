/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double eps = 0.000000001;

int main()
{
	cout << "请输入一元二次方程的三个系数：" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	if (a < 0)
		a = -a, b = -b, c = -c;
	double delta = b*b - 4.0*a*c;
	if (a < eps)
		cout << "不是一元二次方程" << endl;
	else if (delta < eps && delta >= 0.0) {
		delta = sqrt(delta);
		cout << "有两个相等实根:" << endl;
		cout << "x1=x2=" << -b / (2 * a) << endl;
	}
	else if (delta < 0) {
		delta = sqrt(-delta);
		cout << "有两个虚根:" << endl;
		double xx = delta / (2 * a);
		if ((b < eps && b >= 0) || (b <= 0 && b > eps)) {
			if ((xx - 1.0 < eps && xx-1.0 >= 0) || (xx - 1.0 > eps && xx - 1.0 <= 0)) {
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
	else {
		delta = sqrt(delta);
		cout << "有两个不相等实根:" << endl;
		cout << "x1=" << (-b + delta) / (2 * a) << endl;
		cout << "x2=" << (-b - delta) / (2 * a) << endl;
	}
	return 0;
}