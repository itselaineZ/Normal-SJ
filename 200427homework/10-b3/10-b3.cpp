/* 1952339 信08 张馨月 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "10-b3.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::TString(const char* p)
{
	if (p == NULL || strlen(p) == 0) {
		len = 0;
		content = NULL;
		return;
	}
	len = strlen(p);
	content = new(nothrow) char[len + 1];
	strcpy(content, p);
}
TString::TString(const TString& x)
{
	if (x.len == 0) {
		len = 0;
		content = NULL;
		return;
	}
	len = x.len;
	content = new(nothrow) char[len + 1];
	strcpy(content, x.content);
}
TString::~TString()
{
	if (len) {
		len = 0;
		delete[]content;
	}
}

istream& operator >> (istream& in, TString& x)
{
	char s[100];
	in >> s;
	x = s;
	return in;
}
ostream& operator << (ostream& out, const TString& x)
{
	if (x.content == NULL)
		out << "<NULL>";
	else
		out << x.content;
	return out;
}

char* TString::c_str()const
{
	return content;
}

TString& TString::operator = (const TString& x)
{
	TString xx(x);
	if (xx.len == 0) {
		len = 0;
		content = NULL;
		return *this;
	}
	if(len)
		delete[] content;
	len = xx.len;
	content = new(nothrow) char[len + 1];
	strcpy(content, xx.content);
	return *this;
}
TString operator + (const TString& a, const TString& x)
{
	TString rt;
	rt.len = a.len + x.len;
	rt.content = new(nothrow) char[rt.len+1];
	*(rt.content) = 0;
	if(a.len)
		strcpy(rt.content, a.content);
	if(x.len)
		strcat(rt.content, x.content);
	return rt;
}
TString& operator += (TString& a, const TString& x)
{
	TString rt;
	rt = a + x;
	a = rt;
	return a;
}
TString operator + (const TString& a, const char x)
{
	TString rt;
	rt.len = a.len + 1;
	rt.content = new(nothrow) char[rt.len + 1];
	if(a.len)
		strcpy(rt.content, a.content);
	*(rt.content + a.len) = x;
	*(rt.content + rt.len) = 0;
	return rt;
}
TString operator + (const char x, const TString& a)
{
	TString rt;
	rt.len = a.len + 1;
	rt.content = new(nothrow) char[rt.len + 1];
	*(rt.content) = x;
	strcpy(rt.content+1, a.content);
	return rt;
}
TString& operator += (TString& a, const char x)
{
	TString rt;
	rt = a + x;
	a = rt;
	return a;
}
TString operator - (const TString& a, const TString& x)
{
	TString rt(a);
	if (a.len == 0)
		return rt;
	for (int i = 0; i < a.len; ++i) {
		int j;
		for (j = 0; j < x.len && i + j < a.len && *(a.content + i + j) == *(x.content + j); ++j)
			;
		if (j == x.len) {
			if(rt.len)
				delete[] rt.content;
			rt.len = a.len - x.len;
			rt.content = new(nothrow) char[rt.len + 1];
			for (int k = 0; k < i; ++k)
				*(rt.content + k) = *(a.content + k);
			for (int k = i + x.len; k < a.len; ++k)
				*(rt.content + k - x.len) = *(a.content + k);
			*(rt.content + rt.len) = 0;
			break;
		}
	}
	return rt;
}
TString& operator -= (TString& a, const TString& x)
{
	TString rt;
	rt = a - x;
	a = rt;
	return a;
}
TString operator - (const TString& a, const char x)
{
	TString rt(a);
	if (rt.len == 0)
		return rt;
	for (int i = 0; i < a.len; ++i) {
		if(*(a.content+i) == x){
			if(rt.len)
				delete[] rt.content;
			rt.len = a.len - 1;
			rt.content = new(nothrow) char[rt.len + 1];
			for (int k = 0; k < i; ++k)
				*(rt.content + k) = *(a.content + k);
			for (int k = i + 1; k < a.len; ++k)
				*(rt.content + k - 1) = *(a.content + k);
			*(rt.content + rt.len) = 0;
			break;
		}
	}
	return rt;
}
TString& operator -= (TString& a, const char x)
{
	TString rt;
	rt = a - x;
	a = rt;
	return a;
}
TString operator * (const TString& a, const int x)
{
	TString rt = a;
	for (int i = 1; i < x; ++i)
		rt += a;
	return rt;
}
TString& operator *= (TString& a, const int x)
{
	TString rt = a;
	if (a.len == 0)
		return a;
	for (int i = 1; i < x; ++i)
		rt += a;
	a = rt;
	return a;
}
TString TString::operator ! ()
{
	TString rt(*this);
	int l = rt.len / 2;
	for (int i = 0; i < l; ++i)
		swap(*(rt.content + i), *(rt.content + rt.len - i - 1));
	return rt;
}

bool TString::operator > (const TString& x)const
{
	if (len == 0)
		return 0;
	if (x.len == 0)
		return 1;
	return strcmp(this->content, x.content) > 0;
}
bool TString::operator < (const TString& x)const
{
	if (x.len == 0)
		return 0;
	if (len == 0)
		return 1;
	return strcmp(this->content, x.content) < 0;
}
bool TString::operator >= (const TString& x)const
{
	if (len == 0)
		return x.len == 0;
	if (x.len == 0)
		return 1;
	return strcmp(this->content, x.content) >= 0;
}
bool TString::operator <= (const TString& x)const
{
	if (x.len == 0)
		return len == 0;
	if (len == 0)
		return 1;
	return strcmp(this->content, x.content) <= 0;
}
bool TString::operator == (const TString& x)const
{
	if (len == 0)
		return x.len == 0;
	if (x.len == 0)
		return 0;
	return strcmp(this->content, x.content) == 0;
}
bool TString::operator != (const TString& x)const
{
	if (len == 0)
		return x.len != 0;
	if (x.len == 0)
		return 1;
	return strcmp(this->content, x.content) != 0;
}

int TString::length()const
{
	return len;
}

char& TString::operator [](const int x)
{
	return content[x];
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
int TStringLen(const TString& x)
{
	return x.length();
}
