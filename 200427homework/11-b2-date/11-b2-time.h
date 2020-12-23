/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#pragma once
#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;

class Time {
protected:
	LL hour, minute, second;
public:
	Time();
	Time(const LL a, const LL b, const LL c);
	Time(const LL dd);
	Time(const Time& x);
	void set(const Time& x);
	void set(const LL h, const LL m, const LL s);
	void show();
	operator LL();
	Time operator + (const LL dd);
	Time& operator ++ ();
	Time operator ++ (int);
	Time operator - (const LL dd);
	Time& operator -- ();
	Time operator -- (int);
	friend istream& operator >> (istream& in, Time& x);
	friend ostream& operator << (ostream& out, const Time& x);
	bool operator > (const Time& x)const;
	bool operator < (const Time& x)const;
	bool operator >= (const Time& x)const;
	bool operator <= (const Time& x)const;
	bool operator == (const Time& x)const;
	bool operator != (const Time& x)const;
};

const int HOUR_S = 60 * 60;
const int MINUTE_S = 60;
const int DAY_S = 24 * 60 * 60;
const Time TIME_MAX(23, 59, 59);
const Time TIME_MIN(0, 0, 0);