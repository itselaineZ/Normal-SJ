/*1952339 ��08 ��ܰ��*/
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
	cout << "����������num������base\n";
	int num, base;
	cin >> num >> base;
	cout << num;
	if (base == 1 || !is_power(num, base))
		cout << "��";
	cout << "��" << base << "����\n";
	return 0;
}