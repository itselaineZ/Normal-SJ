/* 1952339 ��08 ��ܰ�� */
#include <iostream>
using namespace std;

const double eps = 0.0001;
const int hm = 100000000;
const int mm = 10000000;
const int ml = 1000000;
const int lakh = 100000;
const int tth = 10000;
const int th = 1000;
/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
	cout << "������[0-100��)֮�������:\n";
	double x;
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
	int sum = b3 + b4 + b5 + b6 + b7 + b8 + b9 + b01 + b02;
	int wan = b3 + b4 + b5, ge = b7 + b8 + b9;
	bool wanflg = 0, geflg = 0, fst = 0;
	if (b1) {
		if (b1 > 9) {
			daxie(b1/10, 0);
			cout << "ʰ";
			b1 %= 10;
		}
		daxie(b1, 0);
		cout << "��";
		fst = 1;
	}
	if (b2) {
		daxie(b2, 0);
		cout << "Ǫ";
		fst = 1;
	}
	else if (!sum) {
		if (!b1)
			daxie(0, 1);
		cout << "Բ��\n";
		return 0;
	}
	else if (fst && wan)
		wanflg = 1;
	sum -= b3;
	wan -= b3;
	if (b3) {
		if (wanflg && fst)
			wanflg = 0, daxie(0, 1);
		daxie(b3, 0);
		cout << "��";
		fst = 1;
	}
	else if (!sum) {
		cout << "��Բ��\n";
		return 0;
	}
	else if (wan && fst)
		wanflg = 1;
	sum -= b4;
	wan -= b4;
	if (b4) {
		if (wanflg && fst)
			wanflg = 0, daxie(0, 1);
		daxie(b4, 0);
		cout << "ʰ";
		fst = 1;
	}
	else if (!sum) {
		cout << "��Բ��\n";
		return 0;
	}
	else if (wan)
		wanflg = 1;
	sum -= b5;
	if (b5) {
		if (wanflg && fst)
			wanflg = 0, daxie(0, 1);
		daxie(b5, 0);
		fst = 1;
	}
	if (b2 + b3 + b4 + b5)
		cout << "��";
	if (ge + b01 + b02 == 0) {
		if (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9 == 0)
			daxie(0, 1);
		cout << "Բ��\n";
		return 0;
	}
	sum -= b6;
	if (b6) {
		daxie(b6, 0);
		cout << "Ǫ";
		fst = 1;
	}
	else if (!sum) {
		cout << "Բ��\n";
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b7;
	ge -= b7;
	if (b7) {
		if (geflg && fst)
			geflg = 0, daxie(0, 1);
		daxie(b7, 0);
		cout << "��";
		fst = 1;
	}
	else if (!sum) {
		cout << "Բ��\n";
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b8;
	ge -= b8;
	if (b8) {
		if (geflg && fst)
			geflg = 0, daxie(0, 1);
		daxie(b8, 0);
		cout << "ʰ";
		fst = 1;
	}
	else if (!sum) {
		cout << "Բ��\n";
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b9;
	if (b9) {
		if (geflg && fst)
			geflg = 0, daxie(0, 1);
		daxie(b9, 0);
		fst = 1;
	}
	if (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9)
		cout << "Բ";
	if (!sum) {
		cout << "��\n";
		return 0;
	}
	if (b01 && b02) {
		daxie(b01, 0);
		cout << "��";
		daxie(b02, 0);
		cout << "��\n";
	}
	else if (b01) {
		daxie(b01, 0);
		cout << "����\n";
	}
	else {
		if(fst)
			daxie(0, 1);
		daxie(b02, 0);
		cout << "��\n";
	}
	return 0;
}
