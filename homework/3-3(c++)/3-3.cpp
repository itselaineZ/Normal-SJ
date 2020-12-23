/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
	cout << "请输入华氏温度" << endl;
	int F;
	cin >> F;
	cout << "摄氏温度 : " << setiosflags(ios::fixed) << setprecision(2) << 5.0 / 9.0 * (F - 32.0) << endl;

	return 0;
}