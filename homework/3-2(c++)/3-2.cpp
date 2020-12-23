/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<iomanip>
#define pi 3.14159
#define setformat1 setw(10) << setiosflags(ios::left)
#define setformat2 setiosflags(ios::fixed) << setprecision(2)
using namespace std;

int main()
{
	cout << "请输入半径和高度" << endl;
	int r, h;
	cin >> r >> h;
	cout << setformat1 << "圆周长" << " : " << setformat2 << 2.0 * r * pi << endl;
	cout << setformat1 << "圆面积" << " : " << setformat2 << pi * r * r << endl;
	cout << setformat1 << "圆球表面积" << " : " << setformat2 << 4.0 * pi * r * r << endl;
	cout << setformat1 << "圆球体积" << " : " << setformat2 << 4.0 / 3.0 * pi * r * r << endl;
	cout << setformat1 << "圆柱体积" << " : " << setformat2 << pi * r * r * h << endl;

	return 0;
}