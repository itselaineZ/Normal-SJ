/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	cout << "请输入三角形的三条边长度" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	if (a >= b + c || b >= a + c || c >= a + b)
		cout << "不构成三角形" << endl;
	else {
		double p = (a + b + c) / 2;
		cout << "三角形的面积 : " << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
	}
	return 0;
}