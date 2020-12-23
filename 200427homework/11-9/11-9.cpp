/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

class Teacher {
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tele;
	string title;
public:
	void display();
	Teacher();
};
void Teacher::display()
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
	cout << "title: " << title << endl;
	cout << "address: " << addr << endl;
	cout << "telephone: " << tele << endl;
}
Teacher::Teacher()
{
	name = addr = tele = title = "";
	age = 0;
	sex = 0;
}
class Cadre {
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tele;
	string post;
public:
	Cadre();
};
Cadre::Cadre()
{
	name = addr = tele = post = "";
	age = 0;
	sex = 0;
}
class Teacher_Cadre : public Teacher, public Cadre {
private:
	int wages;
public:
	void show();
	void get();
	Teacher_Cadre();
};
Teacher_Cadre::Teacher_Cadre()
{
	wages = 0;
}
void Teacher_Cadre::show()
{
	display();
	cout << "post: " << post << endl;
	cout << "wages: " << wages << endl;
}
void Teacher_Cadre::get()
{
	cin >> Teacher::name >> Teacher::age >> Teacher::sex >> Teacher::title >> Teacher::addr >> Teacher::tele;
	cin >> Cadre::post >> Teacher_Cadre::wages;
}
int main()
{
	Teacher_Cadre tc;
	tc.get();
	tc.show();
	return 0;
}
/*
戚柒 19 m 学生 地球 12315 学 12345
*/