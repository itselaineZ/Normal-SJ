/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a;
	cin >> a;
	cout << "万位 : " << a / 10000 << endl;
	cout << "千位 : " << a / 1000 % 10 << endl;
	cout << "百位 : " << a / 100 % 10 << endl;
	cout << "十位 : " << a / 10 % 10 << endl;
	cout << "个位 : " << a % 10 << endl;
	return 0;
}