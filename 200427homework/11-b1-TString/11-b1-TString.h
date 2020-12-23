/*1952339 信08 张馨月*/
#pragma once
#include<iostream>
using namespace std;

class TString {
protected:
	char* content;
	int   len;
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
public:
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
	TString();
	TString(const char* p);
	TString(const TString& x);
	~TString();
	friend istream& operator >> (istream& in, TString& x);
	friend ostream& operator << (ostream& out, const TString& x);
	char* c_str()const;
	TString& operator = (const TString& x);
	TString& operator = (const char* p);
	TString& operator = (const char c);
	TString& operator = (const int k);
	friend TString operator + (const TString& a, const TString& x);
	friend TString operator + (const TString& a, const char* p);
	friend TString operator + (const TString& a, const char c);
	friend TString operator + (const char c, const TString& a);
	TString& operator += (const TString& x);
	TString& operator += (const char c);
	friend TString operator - (const TString& a, const TString& x);
	friend TString operator - (const TString& a, const char c);
	TString& operator -= (const TString& x);
	TString& operator -= (const char c);
	friend TString operator * (const TString& a, const int x);
	TString& operator *= (const int x);
	TString operator ! ();
	bool operator > (const TString& x)const;
	bool operator < (const TString& x)const;
	bool operator >= (const TString& x)const;
	bool operator <= (const TString& x)const;
	bool operator == (const TString& x)const;
	bool operator != (const TString& x)const;
	int length()const;
	char& operator [](const int x);
};

int TStringLen(const TString& x);