/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 9; ++i) {
		cout << 1 << 'x' << i << "= " << i;
		for (int j = 2; j <= i; ++j) {
			cout << "  " << j << 'x' << i << '=';
			if (i * j < 10)
				cout << ' ';
			cout << i*j;
		}
		cout << '\n';
	}
	return 0;
}