/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<iostream>
#include<cstdio>
using namespace std;

class Student {
public:
	Student()
	{
		num = 0;
		name = "";
		sex = 0;
	}
protected:
	int num;
	string name;
	char sex;
};
class Student1 : public Student {
public:
	void get_value1();
	void display1();
	Student1()
	{
		age = 0;
		addr = "";
	}
private:
	int age;
	string addr;
};
void Student1::get_value1()
{
	cin >> num >> name >> sex;
	cin >> age >> addr;
}
void Student1::display1()
{
	cout << "num: " << num << endl;
	cout << "name: " << name << endl;
	cout << "sex: " << sex << endl;
	cout << "age: " << age << endl;
	cout << "address: " << addr << endl;
}
int main()
{
	Student1 stud1;
	stud1.get_value1();
	stud1.display1();
	return 0;
}