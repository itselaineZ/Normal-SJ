/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#define pi 3.1415926
using namespace std;

int main()
{
	cout << "请输入三角形的两边及其夹角（角度）:";
	int a, b, c;
	cin >> a >> b >> c;
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << 0.5 * a * b * sin(c/180.0*pi) << endl;
	return 0;
}