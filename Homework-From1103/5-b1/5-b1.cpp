/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	bool lgt[105];
	for (int i = 1; i <= 100; ++i)
		lgt[i] = 0;
	for (int i = 1; i <= 100; ++i) 
		for (int j = i; j <= 100; j += i)
			lgt[j] = !lgt[j];
	bool flg = 0;
	for (int i = 1; i <= 100; ++i) {
		if (lgt[i]) {
			if (flg)
				cout << ' ';
			cout << i;
			flg = 1;
		}
	}
	cout << '\n';
	return 0;
}