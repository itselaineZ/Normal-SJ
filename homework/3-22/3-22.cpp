/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "������ڼ���������Ϊ1\n";
	int d, sum = 1;
	cin >> d;
	while(-- d)
		sum = (sum + 1) << 1;
	cout << "��1���������=" << sum << endl;
	return 0;
}