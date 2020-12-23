/*1952339 信08 张馨月*/
#include<iostream>
using namespace std;

class Time {
	public://缺省为private
		void set_time(void);
		void show_time(void);
		int hour;
		int minute;
		int sec;
};

Time t;

int main()
{
	t.set_time();//set_time();
	t.show_time();//show_time();
	return 0;
}

void Time::set_time(void)//int set_time(void)
{
	cin >> hour;//cin>>t.hour;
	cin >> minute;//cin>>t.minute;
	cin >> sec;//cin>>t.sec
}

void Time::show_time(void)//int show_time(void)
{
	cout << hour << ":" << minute << ":" << sec << endl;//cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}