/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
	cout << "�����뻪���¶�" << endl;
	int F;
	cin >> F;
	cout << "�����¶� : " << setiosflags(ios::fixed) << setprecision(2) << 5.0 / 9.0 * (F - 32.0) << endl;

	return 0;
}