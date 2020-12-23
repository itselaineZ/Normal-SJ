/* 1952339 信08 张馨月 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string.h>
#include "11-b1-TString.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */

static char* strcat(char* dst, char* src)
{
	static char* last_startp = NULL;
	static char* last_endp = NULL;

	if (dst == last_startp) {
		while (*src != 0) 
			*last_endp++ = *src++;
		*last_endp = 0;
	}
	else {
		char* dst_start = dst;
		while (*dst)
			dst++;
		while (*src)
			*dst++ = *src++;
		*dst = 0;
		if (dst - dst_start >= 32768) {
			last_startp = dst_start;
			last_endp = dst;
		}
	}
	return dst;
}

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
	}
	else {
		len = strlen(p);
		content = new(nothrow) char[len + 1];
		if (content)
			strcpy(content, p);
		else
			len = 0;
	}
}
TString::TString(const TString& x)
{
	if (x.len == 0) {
		len = 0;
		content = NULL;
	}
	else {
		len = x.len;
		content = new(nothrow) char[len + 1];
		if (content)
			strcpy(content, x.content);
		else
			len = 0;
	}
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
	char s[8192];
	in >> s;
	if (x.content)
		delete[] x.content;
	x.content = NULL;
	x.len = strlen(s);
	if (x.len > 0) {
		x.content = new(nothrow) char[x.len + 1];
		if (x.content)
			strcpy(x.content, s);
		else
			x.len = 0;
	}
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
	if (this == &x)
		return *this;
	if (this->content)
		delete[] this->content;
	this->len = 0;
	this->content = NULL;
	if (x.len > 0) {
		this->len = x.len;
		this->content = new(nothrow) char[x.len + 1];
		if (this->content)
			strcpy(this->content, x.content);
		else
			this->len = 0;
	}
	return *this;
}
TString& TString::operator = (const char* p)
{
	if (this->content)
		delete[] this->content;
	this->len = 0;
	this->content = NULL;
	if (p == NULL || p[0] == 0)
		return *this;
	this->len = strlen(p);
	this->content = new(nothrow) char[this->len + 1];
	if (this->content)
		strcpy(this->content, p);
	else
		this->len = 0;
	return *this;
}
TString& TString::operator = (const char c)
{
	if (this->content)
		delete[] this->content;
	this->len = 0;
	this->content = NULL;
	if (c) {
		this->len = 1;
		this->content = new(nothrow) char[2];
		if (this->content)
			*this->content = c;
		else
			this->len = 0;
	}
	return *this;
}
TString& TString::operator = (const int k)
{
	if (this->content)
		delete[] this->content;
	this->len = 0;
	this->content = NULL;
	if (k) {
		this->len = 1;
		this->content = new(nothrow) char[2];
		if (this->content)
			*this->content = k;
		else
			this->len = 0;
	}
	return *this;
}
TString operator + (const TString& a, const TString& x)
{
	TString rt;
	if (a.len == 0 && x.len == 0)
		return rt;
	if (a.len == 0)
		return x;
	if (x.len == 0)
		return a;
	rt.len = a.len + x.len;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		strcpy(rt.content, a.content);
		strcat(rt.content, x.content);
	}
	else
		rt.len = 0;
	return rt;
}
TString operator + (const TString& a, const char* p)
{
	TString rt;
	int slen = (p && p[0] ? strlen(p) : 0);
	if (a.len == 0 && slen == 0)
		return rt;
	if (a.len == 0)
		return p;
	if (slen == 0)
		return a;
	rt.len = a.len + slen;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		strcpy(rt.content, a.content);
		strcat(rt.content, p);
	}
	else
		rt.len = 0;
	return rt;
}
TString operator + (const TString& a, const char c)
{
	if (c == 0)
		return a;
	TString rt;
	rt.len = a.len + 1;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		if (a.len > 0) {
			strcpy(rt.content, a.content);
			rt.content[rt.len - 1] = c;
			rt.content[rt.len] = 0;
		}
		else
			rt.content[0] = c;
	}
	else
		rt.len = 0;
	return rt;
}
TString operator + (const char c, const TString& a)
{
	if (c == 0)
		return a;
	TString rt;
	rt.len = a.len + 1;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		rt.content[0] = c;
		if (a.len > 0)
			strcpy(rt.content+1, a.content);
	}
	else
		rt.len = 0;
	return rt;
}
TString& TString::operator += (const TString& x)
{
	char* p = this->content;
	if (x.len == 0)
		return *this;
	this->len += x.len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		strcpy(this->content, p ? p : "");
		strcat(this->content, x.content);
	}
	else
		this->len = 0;
	if(p)
		delete[] p;
	return *this;
}
TString& TString::operator += (const char c)
{
	if (c == 0)
		return *this;
	char* p = this->content;
	++this->len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		strcpy(this->content, p ? p : "");
		this->content[this->len-1] = c;
		this->content[this->len] = 0;
	}
	else
		this->len = 0;
	if (p)
		delete[] p;
	return *this;
}
TString operator - (const TString& a, const TString& x)
{
	const char* p;
	if (a.len == 0 || x.len == 0 || (p = strstr(a.content, x.content)) == NULL)
		return a;
	TString rt;
	rt.len = a.len - x.len;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		if (p != a.content)
			memcpy(rt.content, a.content, p - a.content);
		memcpy(rt.content + (p - a.content), p + x.len, a.len - (p - a.content) - x.len + 1);
	}
	else
		rt.len = 0;
	rt.content[rt.len] = 0;
	return rt;
}
TString operator - (const TString& a, const char c)
{
	const char* p;
	if (a.len == 0 || c == 0 || (p = strchr(a.content, c)) == NULL)
		return a;

	TString rt;
	rt.len = a.len + 1;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		if (p != a.content)
			memcpy(rt.content, a.content, p - a.content);
		memcpy(rt.content + (p - a.content), p + 1, a.len - (p - a.content));
	}
	else
		rt.len = 0;
	rt.content[rt.len] = 0;
	return rt;
}
TString& TString::operator -= (const TString& x)
{
	const char* now = this->content;
	const char* p;
	if (this->len == 0 || x.len == 0 || (p = strstr(this->content, x.content)) == NULL)
		return *this;

	this->len -= x.len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (p != this->content)
			memcpy(this->content, now, p - now);
		memcpy(this->content + (p - now), p + x.len, this->len - (p - now) + 1);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	delete[] now;
	return *this;
}
TString& TString::operator -= (const char c)
{
	const char* now = this->content;
	const char* p;
	if (this->len == 0 || c == 0 || (p = strchr(this->content, c)) == NULL)
		return *this;

	this->len --;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (p != this->content)
			memcpy(this->content, now, p - now);
		memcpy(this->content + (p - now), p + 1, this->len - (p - now) + 1);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	delete[] now;
	return *this;
}
TString operator * (const TString& a, const int x)
{
	if (a.len == 0 || x <= 1)
		return a;
	TString rt;
	rt.len = x * a.len;
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content) {
		strcpy(rt.content, a.content);
		for (int i = 1; i < x; ++i)
			strcat(rt.content, a.content);
	}
	else
		rt.len = 0;
	return rt;
}
TString& TString::operator *= (const int x)
{
	if (this->content == NULL || x <= 1)
		return *this;
	const char* p = this->content;
	this->len *= x;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		strcpy(this->content, p);
		for (int i = 1; i < x; ++i)
			strcat(this->content, p);
	}
	else
		this->len = 0;
	return *this;
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
