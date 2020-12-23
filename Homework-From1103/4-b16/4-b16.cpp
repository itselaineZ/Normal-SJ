/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int min(int a, int b, int c, int d)
{
	return min(a, min(b, min(c, d)));
}

int main()
{
	while (1) {
		cout << "请输入个数num及num个正整数\n";
		int num = 0;
		char x;
		x = getchar();
		if (x < '0' || x > '9') {
			cin.ignore(0x3f3f3f, '\n');
			continue;
		}
		num = x - '0';
		int a, b, c, d;
		if (num == 2) {
			cin >> a >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
				continue;
			}
			cout << "min=" << min(a, b) << '\n';
			break;
		}
		else if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
				continue;
			}
			cout << "min=" << min(a, b, c) << '\n';
			break;
		}
		else if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
				continue;
			}
			cout << "min=" << min(a, b, c, d) << '\n';
			break;
		}
		else {
			cin >> a;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
			}
			cout << "个数输入错误\n";
			break;
		}
	}
	return 0;
}