/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int main()
{
	cout << "请输入俩正整数\n";
	int a, b;
	cin >> a >> b;
	cout << "最大公约数 : " << gcd(a, b) << '\n';
	cout << "最小公倍数 : " << a * b / gcd(a, b) << '\n';
	return 0;
}