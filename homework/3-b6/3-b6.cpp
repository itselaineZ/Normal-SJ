/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	cout << "�����������ε������߳���" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	if (a >= b + c || b >= a + c || c >= a + b)
		cout << "������������" << endl;
	else {
		double p = (a + b + c) / 2;
		cout << "�����ε���� : " << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
	}
	return 0;
}