/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<limits>
using namespace std;

const int MAXINT = 0x3f3f3f3f;
const double eps = 0.000000001;

double a, b, c, delta;

void Case1() {
	cout << "不是一元二次方程" << endl;
}

void Case2() {
	delta = sqrt(delta);
	cout << "有两个相等实根:" << endl;
	cout << "x1=x2=" << -b / (2 * a) << endl;
}

void Case3() {
	delta = sqrt(-delta);
	cout << "有两个虚根:" << endl;
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

void Case4() {
	delta = sqrt(delta);
	cout << "有两个不相等实根:" << endl;
	cout << "x1=" << (-b + delta) / (2 * a) << endl;
	cout << "x2=" << (-b - delta) / (2 * a) << endl;
}

int main()
{
	cout << "请输入一元二次方程的三个系数：" << endl;
	cin >> a >> b >> c;
	/*
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> a >> b >> c;
	}*/
	if (a < 0)
		a = -a, b = -b, c = -c;
	delta = b * b - 4.0 * a * c;
	if (a < eps)
		Case1();
	else if (delta < eps && delta >= 0.0)
		Case2();
	else if (delta < 0)
		Case3();
	else
		Case4();
	return 0;
}