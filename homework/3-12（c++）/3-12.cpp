/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "������һ����������λ������" << endl;
	int x, a, b, c, d, e;
	a = b = c = d = e = 0;
	cin >> x;
	int cnt = 0;
	if (x) {
		++cnt;
		a = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		b = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		c = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		d = x % 10;
		x /= 10;
	}
	if (x) {
		++cnt;
		e = x % 10;
		x /= 10;
	}
	cout << cnt << "λ��" << endl;
	cout << "ÿλ���ֱַ��ǣ�" << endl;
	switch (cnt) {
		case 1: {
			cout << a << endl;
			cout << "���������ÿλ���ֱַ��ǣ�" << endl;
			cout << a << endl;
			break;
		}
		case 2: {
			cout << b << ' ' << a << endl;
			cout <<"���������ÿλ���ֱַ��ǣ�\n";
			cout << a << ' ' << b << endl;
			break;
		}
		case 3: {
			cout << c << ' ' << b << ' ' << a << endl;
			printf("���������ÿλ���ֱַ��ǣ�\n");
			cout << a << ' ' <<b << ' ' << c << endl;
			break;
		}
		case 4: {
			cout << d << ' ' << c << ' ' << b << ' ' << a << endl;
			cout << "���������ÿλ���ֱַ��ǣ�\n";
			cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
			break;
		}
		default: {
			cout << e << ' ' << d << ' ' << c << ' ' << b << ' ' << a << endl;
			printf("���������ÿλ���ֱַ��ǣ�\n");
			cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
			break;
		}
	}
	return 0;
}