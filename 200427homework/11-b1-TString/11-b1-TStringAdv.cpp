/*1952339 –≈08 ’≈‹∞‘¬*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string.h>
#include"11-b1-TStringAdv.h"
using namespace std;

TStringAdv::TStringAdv(){}
TStringAdv::TStringAdv(const TString ts1): TString(ts1){}
TStringAdv::TStringAdv(const char* s) : TString(s) {}

TStringAdv& TStringAdv::assign(const TStringAdv& ts2)
{
	if (this->content)
		delete[] this->content;
	this->len = 0;
	this->content = NULL;
	if (ts2.len == 0)
		return *this;
	this->len = ts2.len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content)
		memcpy(this->content, ts2.content, ts2.len);
	else
		this->len = 0;
	this->content[this->len] = 0;
	return *this;
}
TStringAdv& TStringAdv::assign(const char* s)
{
	if (this->content)
		delete[] this->content;
	this->len = 0;
	this->content = NULL;
	if (s == NULL || s[0] == 0)
		return *this;
	this->len = strlen(s);
	this->content = new(nothrow) char[this->len + 1];
	if (this->content)
		memcpy(this->content, s, this->len);
	else
		this->len = 0;
	this->content[this->len] = 0;
	return *this;
}
TStringAdv& TStringAdv::assign(const char& c)
{
	const char* p = this->content;
	this->len = 0;
	this->content = NULL;
	if (c == 0)
		return *this;
	this->len ++;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		memcpy(this->content, p, this->len - 1);
		this->content[this->len - 1] = c;
		this->content[this->len] = 0;
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	return *this;
}
TStringAdv& TStringAdv::append(const TStringAdv& ts2)
{
	char* p = this->content;
	if (ts2.len == 0)
		return *this;
	this->len += ts2.len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		strcpy(this->content, p ? p : "");
		strcat(this->content, ts2.content);
	}
	else
		this->len = 0;
	if (p)
		delete[] p;
	return *this;
}
TStringAdv& TStringAdv::append(const char* s)
{
	char* p = this->content;
	if (s == NULL || s[0] == 0)
		return *this;
	this->len += strlen(s);
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		strcpy(this->content, p ? p : "");
		strcat(this->content, s);
	}
	else
		this->len = 0;
	if (p)
		delete[] p;
	return *this;
}
TStringAdv& TStringAdv::append(const char& c)
{
	if (c == 0)
		return *this;
	char* p = this->content;
	++this->len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		strcpy(this->content, p ? p : "");
		this->content[this->len - 1] = c;
		this->content[this->len] = 0;
	}
	else
		this->len = 0;
	if (p)
		delete[] p;
	return *this;
}
TStringAdv& TStringAdv::insert(const TStringAdv& ts2, int pos)
{
	--pos;
	if (pos < 0 || pos > this->len || ts2.len == 0)
		return *this;
	const char* p = this->content;
	this->len += ts2.len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (pos)
			memcpy(this->content, p, pos);
		memcpy(this->content + pos, ts2.content, ts2.len);
		memcpy(this->content + pos + ts2.len, p + pos, this->len - pos - ts2.len);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	return *this;
}
TStringAdv& TStringAdv::insert(const char* s, int pos)
{
	--pos;
	if (pos < 0 || pos > this->len || s == NULL || s[0] == 0)
		return *this;
	const char* p = this->content;
	int slen = strlen(s);
	this->len += slen;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (pos)
			memcpy(this->content, p, pos);
		memcpy(this->content + pos, s, slen);
		memcpy(this->content + pos + slen, p + pos, this->len - pos - slen);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	return *this;
}
TStringAdv& TStringAdv::insert(const char& c, int pos)
{
	--pos;
	if (pos < 0 || pos > this->len || c == 0)
		return *this;
	const char* p = this->content;
	this->len ++;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (pos)
			memcpy(this->content, p, pos);
		this->content[pos] = c;
		memcpy(this->content + pos + 1, p + pos, this->len - pos - 1);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	return *this;
}
TStringAdv& TStringAdv::erase(const TStringAdv& ts2)
{
	const char* now = this->content;
	const char* p;
	if (this->len == 0 || ts2.len == 0 || (p = strstr(this->content, ts2.content)) == NULL)
		return *this;

	this->len -= ts2.len;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (p != this->content)
			memcpy(this->content, now, p - now);
		memcpy(this->content + (p - now), p + ts2.len, this->len - (p - now) + 1);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	delete[] now;
	return *this;
}
TStringAdv& TStringAdv::erase(const char* s)
{
	const char* now = this->content;
	const char* p;
	if (this->len == 0 || s == 0 || s[0] == 0 || (p = strstr(this->content, s)) == NULL)
		return *this;

	int slen = strlen(s);
	this->len -= slen;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (p != this->content)
			memcpy(this->content, now, p - now);
		memcpy(this->content + (p - now), p + slen, this->len - (p - now) + 1);
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	delete[] now;
	return *this;
}
TStringAdv& TStringAdv::erase(const char& c)
{
	const char* now = this->content;
	const char* p;
	if (this->len == 0 || c == 0 || (p = strchr(this->content, c)) == NULL)
		return *this;

	this->len--;
	this->content = new(nothrow) char[this->len + 1];
	if (this->content) {
		if (p != this->content)
			memcpy(this->content, now, p - now);
		memcpy(this->content + (p - now), p + 1, this->len - (p - now));
	}
	else
		this->len = 0;
	this->content[this->len] = 0;
	delete[] now;
	return *this;
}
TStringAdv TStringAdv::substr(const int pos, const int len)
{
	int p = pos-1;
	if (p < 0 || p > this->len || p + len > this->len)
		return NULL;
	TStringAdv rt;
	rt.len = (len == -1 ? this->len - pos + 1 : len);
	rt.content = new(nothrow) char[rt.len + 1];
	if (rt.content)
		memcpy(rt.content, this->content + p, (len == -1 ? this->len - pos + 1 : len));
	else
		rt.len = 0;
	rt.content[rt.len] = 0;
	return rt;
}
char& TStringAdv::at(const int n)
{
	return this->content[n];
}

istream& operator >> (istream& in, TStringAdv x)
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
ostream& operator << (ostream& out, TStringAdv x)
{
	if (x.content == NULL)
		out << "<NULL>";
	else
		out << x.content;
	return out;
}