/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
#include<cstring>

class TString {
	char* v;
	int len;
	TString* nxt;
public:
	TString();
	TString(const char* p);
	TString(const TString& x);
	~TString();
	TString& operator = (const TString& x);
	TString& operator += (const TString& x);
	bool operator != (const TString& x);
	int length();
};

TString::TString()
{
	len = 0;
	v = NULL;
	nxt = NULL;
}
TString::TString(const char* p)
{
	if (p == NULL || strlen(p) == 0) {
		len = 0;
		v = NULL;
		nxt = NULL;
		return;
	}
	nxt = NULL;
	len = strlen(p);
	v = new(nothrow) char[len + 1];
	strcpy(v, p);
}
TString::TString(const TString& x)
{
	len = x.len;
	v = new(nothrow) char[len + 1];
	strcpy(v, x.v);
}
TString::~TString()
{
	if (v)
		delete[] v;
	if (nxt) {
		TString* p = nxt, * q;
		while (p != NULL) {
			q = p->nxt;
			delete[]p->v;
			p = q;
		}
	}
}

TString& TString::operator = (const TString& x)
{
	if (v)
		delete[] v;
	if (nxt) {
		TString* p = nxt, * q;
		while (p != NULL) {
			q = p->nxt;
			delete[] p->v;
			p = q;
		}
	}

	TString* p = this;
	const TString* q = &x;
	while (1) {
		p->len = q->len;
		p->v = new(nothrow) char[q->len + 1];
		strcpy(p->v, q->v);
		if (q->nxt) {
			q = q->nxt;
			p->nxt = new(nothrow) TString;
			p = p->nxt;
		}
		else
			break;
	}
	return *this;
}
TString& TString::operator += (const TString& x)
{
	TString* p = this;
	if (p->len) {
		while (p->nxt != NULL)
			p = p->nxt;
		p->nxt = new(nothrow) TString;
		p = p->nxt;
	}
	const TString* q = &x;
	int len_all = len + x.len;
	while (1) {
		p->len = q->len;
		p->v = new(nothrow) char[p->len + 1];
		strcpy(p->v, q->v);
		if (q->nxt) {
			p->nxt = new(nothrow) TString;
			p = p->nxt;
			q = q->nxt;
		}
		else
			break;
	}
	len = len_all;
	return *this;
}

bool TString::operator != (const TString& x)
{
	const TString* p = this, * q = &x;
	int i, j;
	i = j = 0;
	while (p && q) {
		while (p->v[i] && q->v[j]) {
			if (p->v[i] != q->v[j])
				return 1;
			++i, ++j;
		}
		if (p->v[i] == 0)
			p = p->nxt, i = 0;
		if (q->v[j] == 0)
			q = q->nxt, j = 0;
	}
	return 0;
}

int TString::length()
{
	return len;
}
