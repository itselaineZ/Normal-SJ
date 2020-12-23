/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	cout << "请输入a值（正整数）\n";
	int a;
	cin >> a;
	cout << a << "的平方根=" << setiosflags(ios::fixed) << setprecision(3) << sqrt(a) << endl;
	return 0;
}