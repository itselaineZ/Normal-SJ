/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int Cal(int n) {
	if (n == 1)
		return 1;
	return Cal(n-1)+n*n;
}

int main()
{
	cout << "求1^2+...+n^2，请输入n值[3..3180]\n";
	int n;
	cin >> n;
	cout << "1^2+...+" << n << "^2=" << Cal(n) << '\n';
	return 0;
}