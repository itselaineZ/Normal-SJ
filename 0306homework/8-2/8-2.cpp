/*1952339 ��08 ��ܰ��*/
#include<iostream>
using namespace std;

class Time {
	int hour;
	int minute;
	int sec;
public:
	void set_time(void)
	{
		cin >> hour;
		cin >> minute;
		cin >> sec;
	}

	void show_time(void)
	{
		cout << hour << ":" << minute << ":" << sec << endl;
	}
};

int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();
	return 0;
}