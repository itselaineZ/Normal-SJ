/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int max(int a, int b, int c, int d)
{
	return max(a, max(b, max(c, d)));
}

int main()
{
	while (1) {
		cout << "���������num��num��������\n";
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
			if(cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
				continue;
			}
			cout << "max=" << max(a, b) << '\n';
			break;
		}
		else if (num == 3) {
			cin >> a >> b >> c;
			if(cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
				continue;
			}
			cout << "max=" << max(a, b, c) << '\n';
			break;
		}
		else if(num == 4){
			cin >> a >> b >> c >> d;
			if(cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
				continue;
			}
			cout << "max=" << max(a, b, c, d) << '\n';
			break;
		}
		else {
			cin >> a;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(0x3f3f3f, '\n');
			}
			cout << "�����������\n";
			break;
		}
	}
	return 0;
}