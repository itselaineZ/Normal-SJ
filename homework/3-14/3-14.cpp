/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main() 
{
	int a, b, c, d;
	cout << "�������ĸ�������" << endl;
	cin >> a >> b >> c >> d;
	if (b > c)	swap(b, c);
	if (a > d)	swap(a, d);
	if (a > b)	swap(a, b);
	if (c > d)	swap(c, d);
	if (b > c)	swap(b, c);
	//if (c > d)	swap(c, d);
	cout << "�����" << endl;
	cout << a << ' '<< b << ' ' << c << ' ' << d << endl;
	return 0;
}