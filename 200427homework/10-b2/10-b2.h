#pragma once
/* 1952339 ��08 ��ܰ�� */
#include <iostream>
using namespace std;

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */
public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date();
	Date(int, int, int);
	void set(int, int = 1, int = 1);
	void get(int&, int&, int&);
	void show();
	Date(int);
	operator int();
	Date operator + (int x);
	Date operator - (int x);
	int operator - (Date& x);
	Date& operator ++ ();
	Date operator ++ (int);
	Date& operator -- ();
	Date operator -- (int);
	friend istream& operator >> (istream& in, Date& x);
	friend ostream& operator << (ostream& out, const Date& x);
	bool operator < (const Date& x)const;
	bool operator > (const Date& x)const;
	bool operator >= (const Date& x)const;
	bool operator <= (const Date& x)const;
	bool operator == (const Date& x)const;
	bool operator != (const Date& x)const;
};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
bool year_check(int y);
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
const int Year = 365;
const int mth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };