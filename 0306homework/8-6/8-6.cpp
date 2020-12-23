/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

class rectangle {
	int length, width, height;
	int v;
public:
	void input()
	{
		cin >> length >> width >> height;
	}
	void volumn()
	{
		v = length * width * height;
	}
	void output()
	{
		cout << v << endl;
	}
};

int main()
{
	rectangle x;
	for (int i = 0; i < 3; ++i) {
		x.input();
		x.volumn();
		x.output();
	}
	return 0;
}