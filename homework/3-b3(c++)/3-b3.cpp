/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#define eps 0.0001
#define setformat setw(6)<<setiosflags(ios::left)
using namespace std;

int main()
{
	double a;
	cin >> a;
	cout << setformat << "ʮ��λ" << " : " << int(a/1e9)%10 << endl;
	a -= int(a / 1e9) * 1e9;
	cout << setformat << "��λ" << " : " << int(a/1e8)%10 << endl;
	a -= int(a / 1e8) * 1e8;
	cout << setformat << "ǧ��λ" << " : " << int(a/1e7)%10 << endl;
	a -= int(a / 1e7) * 1e7;
	cout << setformat << "����λ" << " : " << int(a/1e6)%10 << endl;
	a -= int(a / 1e6) * 1e6;
	cout << setformat << "ʮ��λ" << " : " << int(a/1e5)%10 << endl;
	a -= int(a / 1e5) * 1e5;
	cout << setformat << "��λ" << " : " << int(a/1e4)%10 << endl;
	a -= int(a / 1e4) * 1e4;
	cout << setformat << "ǧλ" << " : " << int(a/1e3)%10 << endl;
	a -= int(a / 1e3) * 1e3;
	cout << setformat << "��λ" << " : " << int(a/100)%10 << endl;
	a -= int(a / 1e2) * 1e2;
	cout << setformat << "ʮλ" << " : " << int(a/10)%10 << endl;
	a -= int(a / 10.0) * 10.0;
	cout << setformat << "Բ" << " : " << int(a) << endl;
	a -= int(a);
	cout << setformat << "��" << " : " << int((a+eps)*10) << endl;
	a -= int((a+eps) / 0.1)* 0.1;
	cout << setformat << "��" << " : " << int((a+eps)*100) << endl;
	return 0;
}
/*
8307238123.07
9999999999.99
9999999999.90
9999999999.09
9900000000
8912003005.78
2501200350.03
1203056740.00
203056740.20
23000056.82
3051200.72
301000.35
10001.34
8070.23
9876.54
803.03
12.30
10.03
9.30
7.03
0.35
0.30
0.07
0.03
0

*/