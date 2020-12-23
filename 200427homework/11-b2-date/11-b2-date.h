/* 1952339 信08 张馨月 */
#pragma once
#include <iostream>
using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
protected:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
	Date();
	Date(const int, const int, const int);
	void set(const Date&);
	void set(const int, const int = 1, const int = 1);
	void get(int&, int&, int&);
	void show();
	Date(const int);
	operator int();
	Date operator + (const int dd);
	Date operator - (const int dd);
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

/* 如果有其它全局函数需要声明，写于此处 */
bool year_check(int y);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
const int Year = 365;
const int mth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const Date DATE_MAX(2099, 12, 31);
const Date DATE_MIN(1900, 1, 1);