/*1952339 ��08 ��ܰ��*/
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
	cout << "��1^2+...+n^2��������nֵ[3..3180]\n";
	int n;
	cin >> n;
	cout << "1^2+...+" << n << "^2=" << Cal(n) << '\n';
	return 0;
}