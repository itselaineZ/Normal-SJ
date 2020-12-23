/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

class Time;
class Date {
public:
	Date(int, int, int);
	void display(Time&);
private:
	int month;
	int day;
	int year;
};
class Time {
public:
	Time(int, int, int);
	friend void Date::display(Time&);
private:
	int hour;
	int minute;
	int sec;
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}

void Date::display(Time& t)
{
	cout << month << "/" << day << "/" << year << endl;
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}

Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

int main()
{
	Time t1(10, 13, 56);
	Date d1(12, 25, 2004);
	d1.display(t1);
	return 0;
}