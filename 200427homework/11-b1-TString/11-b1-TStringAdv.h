/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#pragma once
#include<iostream>
#include"11-b1-TString.h"
using namespace std;

class TStringAdv: protected TString {
public:
	TStringAdv();
	TStringAdv(const TString ts1);
	TStringAdv(const char* s);
	TStringAdv& assign(const TStringAdv& ts2);
	TStringAdv& assign(const char* s);
	TStringAdv& assign(const char& c);
	TStringAdv& append(const TStringAdv& ts2);
	TStringAdv& append(const char* s);
	TStringAdv& append(const char& c);
	TStringAdv& insert(const TStringAdv& ts2, int pos);
	TStringAdv& insert(const char* s, int pos);
	TStringAdv& insert(const char& c, int pos);
	TStringAdv& erase(const TStringAdv& ts2);
	TStringAdv& erase(const char* s);
	TStringAdv& erase(const char& c);
	TStringAdv substr(const int pos, const int len = -1);
	char& at(const int n);
	friend istream& operator >> (istream& in, TStringAdv x);
	friend ostream& operator << (ostream& out, TStringAdv x);
};