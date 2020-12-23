/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	for (int num = 2; num <= 1000; ++num) {
		int t = num;
		for (int i = 1; i < num; ++i)
			if (num % i == 0)
				t -= i;
		if (t == 0) {
			cout << num << ", its factors are 1";
			for (int i = 2; i < num; ++i)
				if (num % i == 0)
					cout << ',' << i;
			putchar(10);
		}
	}
	return 0;
}