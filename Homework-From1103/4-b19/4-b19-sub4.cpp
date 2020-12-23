/*1952339 信08 张馨月*/
#include<iostream>
#include<cmath>
using namespace std;

void Case4(double delta, double a, double b)
{
	delta = sqrt(delta);
	cout << "有两个不相等实根：" << endl;
	cout << "x1=" << (-b + delta) / (2 * a) << endl;
	cout << "x2=" << (-b - delta) / (2 * a) << endl;
}
