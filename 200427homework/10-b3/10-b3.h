/* 1952339 ��08 ��ܰ�� */
#pragma once
#include <iostream>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString {
private:
	char* content;
	int   len;
	/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
public:
	/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
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

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
int TStringLen(const TString& x);
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */