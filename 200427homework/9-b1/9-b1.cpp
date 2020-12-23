/* 1952339 信08 张馨月 */
#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
public:
	int calc_days();     //计算是当年的第几天
	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限 */
	Days(int, int, int);
};

/* 此处给出类成员函数的体外实现 */

Days::Days(int a, int b, int c) :year(a), month(b), day(c)
{}

int Days::is_leap_year()
{
	if ((year % 100 && year % 4 == 0) || (year % 400 == 0))
		return 1;
	return 0;
}

int Days::calc_days()
{
	int mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 100 && year % 4 == 0) || (year % 400 == 0))
		++mth[2];
	if (month > 12 || month < 1)
		return 0;
	if (day > mth[month])
		return -1;
	int cnt = day;
	for (int i = 1; i < month; ++i)
		cnt += mth[i];
	return cnt;
}


/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
