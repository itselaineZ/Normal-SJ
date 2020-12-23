/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include"11-b2-date.h"
#include"11-b2-time.h"
#include"11-b2-datetime.h"
using namespace std;

#if defined(__linux) || defined(__linux__)
#include <sys/time.h>
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

long get_cur_msec(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);

	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

#else
#include <Windows.h>
#include <conio.h>
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}


#endif

int main()
{

	if (1) {
		cout << "下面开始对Date类进行测试\n\n";

		wait_for_enter();

		if (1) {
			cout << "测试 ++ / -- 的实现\n";
			Date d1, d2;

			d1.set(2099, 12, 31);
			d2 = ++d1;
			cout << "应输出1900-01-01    实际上：" << d2 << endl;

			d1.set(2099, 12, 31);
			d2 = d1++;
			cout << "应输出2099-12-31    实际上：" << d2 << endl;

			d1.set(1900, 1, 1);
			d2 = --d1;
			cout << "应输出2099-12-31    实际上：" << d2 << endl;

			d1.set(1900, 1, 1);
			d2 = d1--;
			cout << "应输出1900-01-01    实际上：" << d2 << endl;

			wait_for_enter();
		}
		if (1) {
			cout << "测试比较运算符\n";

			Date d1(2012, 12, 3);
			Date d2(2012, 12, 2);
			Date d3(2012, 12, 3);

			cout << "比较结果应为1，实际为：" << (d1 > d2) << endl;
			cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 < d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 <= d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 == d2) << endl;
			cout << "比较结果应为1，实际为：" << (d1 != d2) << endl;

			cout << "比较结果应为0，实际为：" << (d1 > d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
			cout << "比较结果应为0，实际为：" << (d1 < d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 <= d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 == d3) << endl;
			cout << "比较结果应为0，实际为：" << (d1 != d3) << endl;

			wait_for_enter();
		}

	}

	if (1) {
		cout << "下面开始对Time类进行测试\n\n";

		wait_for_enter();

		if (1) {
			cout << "测试 + / - 的实现\n";
			Time t1, t2;

			t1.set(13, 59, 59);
			t2.set(12, 0, 0);
			cout << "应输出01:59:59    实际上：" << t1 + t2 << endl;

			t1.set(13, 59, 59);
			t2.set(12, 0, 0);
			cout << "应输出01:59:59    实际上：" << t1 - t2 << endl;

			t1.set(0, 59, 59);
			t2.set(12, 0, 0);
			cout << "应输出12:59:59    实际上：" << t1 + t2 << endl;

			t1.set(0, 59, 59);
			t2.set(12, 0, 0);
			cout << "应输出12:59:59    实际上：" << t1 - t2 << endl;

			wait_for_enter();
		}
		if (1) {
			cout << "测试 ++ / -- 的实现";
			Time t1, t2;

			t1.set(23, 59, 59);
			t2 = ++t1;
			cout << "应输出00:00:00    实际上：" << t2 << endl;

			t1.set(23, 59, 59);
			t2 = t1++;
			cout << "应输出23:59:59    实际上：" << t2 << endl;

			t1.set(0, 0, 0);
			t2 = --t1;
			cout << "应输出23:59:59    实际上：" << t2 << endl;

			t1.set(0, 0, 0);
			t2 = t1--;
			cout << "应输出00:00:00    实际上：" << t2 << endl;

			wait_for_enter();
		}
		if (1) {
			cout << "测试比较运算符\n";

			Time d1(12, 12, 3);
			Time d2(12, 12, 2);
			Time d3(12, 12, 3);

			cout << "比较结果应为1，实际为：" << (d1 > d2) << endl;
			cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 < d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 <= d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 == d2) << endl;
			cout << "比较结果应为1，实际为：" << (d1 != d2) << endl;

			cout << "比较结果应为0，实际为：" << (d1 > d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
			cout << "比较结果应为0，实际为：" << (d1 < d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 <= d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 == d3) << endl;
			cout << "比较结果应为0，实际为：" << (d1 != d3) << endl;

			wait_for_enter();
		}
	}

	if (1) {
		cout << "下面开始对DateTime类进行测试\n\n";

		wait_for_enter();

		if (1) {
			cout << "测试 ++ / -- 的实现\n";
			DateTime dt1, dt2(2099, 12, 31, 23, 59, 59);

			dt1.set(2099, 12, 31, 23, 59, 59);
			dt2 = ++dt1;
			cout << "应输出1900-01-01 00:00:00    实际上：" << dt2 << endl;

			dt1.set(2099, 12, 31, 23, 59, 59);
			dt2 = dt1++;
			cout << "应输出2099-12-31 23:59:59    实际上：" << dt2 << endl;

			dt1.set(1900, 1, 1, 0, 0, 0);
			dt2 = --dt1;
			cout << "应输出2099-12-31 23:59:59    实际上：" << dt2 << endl;

			dt1.set(1900, 1, 1, 0, 0, 0);
			dt2 = dt1--;
			cout << "应输出1900-01-01 00:00:00    实际上：" << dt2 << endl;
		}

		if (1) {
			cout << "测试比较运算符\n";

			DateTime d1(2001, 12, 23, 12, 12, 3);
			DateTime d2(2001, 12, 23, 12, 12, 2);
			DateTime d3(2001, 12, 23, 12, 12, 3);

			cout << "比较结果应为1，实际为：" << (d1 > d2) << endl;
			cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 < d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 <= d2) << endl;
			cout << "比较结果应为0，实际为：" << (d1 == d2) << endl;
			cout << "比较结果应为1，实际为：" << (d1 != d2) << endl;

			cout << "比较结果应为0，实际为：" << (d1 > d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
			cout << "比较结果应为0，实际为：" << (d1 < d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 <= d3) << endl;
			cout << "比较结果应为1，实际为：" << (d1 == d3) << endl;
			cout << "比较结果应为0，实际为：" << (d1 != d3) << endl;

			wait_for_enter();
		}
	}
	return 0;
}