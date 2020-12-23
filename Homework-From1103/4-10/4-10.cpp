/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

void Divide(int x) {
	if (fabs(x) < 10) {
		if (x < 0)
			cout << "-" << -x;
		else 
			cout << x;
		return ;
	}
	Divide(x/10);
	if (x < 0)
		cout << " " << -x%10;
	else 
		cout << " " << x%10;
}

int main()
{
	cout << "请输入一个整数\n";
	int x;
	cin >> x;
	Divide(x);
	putchar('\n');
	return 0;
}