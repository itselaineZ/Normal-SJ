/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<iomanip>
using namespace std;

const double eps = 1e-6;

int main()
{
	double l, r;
	l = 0.0, r = 1.0;
	while (r - l >= eps) {
		double mid = (l+r)/2.0;
		if (2.0 * mid * mid * mid - 9.0 * mid * mid + 12.0 * mid - 3.0 < eps)
			l = mid;
		else
			r = mid;
	}
	cout << "x=" << setiosflags(ios::fixed) << setprecision(3) << (l + r) / 2 << endl;
	return 0;
}