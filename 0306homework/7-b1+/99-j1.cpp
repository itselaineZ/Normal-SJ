/* 1952339 信08 张馨月 */
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string.h>	//Dev/CB的strlen需要
using namespace std;
#ifndef __linux
	#include <conio.h>	//用getch，因此不需要支持Linux
#endif
struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;	//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

/* 可以在此定义其它需要的函数 */



/***************************************************************************
  函数名称：
  功    能：给出提示并等待回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //思考一下，||的左右两个条件能否互换
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt << "，按回车键继续";

#ifdef __linux 
	while (getchar() != '\r' && getchar() != '\n')
		;
#else
	while (_getch() != '\r')
		;
#endif
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：调用系统的转换函数将整型秒值转换为与本题相似的结构体并输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t的本质是64位无符号整数
{
	struct tm* tt;	//struct tm 为系统定义的结构体

	tt = localtime(&input_time);	//localtime为系统函数
	
	/* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
	cout << tt->tm_year + 1900 << '-' << tt->tm_mon + 1 << '-' << tt->tm_mday << ' ' << tt->tm_hour << ':' << tt->tm_min << ':' << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换结果输出函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* 实现自定义结构的输出，输出形式与system_time_output相同 */
	cout << tp->tj_year << '-' << tp->tj_month << '-' << tp->tj_day << ' ' << tp->tj_hour << ':' << tp->tj_minute << ':' << tp->tj_second << endl;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
struct tj_time* tj_time_convert(const time_t input_time0)
{
	static struct tj_time result;	//定义静态局部变量，不准动

	/* 实现过程开始，在下面添加相应的定义及执行语句即可 */

	int input_time = input_time0;
	result.tj_year = 1970;
	result.tj_month = 0;
	result.tj_day = 0;
	result.tj_hour = result.tj_minute = result.tj_second = 0;

	const int yrs_4 = (365 * 4 + 1) * 24 * 60 * 60, yrs_1 = 365 * 24 * 60 * 60;
	const int dys = 24 * 60 * 60, hrs = 60 * 60, mts = 60, MTH = 12;
	int mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	struct tm* tt;
	int delta_t;
	tt = localtime(&input_time0);
	delta_t = tt->tm_hour;
	tt = gmtime(&input_time0);

	input_time += hrs * (delta_t-tt->tm_hour);
	//cout << delta_t - tt->tm_hour << endl;

	result.tj_year += input_time / yrs_4 * 4;
	input_time %= yrs_4;

	if (input_time >= yrs_1 * 3 + dys) {
		input_time -= yrs_1 * 3 + dys;
		result.tj_year += 3;
	}
	else if (input_time >= yrs_1 * 2) {
		input_time -= yrs_1 * 2;
		result.tj_year += 2;
		mth[2] ++;
	}
	else {
		result.tj_year += input_time / yrs_1;
		input_time %= yrs_1;
	}

	for (int i = 1; i <= MTH && input_time >= mth[i] * dys; ++i) {
		input_time -= mth[i] * dys;
		result.tj_month = i;
	}
	++result.tj_month;

	result.tj_day = input_time / dys + 1;
	input_time %= dys;
	result.tj_hour = input_time / hrs;
	input_time %= hrs;
	result.tj_minute = input_time / mts;
	input_time %= mts;
	result.tj_second = input_time;

	/* 实现过程结束 */

	return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	struct tj_time* tp;
	time_t t = time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

	cout << "当前系统时间    ：" << (int)t << endl;
	cout << "系统转换的结果  ：";
	system_time_output(t);

	cout << "自定义转换的结果：";
	tp = tj_time_convert(t);
	tj_time_output(tp);

	wait_for_enter();

	return 0;
}
