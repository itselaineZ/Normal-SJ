/*1952339 信08 张馨月*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int x;
	char c;

	while (1) {
		cout << "请输入x的值(0-100)：";
		cin >> x;
		while (cin.fail() || x < -100 || x > 100) {
			c = getchar();
			cin.clear();
			cin >> x;
		}
		if (x >= -100 && x <= 100)
			break;
	}
	if (c == '-')
		x = -x;

	cout << "x=" << x << endl;

	return 0;
}
