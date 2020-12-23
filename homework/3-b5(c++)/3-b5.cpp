/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double x, y;
	cout << "请输入坐标：" << endl;
	cin >> x >> y;
	cout << "该点高度为：\n";
	if (!x && !y)
		cout << 0 << endl;
	if (x > 0 && y > 0) {
		if (x + y - 3 < 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	if (x > 0 && y < 0) {
		if (x - y - 3 < 0)
			cout << 4 << endl;
		else
			cout << 0 << endl;
	}
	if (x < 0 && y > 0) {
		if (x - y + 3 > 0)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	if (x < 0 && y < 0) {
		if (x + y + 3 > 0)
			cout << 3 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}