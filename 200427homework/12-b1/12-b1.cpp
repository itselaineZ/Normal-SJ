/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class integral {
protected:
	double dn, up;
	int seg;
public:
	integral()
	{
		dn = up = 0.0;
		seg = 1;
	}
	virtual double value()
	{
		return 0.0;
	}
	friend istream& operator >> (istream& in, integral& x)
	{
		in >> x.dn >> x.up >> x.seg;
		return in;
	}
};

class integral_sin: public integral {
public:
	virtual double value()
	{
		double p = (up - dn) / seg, rt = 0.0;
		for (double i = dn + p; i <= up; i += p)
			rt += p * sin(i);
		return rt;
	}
};

class integral_cos: public integral {
public:
	virtual double value()
	{
		double p = (up - dn) / seg, rt = 0.0;
		for (double i = dn + p; i <= up; i += p)
			rt += p * cos(i);
		return rt;
	}
};

class integral_exp : public integral {
public:
	virtual double value()
	{
		double p = (up - dn) / seg, rt = 0.0;
		for (double i = dn + p; i <= up; i += p)
			rt += p * exp(i);
		return rt;
	}
};

int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;
	integral* p;

	cin >> s1;
	p = &s1;
	cout << p->value() << endl;
	cin >> s2;
	p = &s2;
	cout << p->value() << endl;
	cin >> s3;
	p = &s3;
	cout << p->value() << endl;
	return 0;
}