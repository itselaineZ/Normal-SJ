/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int N = 10;

int main()
{
	int id[11], score[11], guake[11];
	string name[11];
	memset(guake, 0, sizeof guake);
	for (int i = 1; i <= 10; ++i) {
		cout << "请输入第" << i << "个人的学号、姓名、成绩\n";
		cin >> id[i];
		cin >> name[i];
		cin >> score[i];
		if (score[i] < 60)
			guake[i] = 1;
	}
	cout << "\n不及格名单:\n";
	for (int i = 1; i <= 10; ++i)
		if (guake[i])
			cout << name[i] << ' ' << id[i] << ' ' << score[i] << '\n';
	return 0;
}