/*1952339 –≈08 ’≈‹∞‘¬*/
#include<iostream>
#include<cstdio>
#include"11-b2-date.h"
#include"11-b2-time.h"
#include"11-b2-datetime.h"
using namespace std;

DateTime::DateTime() :Date(), Time(){}
DateTime::DateTime(const int dd)
{
	Time tm(dd%DAY_S);
	Time::set(tm);
	if (dd / DAY_S) {
		Date dt(dd / DAY_S);
		Date::set(dt);
	}
}
DateTime::DateTime(const LL dd)
{
	Time tm(int(dd % DAY_S));
	Time::set(tm);
	if (dd / DAY_S) {
		Date dt(int(dd / DAY_S));
		Date::set(dt);
	}
}
DateTime::DateTime(const Date& x)
{
	Time::set(0, 0, 0);
	Date::set(x);
	if (*this < DT_MIN || *this > DT_MAX)
		*this = DT_MIN;
}
DateTime::DateTime(const Time& x)
{
	Time::set(x);
	Date::set(1900, 0, 0);
	if (*this < DT_MIN || *this > DT_MAX)
		*this = DT_MIN;
}
DateTime::DateTime(const DateTime& x)
{
	*this = x;
	if (*this < DT_MIN || *this > DT_MAX)
		*this = DT_MIN;
}
DateTime::DateTime(const int a, const int b, const int c, const LL d, const LL e, const LL f)
{
	Date::set(a, b, c);
	Time::set(d, e, f);
}
void DateTime::set(const int a, const int b, const int c, const LL d, const LL e, const LL f)
{
	Date::set(a, b, c);
	Time::set(d, e, f);
	if (*this < DT_MIN || *this > DT_MAX)
		*this = DT_MIN;
}
DateTime::operator LL()
{
	LL rt = 0ll;
	Date dt(year, month, day);
	Time tm(hour, minute, second);
	rt += 1ll * int(dt) * DAY_S;
	rt += int(tm);
	return rt;
}
DateTime DateTime::operator + (const LL x)
{
	second += x;
	minute += second / MINUTE_S;
	second %= MINUTE_S;
	hour += minute / MINUTE_S;
	int add_dt = int(hour / 24);
	hour %= 24;
	Date dt(year, month, day);
	dt = dt + add_dt;
	Date::set(dt);
	if (*this < DT_MIN || *this > DT_MAX)
		*this = DT_MIN;
	return *this;
}
DateTime& DateTime::operator ++()
{
	++second;
	if (second != MINUTE_S)
		return *this;
	++minute;
	second = 0;
	if (minute != MINUTE_S)
		return *this;
	minute = 0;
	++hour;
	if (hour != 24)
		return *this;
	hour = 0;
	Date dt(year, month, day);
	dt++;
	Date::set(dt);
	if (*this > DT_MAX)
		*this = DT_MIN;
	return *this;
}
DateTime DateTime::operator ++(int)
{
	DateTime dt = *this;
	++* this;
	if ( *this > DT_MAX)
		*this = DT_MIN;
	return dt;
}
DateTime DateTime::operator - (const LL x)
{
	LL dt_num = LL(*this);
	dt_num -= x;
	DateTime rt(dt_num);
	return rt;
}
DateTime& DateTime::operator -- ()
{
	if (second) {
		--second;
		return *this;
	}
	second = 59;
	if (minute) {
		--minute;
		return *this;
	}
	minute = 59;
	if (hour) {
		--hour;
		return *this;
	}
	hour = 23;
	Date dt(year, month, day);
	--dt;
	Date::set(dt);
	if (*this < DT_MIN)
		*this = DT_MAX;
	return *this;
}
DateTime DateTime::operator --(int)
{
	DateTime rt = *this;
	--* this;
	return rt;
}
istream& operator >> (istream& in, DateTime& x)
{
	Date dt;
	in >> dt;
	Time tm;
	in >> tm;
	x.Date::set(dt);
	x.Time::set(tm);
	return in;
}
ostream& operator << (ostream& out, const DateTime& x)
{
	Date dt(x.year, x.month, x.day);
	out << dt << ' ';
	Time tm(x.hour, x.minute, x.second);
	out << tm;
	return out;
}
bool DateTime::operator > (const DateTime& x)const
{
	Date dt_1(year, month, day), dt_2(x.year, x.month, x.day);
	Time tm_1(hour, minute, second), tm_2(x.hour, x.minute, x.second);
	if (dt_1 == dt_2)
		return tm_1 > tm_2;
	return dt_1 > dt_2;
}
bool DateTime::operator < (const DateTime& x)const
{
	Date dt_1(year, month, day), dt_2(x.year, x.month, x.day);
	Time tm_1(hour, minute, second), tm_2(x.hour, x.minute, x.second);
	if (dt_1 == dt_2)
		return tm_1 < tm_2;
	return dt_1 < dt_2;
}
bool DateTime::operator >= (const DateTime& x)const
{
	Date dt_1(year, month, day), dt_2(x.year, x.month, x.day);
	Time tm_1(hour, minute, second), tm_2(x.hour, x.minute, x.second);
	if (dt_1 == dt_2)
		return tm_1 >= tm_2;
	return dt_1 >= dt_2;
}
bool DateTime::operator <= (const DateTime& x)const
{
	Date dt_1(year, month, day), dt_2(x.year, x.month, x.day);
	Time tm_1(hour, minute, second), tm_2(x.hour, x.minute, x.second);
	if (dt_1 == dt_2)
		return tm_1 <= tm_2;
	return dt_1 <= dt_2;
}
bool DateTime::operator == (const DateTime& x)const
{
	Date dt_1(year, month, day), dt_2(x.year, x.month, x.day);
	Time tm_1(hour, minute, second), tm_2(x.hour, x.minute, x.second);
	return dt_1 == dt_2 && tm_1 == tm_2;
}
bool DateTime::operator != (const DateTime& x)const
{
	Date dt_1(year, month, day), dt_2(x.year, x.month, x.day);
	Time tm_1(hour, minute, second), tm_2(x.hour, x.minute, x.second);
	return dt_1 != dt_2 || tm_1 != tm_2;
}