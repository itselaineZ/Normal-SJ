/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a;
	cin >> a;
	cout << "��λ : " << a / 10000 << endl;
	cout << "ǧλ : " << a / 1000 % 10 << endl;
	cout << "��λ : " << a / 100 % 10 << endl;
	cout << "ʮλ : " << a / 10 % 10 << endl;
	cout << "��λ : " << a % 10 << endl;
	return 0;
}