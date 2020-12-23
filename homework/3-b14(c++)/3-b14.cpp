/*1952339 信08 张馨月*/
#include<iostream>
using namespace std;

int main()
{
	int x;
	while (1) {
		cout << "请输入x的值(0-100)：";
		cin >> x;
		while(cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> x;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	cout << "x=" << x << '\n';

	return 0;
}