/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	cout << "������aֵ����������\n";
	int a;
	cin >> a;
	cout << a << "��ƽ����=" << setiosflags(ios::fixed) << setprecision(3) << sqrt(a) << endl;
	return 0;
}