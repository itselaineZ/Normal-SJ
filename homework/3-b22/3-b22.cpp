/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int x = 0;
	char flg, c;
	bool tg = 1;
	cout << "������x��ֵ(0-100)��";
	while (1 && tg) {
		flg = getchar();
		if (flg >= '0' && flg <= '9')
			x = flg - '0';
		while ((c = getchar()) && c != '\n') {
			if (c < '0' || c > '9')
				tg = 0;
			else
				x = x * 10 + c - '0';
		}
		if (flg == '-')
			x = -x;
		if (!tg) {
			tg = 1;
			cout << "���뺬�зǷ��ַ�������������\n";
		}
		else if (x > 100 || x < 0)
			cout << "����ֵ����ָ����Χ�ڣ�����������\n";
		else if (x >= 0 && x <= 100)
			break;
	}
	cout << "x=" << x << endl;
	return 0;
}
