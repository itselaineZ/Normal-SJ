/* 1952339 信08 张馨月 */
#pragma once
#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
private:
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
	friend ostream& operator << (ostream & out, const TString & x);
	char* c_str()const;
	TString& operator = (const TString& x);
	friend TString operator + (const TString& a, const TString& x);
	friend TString& operator += (TString& a, const TString& x);
	friend TString operator + (const TString& a, const char x);
	friend TString operator + (const char x, const TString& a);
	friend TString& operator += (TString& a, const char x);
	friend TString operator - (const TString& a, const TString& x);
	friend TString& operator -= (TString& a, const TString& x);
	friend TString operator - (const TString& a, const char x);
	friend TString& operator -= (TString& a, const char x);
	friend TString operator * (const TString& a, const int x);
	friend TString& operator *= (TString& a, const int x);
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

/* 如果有其它全局函数需要声明，写于此处 */
int TStringLen(const TString& x);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */