/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

class Teacher {
private:
	int num;
	string name;
	char sex;
public:
	Teacher() 
	{
		num = 0;
		name = "";
		sex = 0;
	}
	Teacher(int a, string b, char c)
	{
		num = a;
		name = b;
		sex = c;
	}
	void display()
	{
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		cout << "sex: " << sex << endl;
	}
};
class BirthDate {
private:
	int year, month, day;
public:
	BirthDate() 
	{
		year = month = day = 0;
	}
	BirthDate(int a, int b, int c)
	{
		year = a;
		month = b;
		day = c;
	}
	void set(int a, int b, int c);
	void display()
	{
		cout << "year: " << year << endl;
		cout << "month: " << month << endl;
		cout << "day: " << day << endl;
	}
};
void BirthDate::set(int a, int b, int c)
{
	year = a;
	month = b;
	day = c;
}

class Professor : public Teacher {
private:
	BirthDate birthday;
public:
	Professor() {}
	Professor(int a, string b, char c, int d, int e, int f):Teacher(a, b, c), birthday(d, e, f){}
	void bir_change(int a, int b, int c)
	{
		birthday.set(a, b, c);
	}
	void show()
	{
		display();
		birthday.display();
	}
};

int main() 
{
	Professor prof1(6, "andrew", 'f', 1976, 7, 3);
	prof1.bir_change(1988, 3, 22);
	prof1.show();
	return 0;
}