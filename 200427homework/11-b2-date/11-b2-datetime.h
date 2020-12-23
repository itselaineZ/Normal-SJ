/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#pragma once
#include<iostream>
#include<cstdio>
#include"11-b2-Date.h"
#include"11-b2-Time.h"
using namespace std;

class DateTime:protected Date, protected Time {
public:
	DateTime();
	DateTime(const int);
	DateTime(const LL);
	DateTime(const Date&);
	DateTime(const Time&);
	DateTime(const DateTime&);
	DateTime(const int, const int, const int, const LL, const LL, const LL);
	void set(const int, const int, const int, const LL, const LL, const LL);
	operator LL();
	DateTime operator + (const LL);
	DateTime& operator ++();
	DateTime operator ++(int);
	DateTime operator - (const LL);
	DateTime& operator -- ();
	DateTime operator --(int);
	friend istream& operator >> (istream&, DateTime&);
	friend ostream& operator << (ostream&, const DateTime&);
	bool operator > (const DateTime&)const;
	bool operator < (const DateTime&)const;
	bool operator >= (const DateTime&)const;
	bool operator <= (const DateTime&)const;
	bool operator == (const DateTime&)const;
	bool operator != (const DateTime&)const;
};
const DateTime DT_MIN(1900, 1, 1, 0, 0, 0);
const DateTime DT_MAX(2099, 12, 31, 23, 59, 59);
