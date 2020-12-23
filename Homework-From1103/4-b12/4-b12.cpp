/* 1952339 ��08 ��ܰ�� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* ------------------------------------------------------------------------------ */
/* ---- ����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ�� ---- */
/* ------------------------------------------------------------------------------ */

void Print_alph(char bg_ch, char ed_ch,int delta) {
	if (bg_ch == ed_ch)
		return;
	putchar(bg_ch);
	return Print_alph(bg_ch+delta, ed_ch, delta);
}

void Print_spc(int l, int r) {
	if (l == r)
		return;
	putchar(32);
	return Print_spc(l+1, r);
}

void Print_0(char bg_ch, char ed_ch, int num) {
	int spc = ed_ch - bg_ch + 1 - num;
	Print_spc(1, spc);
	Print_alph(bg_ch+num-1, bg_ch, -1);
	Print_alph(bg_ch, bg_ch+num, 1);
	putchar(10);
	if (bg_ch + num == ed_ch)
		return ;
	return Print_0(bg_ch, ed_ch, num + 1);
}

void Print_1(char bg_ch, char ed_ch, int num) {
	int spc = ed_ch - bg_ch + 1 - num;
	Print_spc(1, spc);
	Print_alph(ed_ch-num, ed_ch, 1);
	Print_alph(ed_ch-2, ed_ch-num-1, -1);
	putchar(10);
	if (num == 1)
		return ;
	return Print_1(bg_ch, ed_ch, num - 1);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���������ӡ������
  ���������order - 0 ������������
			order - 1 ������������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�� */
	if (!order)
		Print_0(start_ch, end_ch+1, 1);
	else
		Print_1(start_ch, end_ch+1, end_ch-start_ch+1);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();			//����������һ���ַ�
		while (getchar() != '\n')	//��ջ�����ʣ���ַ�
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}
