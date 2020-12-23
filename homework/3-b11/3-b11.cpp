/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

const double eps = 0.00001;

int main() 
{
	cout << "请输入找零值：\n";
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
	cout << "共"<<cnt <<"张找零，具体如下：\n";

	if (r50)
		cout << setw(4) << setiosflags(ios::left) << "50元" << " : " << r50 << "张\n";
	if (r20)
		cout << setw(4) << setiosflags(ios::left) << "20元" << " : " << r20 << "张\n";
	if (r10)
		cout << setw(4) << setiosflags(ios::left) << "10元" << " : " << r10 << "张\n";
	if (r5)
		cout << setw(4) << setiosflags(ios::left) << "5元" << " : " << r5 << "张\n";
	if (r1)
		cout << setw(4) << setiosflags(ios::left) << "1元" << " : " << r1 << "张\n";
	if (r05)
		cout << setw(4) << setiosflags(ios::left) << "5角" << " : " << r05 << "张\n";
	if (r01)
		cout << setw(4) << setiosflags(ios::left) << "1角" << " : " << r01 << "张\n";
	if (r005)
		cout << setw(4) << setiosflags(ios::left) << "5分" << " : " << r005 << "张\n";
	if (r002)
		cout << setw(4) << setiosflags(ios::left) << "2分" << " : " << r002 << "张\n";
	if (r001)
		cout << setw(4) << setiosflags(ios::left) << "1分" << " : " << r001 << "张\n";
	return 0;
}