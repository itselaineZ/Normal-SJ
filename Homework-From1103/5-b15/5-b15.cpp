/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char name[50][10], id[50][10];

int main()
{
	int N;
	cout << "please input number of this class:";
	cin >> N;
	while (cin.fail() || N <= 0) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "Input invalid, please try again!\n";
		cin >> N;
	}
	for (int i = 0; i < N; ++i) {
		cout << "input name and NO. of student " << i + 1 << " : ";
		cin >> name[i] >> id[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(0x3f3f3f3f, '\n');
			cout << "Input invalid, please try again!\n";
			cin >> name[i] >> id[i];
		}
	}
	cout << "please input name you want find:";
	char fd_name[10];
	cin >> fd_name;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "Input invalid, please try again!\n";
		cin >> fd_name;
	}
	bool flg = 0;
	for(int i = 0; i < N && !flg; ++ i)
		if (strcmp(fd_name, name[i]) == 0) {
			cout << fd_name << " has been found, his number is " << id[i] << '\n';
			flg = 1;
		}
	if (!flg)
		cout << "can't find this name\n";
	return 0;
}