/*1952339 –≈08 ’≈‹∞‘¬*/
#include<iostream>
#include<cstdio>
#include<iomanip>
#include"11-b2-time.h"
using namespace std;

Time::Time()
{
	hour = minute = second = 0;
}
Time::Time(const LL a, const LL b, const LL c)
{
	hour = a, minute = b, second = c;
	if (*this < TIME_MIN || (TIME_MAX.hour && *this > TIME_MAX))
		*this = TIME_MIN;
}
Time::Time(const LL dd)
{
	LL x = dd;
	hour = x / HOUR_S;
	x %= HOUR_S;
	minute = x / MINUTE_S;
	x %= MINUTE_S;
	second = x;
	if (*this < TIME_MIN || *this > TIME_MAX)
		*this = TIME_MIN;
}
Time::Time(const Time& x)
{
	hour = x.hour, minute = x.minute, second = x.second;
	if (*this < TIME_MIN || *this > TIME_MAX)
		*this = TIME_MIN;
}
void Time::set(const Time& x)
{
	*this = x;
	if (*this < TIME_MIN || *this > TIME_MAX)
		*this = TIME_MIN;
}
void Time::set(const LL h, const LL m, const LL s)
{
	*this = Time(h, m ,s);
	if (*this < TIME_MIN || *this > TIME_MAX)
		*this = TIME_MIN;
}
void Time::show()
{
	cout << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second;
}
Time::operator LL()
{
	return hour * HOUR_S + minute * MINUTE_S + second;
}
Time Time::operator + (const LL dd)
{
	LL now = LL(*this) + dd;
	now %= DAY_S;
	second = now;
	minute = second / MINUTE_S;
	second %= MINUTE_S;
	hour = minute / MINUTE_S;
	minute %= MINUTE_S;
	return *this;

}
Time& Time::operator ++ ()
{
	++second;
	minute += second / MINUTE_S;
	second %= MINUTE_S;
	hour += minute / MINUTE_S;
	minute %= MINUTE_S;
	if (*this > TIME_MAX)
		*this = TIME_MIN;
	return *this;
}
Time Time::operator ++ (int)
{
	Time rt = *this;
	++* this;
	return rt;
}
Time Time::operator - (const LL dd)
{
	LL tt = LL(*this);
	tt -= dd;
	if (tt < 0ll)
		tt += DAY_S;
	Time rt = Time(tt);
	return rt;
}
Time& Time::operator -- ()
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
	return *this;
}
Time Time::operator -- (int)
{
	Time rt = *this;
	--* this;
	return rt;
}
istream& operator >> (istream& in, Time& x)
{
	in >> x.hour >> x.minute >> x.second;
	if (x < TIME_MIN || x > TIME_MAX)
		x = TIME_MIN;
	return in;
}
ostream& operator << (ostream& out, const Time& x)
{
	out << setfill('0') << setw(2) << x.hour << ':' << setw(2) << x.minute << ':' << setw(2) << x.second;
	return out;
}
bool Time::operator > (const Time& x)const
{
	if (hour == x.hour && minute == x.minute)
		return second > x.second;
	if (hour == x.hour)
		return minute > x.minute;
	return second > x.second;
}
bool Time::operator < (const Time& x)const
{
	if (hour == x.hour && minute == x.minute)
		return second < x.second;
	if (hour == x.hour)
		return minute < x.minute;
	return second < x.second;
}
bool Time::operator >= (const Time& x)const
{
	if (hour == x.hour && minute == x.minute)
		return second >= x.second;
	if (hour == x.hour)
		return minute >= x.minute;
	return second >= x.second;
}
bool Time::operator <= (const Time& x)const
{
	if (hour == x.hour && minute == x.minute)
		return second <= x.second;
	if (hour == x.hour)
		return minute <= x.minute;
	return second <= x.second;
}
bool Time::operator == (const Time& x)const
{
	return hour == x.hour && minute == x.minute && second == x.second;
}
bool Time::operator != (const Time& x)const
{
	return hour != x.hour || minute != x.minute || second != x.second;
}