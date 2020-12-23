/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "请输入第几天桃子数为1\n";
	int d, sum = 1;
	cin >> d;
	while(-- d)
		sum = (sum + 1) << 1;
	cout << "第1天的桃子数=" << sum << endl;
	return 0;
}