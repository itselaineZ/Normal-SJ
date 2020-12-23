/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

class Student {
public:
	void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << "name: " << name << endl;
		cout << "num: " << num << endl;
		cout << "sex: " << sex << endl;
	}
	Student()
	{
		num = 0;
		name = "";
		sex = 0;
	}
private:
	int num;
	string name;
	char sex;
};

class Student1 : public Student {
public:
	void get_value_1()
	{
		cin >> age >> addr;
	}
	void display_1()
	{
		cout << "age: " << age << endl;
		cout << "address: " << addr << endl;
	}
	Student1()
	{
		age = 0;
		addr = "";
	}
private:
	int age;
	string addr;
};

int main()
{
	Student1 stud;
	stud.get_value();
	stud.get_value_1();
	stud.display();
	stud.display_1();
	return 0;
}