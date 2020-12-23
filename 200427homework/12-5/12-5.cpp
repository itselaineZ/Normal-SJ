/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
#include<cmath> 
#define pi 3.1415926
using namespace std;

class Shape {
public:
	virtual void area(){}
};

class Circle : public Shape {
private:
	int r;
public:
	Circle() 
	{
		r = 0;
	}
	Circle(const int rr)
	{
		r = rr;
	}
	virtual void area()
	{
		cout << double(r) * r * pi << endl;
	}
};

class Square : public Shape {
private:
	int a;
public:
	Square()
	{
		a = 0;
	}
	Square(const int rr)
	{
		a = rr;
	}
	virtual void area()
	{
		cout << a*a << endl;
	}
};

class Rectangle : public Shape {
private:
	int a, b;
public:
	Rectangle()
	{
		a = b = 0;
	}
	Rectangle(const int aa, const int bb)
	{
		a = aa, b = bb;
	}
	virtual void area()
	{
		cout << a * b << endl;
	}
};

class Trapezoid : public Shape {
private:
	int a, b, h;
public:
	Trapezoid()
	{
		a = b = h = 0;
	}
	Trapezoid(const int aa, const int bb, const int hh)
	{
		a = aa, b = bb, h = hh;
	}
	virtual void area()
	{
		cout << (double(a) + b) * h / 2.0 << endl;
	}
};

class Triangle : public Shape {
private:
	int a, b, c;
public:
	Triangle()
	{
		a = b = c = 0;
	}
	Triangle(const int aa, const int bb, const int cc)
	{
		a = aa, b = bb, c = cc;
	}
	virtual void area()
	{
		double p = (double(a) + b + c) / 2.0;
		cout << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
	}
};

int main()
{
	Circle c1(1);
	Square s1(1);
	Rectangle r1(1, 2);
	Trapezoid t1(1, 2, 3);
	Triangle t2(1, 2, 2);
	Shape* s[5] = {&c1, &s1, &r1, &t1, &t2};

	for (int i = 0; i < 5; ++i)
		s[i]->area();
	return 0;
}
