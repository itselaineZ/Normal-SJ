/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<iomanip>
#define pi 3.14159
#define setformat1 setw(10) << setiosflags(ios::left)
#define setformat2 setiosflags(ios::fixed) << setprecision(2)
using namespace std;

int main()
{
	cout << "������뾶�͸߶�" << endl;
	int r, h;
	cin >> r >> h;
	cout << setformat1 << "Բ�ܳ�" << " : " << setformat2 << 2.0 * r * pi << endl;
	cout << setformat1 << "Բ���" << " : " << setformat2 << pi * r * r << endl;
	cout << setformat1 << "Բ������" << " : " << setformat2 << 4.0 * pi * r * r << endl;
	cout << setformat1 << "Բ�����" << " : " << setformat2 << 4.0 / 3.0 * pi * r * r << endl;
	cout << setformat1 << "Բ�����" << " : " << setformat2 << pi * r * r * h << endl;

	return 0;
}