/* 1952339 信08 张馨月 */
#include <iostream>
#include <iomanip>
#include "11-b2-date.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(const int y, const int m, const int d)
{
	int a = y, b = m, c = d;
	if (a >= 1900 && a < 2100)
		year = a;
	else
		a = year = 1900;
	if (b >= 1 && b <= 12)
		month = b;
	else
		b = month = 1;
	if (c >= 1 && ((b == 2 && c <= mth[b] + year_check(a)) || c <= mth[b]))
		day = c;
	else
		day = 1;
}

void Date::set(const Date& x)
{
	*this = x;
	if (*this < DATE_MIN || *this > DATE_MAX)
		*this = DATE_MIN;
}
void Date::set(const int a, const int b, const int c)
{
	if (!a || !b || !c || a < 1900 || a > 2099 || b < 1 || b > 12 || c < 1 || (b == 2 && c > mth[b] + year_check(a)) || (b != 2 && c > mth[b]))
		year = 1900, month = 1, day = 1;
	else
		year = a, month = b, day = c;
}

void Date::get(int& a, int& b, int& c)
{
	a = year, b = month, c = day;
}

void Date::show()
{
	cout << year << "年" << month << "月" << day << "日\n";
}

Date::Date(const int dd)
{
	int x = dd;
	if (x < 0 || x > 73049) {
		year = 1900;
		month = 1;
		day = 1;
	}
	else {
		year = 1900;
		while (x >= Year + year_check(year)) {
			x -= Year + year_check(year);
			++year;
		}
		bool tg = year_check(year);
		for (month = 1; month <= 12; ++month)
			if (month == 2) {
				if (x <= mth[2] + tg)
					break;
				else
					x -= mth[2] + tg;
			}
			else {
				if (x <= mth[month])
					break;
				else
					x -= mth[month];
			}
		day = x;
	}
}

Date::operator int()
{
	int m = month, y = year;
	int rt = day;
	for (--m; m; --m)
		if (m == 2)
			rt += mth[m] + year_check(y);
		else
			rt += mth[m];
	for (--y; y >= 1900; --y)
		rt += Year + year_check(y);
	return rt;
}

Date Date::operator + (const int dd)
{
	int x = dd;
	Date rt(year, month, day);
	if (rt.month == 2) {
		if (x <= mth[rt.month] + year_check(rt.year) - rt.day) {
			rt.day += x;
			return rt > DATE_MAX ? DATE_MAX : rt;
		}
		else {
			x -= mth[rt.month] + year_check(rt.year) - rt.day;
			rt.day = mth[rt.month];
		}
	}
	else {
		if (x <= mth[rt.month] - rt.day) {
			rt.day += x;
			return rt > DATE_MAX ? DATE_MAX : rt;
		}
		else {
			x -= mth[rt.month] - rt.day;
			rt.day = mth[rt.month];
		}
	}

	bool tg = year_check(rt.year);
	for (++rt.month; rt.month <= 12; ++rt.month)
		if (rt.month == 2) {
			if (x <= mth[2] + tg) {
				rt.day = x;
				return rt > DATE_MAX ? DATE_MAX : rt;
			}
			else {
				x -= mth[2] + tg;
				rt.day = mth[2] + tg;
			}
		}
		else {
			if (x <= mth[rt.month]) {
				rt.day = x;
				return rt > DATE_MAX ? DATE_MAX : rt;
			}
			else {
				rt.day = mth[rt.month];
				x -= mth[rt.month];
			}
		}

	--rt.month;
	for (rt.year++; x >= Year + year_check(rt.year); ++rt.year)
		x -= Year + year_check(rt.year);

	tg = year_check(rt.year);
	for (rt.month = 1; rt.month <= 12; ++rt.month)
		if (rt.month == 2) {
			if (x <= mth[2] + tg) {
				rt.day = x;
				return rt > DATE_MAX ? DATE_MAX : rt;
			}

			else {
				rt.day = mth[2] + tg;
				x -= mth[2] + tg;
			}
		}
		else {
			if (x <= mth[rt.month]) {
				rt.day = x;
				return rt > DATE_MAX ? DATE_MAX : rt;
			}
			else {
				rt.day = mth[rt.month];
				x -= mth[rt.month];
			}
		}
	--rt.month;
	return rt > DATE_MAX ? DATE_MAX : rt;
}
Date Date::operator - (const int dd)
{
	int x = dd;
	Date rt(year, month, day);
	if (x < rt.day) {
		rt.day -= x;
		return rt < DATE_MIN ? DATE_MIN : rt;
	}
	else {
		x -= rt.day;
		rt.day = mth[rt.month];
		if (rt.month == 0)
			--rt.year, rt.month = 12, rt.day = 31;
	}


	bool tg = year_check(rt.year);
	for (--rt.month; rt.month; --rt.month)
		if (rt.month == 2) {
			if (x < mth[rt.month] + tg) {
				rt.day = mth[rt.month] + tg - x;
				return rt < DATE_MIN ? DATE_MIN : rt;
			}
			else {
				x -= mth[rt.month] + tg;
				rt.day = mth[1];
			}
		}
		else {
			if (x < mth[rt.month]) {
				rt.day = mth[rt.month] - x;
				return rt < DATE_MIN ? DATE_MIN : rt;
			}
			else {
				x -= rt.day;
				if (rt.month == 3)
					rt.day = mth[2] + tg;
				else if (rt.month == 1)
					rt.day = 31;
				else
					rt.day = mth[rt.month - 1];
			}
		}

	rt.year--;
	for (rt.year--; x >= Year + year_check(rt.year); --rt.year)
		x -= Year + year_check(rt.year);
	++rt.year;
	tg = year_check(rt.year);
	for (rt.month = 12; rt.month; --rt.month)
		if (rt.month == 2) {
			if (x < mth[rt.month] + tg) {
				rt.day = mth[rt.month] + tg - x;
				return rt < DATE_MIN ? DATE_MIN : rt;
			}
			else {
				x -= mth[rt.month] + tg;
				rt.day = mth[1];
			}
		}
		else {
			if (x < mth[rt.month]) {
				rt.day = mth[rt.month] - x;
				return rt < DATE_MIN ? DATE_MIN : rt;
			}
			else {
				x -= mth[rt.month];
				if (rt.month == 3)
					rt.day = mth[rt.month - 1] + tg;
				else
					rt.day = mth[rt.month - 1];
			}
		}

	++rt.month;
	return rt < DATE_MIN ? DATE_MIN : rt;
}
int Date::operator - (Date& x)
{
	return int(*this) - int(x);
}
Date& Date::operator ++ ()
{
	Date DATE_MAX(2099, 12, 31);
	if (month == 2) {
		if (day == mth[2] + year_check(year))
			++month, day = 1;
		else
			++day;
	}
	else if (month == 12) {
		if (day == mth[12])
			++year, month = 1, day = 1;
		else
			++day;
	}
	else {
		if (day == mth[month])
			++month, day = 1;
		else
			++day;
	}
	if (*this > DATE_MAX)
		*this = DATE_MIN;
	return *this;
}
Date Date::operator ++ (int)
{
	Date c = *this;
	if (month == 2) {
		if (day == mth[2] + year_check(year))
			++month, day = 1;
		else
			++day;
	}
	else if (month == 12) {
		if (day == mth[12])
			++year, month = 1, day = 1;
		else
			++day;
	}
	else {
		if (day == mth[month])
			++month, day = 1;
		else
			++day;
	}
	*this = *this > DATE_MAX ? DATE_MIN : *this;
	return c > DATE_MAX ? DATE_MIN : c;
}
Date& Date::operator -- ()
{
	if (month == 3) {
		if (day == 1)
			--month, day = mth[month] + year_check(year);
		else
			--day;
	}
	else if (month == 1) {
		if (day == 1)
			--year, month = 12, day = mth[12];
		else
			--day;
	}
	else {
		if (day == 1)
			--month, day = mth[month];
		else
			--day;
	}
	if (*this < DATE_MIN)
		*this = DATE_MAX;
	return *this;
}
Date Date::operator -- (int)
{
	Date DATE_MIN(1900, 1, 1);
	Date c = *this;
	if (month == 3) {
		if (day == 1)
			--month, day = mth[month] + year_check(year);
		else
			--day;
	}
	else if (month == 1) {
		if (day == 1)
			--year, month = 12, day = mth[12];
		else
			--day;
	}
	else {
		if (day == 1)
			--month, day = mth[month];
		else
			--day;
	}
	*this = *this < DATE_MIN ? DATE_MAX : *this;
	return c < DATE_MIN ? DATE_MAX : c;
}

istream& operator >> (istream& in, Date& x)
{
	int y, m, d;
	in >> y >> m >> d;
	x = Date(y, m, d);
	return in;
}
ostream& operator << (ostream& out, const Date& x)
{
	out << setfill('0') << setw(4) << x.year << '-' << setw(2) << x.month << '-' << setw(2) << x.day;
	return out;
}

bool Date::operator < (const Date& x)const
{
	if (year == x.year && month == x.month)
		return day < x.day;
	else if (year == x.year)
		return month < x.month;
	else
		return year < x.year;
}
bool Date::operator > (const Date& x)const
{
	if (year == x.year && month == x.month)
		return day > x.day;
	else if (year == x.year)
		return month > x.month;
	else
		return year > x.year;
}
bool Date::operator <= (const Date& x)const
{
	if (year == x.year && month == x.month)
		return day <= x.day;
	else if (year == x.year)
		return month <= x.month;
	else
		return year <= x.year;
}
bool Date::operator >= (const Date& x)const
{
	if (year == x.year && month == x.month)
		return day >= x.day;
	else if (year == x.year)
		return month >= x.month;
	else
		return year >= x.year;
}
bool Date::operator == (const Date& x)const
{
	return year == x.year && month == x.month && day == x.day;
}
bool Date::operator != (const Date& x)const
{
	return year != x.year || month != x.month || day != x.day;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
bool year_check(int y)
{
	return (y % 400 == 0) || (y % 100 && y % 4 == 0);
}
