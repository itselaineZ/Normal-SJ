/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include"4-b19.h"
using namespace std;

const int MAXINT = 0x3f3f3f3f;
const double eps = 0.000000001;


int main()
{
	double a, b, c, delta;
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
		Case2(delta, a, b);
	else if (delta < 0)
		Case3(a, b, delta);
	else
		Case4(delta, a, b);
	return 0;
}