/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

bool is_power(int num, int base) {
	if (num == 1)
		return 1;
	if (num % base)
		return 0;
	return is_power(num/base, base);
}

int main()
{
	cout << "请输入整数num及基数base\n";
	int num, base;
	cin >> num >> base;
	cout << num;
	if (base == 1 || !is_power(num, base))
		cout << "不";
	cout << "是" << base << "的幂\n";
	return 0;
}