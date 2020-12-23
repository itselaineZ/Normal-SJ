#pragma once
/* 1952339 信08 张馨月 */
#include <iostream>
using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
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

/* 如果有其它全局函数需要声明，写于此处 */
bool year_check(int y);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
const int Year = 365;
const int mth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };