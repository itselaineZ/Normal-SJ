/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

const double eps = 0.00001;

int main() 
{
	cout << "����������ֵ��\n";
	double x;
	cin >> x;
	int r50, r20, r10, r5, r1, r05, r01, r005, r002, r001;
	r50 = r20 = r10 = r5 = r1 = r05 = r01 = r005 = r002 = r001 = 0;

	r50 = x / 50.0;
	x -= 50.0 * r50;

	r20 = x / 20.0;
	x -= 20.0 * r20;

	r10 = x / 10.0;
	x -= 10.0 * r10;

	r5 = x / 5.0;
	x -= 5.0 * r5;

	r1 = x / 1.0;
	x -= 1.0 * r1;

	r05 = (x + eps) / 0.5;
	x -= 0.5 * r05;

	r01 = (x + eps) / 0.1;
	x -= 0.1 * r01;

	r005 = (x + eps) / 0.05;
	x -= 0.05 * r005;

	r002 = (x + eps) / 0.02;
	x -= 0.02 * r002;

	r001 = (x + eps) / 0.01;
	x -= 0.01 * r001;

	int cnt = r50 + r20 + r10 + r5 + r1 + r05 + r01 + r005 + r002 + r001;
	cout << "��"<<cnt <<"�����㣬�������£�\n";

	if (r50)
		cout << setw(4) << setiosflags(ios::left) << "50Ԫ" << " : " << r50 << "��\n";
	if (r20)
		cout << setw(4) << setiosflags(ios::left) << "20Ԫ" << " : " << r20 << "��\n";
	if (r10)
		cout << setw(4) << setiosflags(ios::left) << "10Ԫ" << " : " << r10 << "��\n";
	if (r5)
		cout << setw(4) << setiosflags(ios::left) << "5Ԫ" << " : " << r5 << "��\n";
	if (r1)
		cout << setw(4) << setiosflags(ios::left) << "1Ԫ" << " : " << r1 << "��\n";
	if (r05)
		cout << setw(4) << setiosflags(ios::left) << "5��" << " : " << r05 << "��\n";
	if (r01)
		cout << setw(4) << setiosflags(ios::left) << "1��" << " : " << r01 << "��\n";
	if (r005)
		cout << setw(4) << setiosflags(ios::left) << "5��" << " : " << r005 << "��\n";
	if (r002)
		cout << setw(4) << setiosflags(ios::left) << "2��" << " : " << r002 << "��\n";
	if (r001)
		cout << setw(4) << setiosflags(ios::left) << "1��" << " : " << r001 << "��\n";
	return 0;
}