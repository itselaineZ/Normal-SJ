/*1952339 ��08 ��ܰ��*/
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
		cout << "�������" << i << "���˵�ѧ�š��������ɼ�\n";
		cin >> id[i];
		cin >> name[i];
		cin >> score[i];
		if (score[i] < 60)
			guake[i] = 1;
	}
	cout << "\n����������:\n";
	for (int i = 1; i <= 10; ++i)
		if (guake[i])
			cout << name[i] << ' ' << id[i] << ' ' << score[i] << '\n';
	return 0;
}