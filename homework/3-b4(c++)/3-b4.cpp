/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#define pi 3.1415926
using namespace std;

int main()
{
	cout << "�����������ε����߼���нǣ��Ƕȣ�:";
	int a, b, c;
	cin >> a >> b >> c;
	cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << 0.5 * a * b * sin(c/180.0*pi) << endl;
	return 0;
}