/*1952339 –≈08 ’≈‹∞‘¬*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

class TString {
	string v;
public:
	TString() {}
	TString(const char* p);
	TString(const TString& x);
	TString& operator = (const TString& x);
	TString& operator += (const TString& x);
	bool operator != (const TString& x);
	int length();
};

TString::TString(const char* p)
{
	v = p;
}
TString::TString(const TString& x)
{
	v = x.v;
}

TString& TString::operator = (const TString& x)
{
	v = x.v;
	return *this;
}
TString& TString::operator += (const TString& x)
{
	v += x.v;
	return *this;
}

bool TString::operator != (const TString& x)
{
	return v != x.v;
}

int TString::length()
{
	return v.size();
}
