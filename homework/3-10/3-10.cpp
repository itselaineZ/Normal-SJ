/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "������x��ֵ" << endl;
	double x;
	cin >> x;
	cout << "y=";
	if (x < 1)
		cout << x << endl;
	else if (x >= 1 && x < 10)
		cout << 2 * x - 1 << endl;
	else
		cout << 3 * x - 11 << endl;
	return 0;
}