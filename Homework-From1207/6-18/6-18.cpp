/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	const char mth[][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << "请输入月份(1-12)\n";
	int x;
	const char(*p)[10] = mth;
	cin >> x;
	if (cin.fail() || x < 1 || x > 12)
		cout << "Invalid\n";
	else
		cout << *(p+x-1) << '\n';
	return 0;
}