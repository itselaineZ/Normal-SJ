/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

#define Print(bit) \
{if (bit == 1)\
	cout << "Ҽ";\
else if (bit == 2)\
	cout << "��";\
else if (bit == 3)\
	cout << "��";\
else if (bit == 4)\
	cout << "��";\
else if (bit == 5)\
	cout << "��";\
else if (bit == 6)\
	cout << "½";\
else if (bit == 7)\
	cout << "��";\
else if (bit == 8)\
	cout << "��";\
else if (bit == 9)\
	cout << "��";}

const double eps = 0.0001;
const int hm = 100000000;
const int mm = 10000000;
const int ml = 1000000;
const int lakh = 100000;
const int tth = 10000;
const int th = 1000;

int main()
{
	cout << "������[0-100��)֮�������:\n";
	double x;
	int bit;
	cin >> x;
	cout << "��д����ǣ�\n";
	int b1, b2, b3, b4, b5, b6, b7, b8, b9, b01, b02;
	b1 = int(x / hm), x -= 1.0 * b1 * hm;
	b2 = int(x / mm), x -= 1.0 * b2 * mm;
	b3 = int(x / ml), x -= 1.0 * b3 * ml;
	b4 = int(x / lakh), x -= 1.0 * b4 * lakh;
	b5 = int(x / tth), x -= 1.0 * b5 * tth;
	b6 = int(x / th), x -= 1.0 * b6 * th;
	b7 = int(x / 100), x -= 1.0 * b7 * 100;
	b8 = int(x / 10), x -= 1.0 * b8 * 10;
	b9 = int(x), x -= b9;
	b01 = int((x + eps) * 10), x -= b01 * 0.1;
	b02 = int((x + eps) * 100);
	bool fst = 0, tthflg = 0;
	if (b1) {
		if (b1 > 10) {
			bit = b1 /= 10;
			Print(bit);
			cout << "ʰ";
		}
		bit = b1;
		Print(bit);
		cout << "��";
		fst = 1;
	}
	if (b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b2) {
		bit = b2;
		Print(bit);
		cout << "Ǫ";
		tthflg = fst = 1;
	}
	else if (fst && b3)
		cout << "��", fst = 0;
	if (b3 + b4 + b5 + b6 + b7 + b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b3) {
		bit = b3;
		Print(bit);
		cout << "��";
		tthflg = fst = 1;
	}
	else if (fst && b4)
		cout << "��", fst = 0;
	if (b4 + b5 + b6 + b7 + b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b4) {
		bit = b4;
		Print(bit);
		cout << "ʰ";
		tthflg = fst = 1;
	}
	else if (fst && b5)
		cout << "��", fst = 0;
	if (b5 + b6 + b7 + b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b5) {
		bit = b5;
		Print(bit);
		cout << "��";
		tthflg = fst = 1;
	}
	else if (tthflg)
		cout << "��";
	else if (fst && b6)
		cout << "��", fst = 0;
	if (b6 + b7 + b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b6) {
		bit = b6;
		Print(bit);
		cout << "Ǫ";
		fst = 1;
	}
	else if (fst && b7)
		cout << "��", fst = 0;
	if (b7 + b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b7) {
		bit = b7;
		Print(bit);
		cout << "��";
		fst = 1;
	}
	else if (fst && b8)
		cout << "��", fst = 0;
	if (b8 + b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b8) {
		bit = b8;
		Print(bit);
		cout << "ʰ";
		fst = 1;
	}
	else if (fst && b9)
		cout << "��", fst = 0;
	if (b9 + b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b9) {
		bit = b9;
		Print(bit);
		fst = 1;
	}
	cout << "Բ";
	if (b01 + b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b01) {
		bit = b01;
		Print(bit);
		cout << "��";
		fst = 1;
	}
	else if (fst && b01)
		cout << "��", fst = 0;
	if (b02 == 0) {
		cout << "��\n";
		return 0;
	}
	if (b02) {
		bit = b02;
		Print(bit);
		cout << "��\n";
		fst = 1;
	}
	return 0;
}
