/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int main()
{
	cout << "��������������\n";
	int a, b;
	cin >> a >> b;
	cout << "���Լ�� : " << gcd(a, b) << '\n';
	cout << "��С������ : " << a * b / gcd(a, b) << '\n';
	return 0;
}