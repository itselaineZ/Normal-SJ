/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cmath>
using namespace std;

void Case4(double delta, double a, double b)
{
	delta = sqrt(delta);
	cout << "�����������ʵ����" << endl;
	cout << "x1=" << (-b + delta) / (2 * a) << endl;
	cout << "x2=" << (-b - delta) / (2 * a) << endl;
}
