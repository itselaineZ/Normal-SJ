/*1952339 ��08 ��ܰ��*/
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
	cout << endl << "���س�������";
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
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}


#endif

int main()
{

	if (1) {
		cout << "���濪ʼ��Date����в���\n\n";

		wait_for_enter();

		if (1) {
			cout << "���� ++ / -- ��ʵ��\n";
			Date d1, d2;

			d1.set(2099, 12, 31);
			d2 = ++d1;
			cout << "Ӧ���1900-01-01    ʵ���ϣ�" << d2 << endl;

			d1.set(2099, 12, 31);
			d2 = d1++;
			cout << "Ӧ���2099-12-31    ʵ���ϣ�" << d2 << endl;

			d1.set(1900, 1, 1);
			d2 = --d1;
			cout << "Ӧ���2099-12-31    ʵ���ϣ�" << d2 << endl;

			d1.set(1900, 1, 1);
			d2 = d1--;
			cout << "Ӧ���1900-01-01    ʵ���ϣ�" << d2 << endl;

			wait_for_enter();
		}
		if (1) {
			cout << "���ԱȽ������\n";

			Date d1(2012, 12, 3);
			Date d2(2012, 12, 2);
			Date d3(2012, 12, 3);

			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 > d2) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 < d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 <= d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 == d2) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 != d2) << endl;

			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 > d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d3) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 < d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 <= d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 == d3) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 != d3) << endl;

			wait_for_enter();
		}

	}

	if (1) {
		cout << "���濪ʼ��Time����в���\n\n";

		wait_for_enter();

		if (1) {
			cout << "���� + / - ��ʵ��\n";
			Time t1, t2;

			t1.set(13, 59, 59);
			t2.set(12, 0, 0);
			cout << "Ӧ���01:59:59    ʵ���ϣ�" << t1 + t2 << endl;

			t1.set(13, 59, 59);
			t2.set(12, 0, 0);
			cout << "Ӧ���01:59:59    ʵ���ϣ�" << t1 - t2 << endl;

			t1.set(0, 59, 59);
			t2.set(12, 0, 0);
			cout << "Ӧ���12:59:59    ʵ���ϣ�" << t1 + t2 << endl;

			t1.set(0, 59, 59);
			t2.set(12, 0, 0);
			cout << "Ӧ���12:59:59    ʵ���ϣ�" << t1 - t2 << endl;

			wait_for_enter();
		}
		if (1) {
			cout << "���� ++ / -- ��ʵ��";
			Time t1, t2;

			t1.set(23, 59, 59);
			t2 = ++t1;
			cout << "Ӧ���00:00:00    ʵ���ϣ�" << t2 << endl;

			t1.set(23, 59, 59);
			t2 = t1++;
			cout << "Ӧ���23:59:59    ʵ���ϣ�" << t2 << endl;

			t1.set(0, 0, 0);
			t2 = --t1;
			cout << "Ӧ���23:59:59    ʵ���ϣ�" << t2 << endl;

			t1.set(0, 0, 0);
			t2 = t1--;
			cout << "Ӧ���00:00:00    ʵ���ϣ�" << t2 << endl;

			wait_for_enter();
		}
		if (1) {
			cout << "���ԱȽ������\n";

			Time d1(12, 12, 3);
			Time d2(12, 12, 2);
			Time d3(12, 12, 3);

			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 > d2) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 < d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 <= d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 == d2) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 != d2) << endl;

			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 > d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d3) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 < d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 <= d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 == d3) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 != d3) << endl;

			wait_for_enter();
		}
	}

	if (1) {
		cout << "���濪ʼ��DateTime����в���\n\n";

		wait_for_enter();

		if (1) {
			cout << "���� ++ / -- ��ʵ��\n";
			DateTime dt1, dt2(2099, 12, 31, 23, 59, 59);

			dt1.set(2099, 12, 31, 23, 59, 59);
			dt2 = ++dt1;
			cout << "Ӧ���1900-01-01 00:00:00    ʵ���ϣ�" << dt2 << endl;

			dt1.set(2099, 12, 31, 23, 59, 59);
			dt2 = dt1++;
			cout << "Ӧ���2099-12-31 23:59:59    ʵ���ϣ�" << dt2 << endl;

			dt1.set(1900, 1, 1, 0, 0, 0);
			dt2 = --dt1;
			cout << "Ӧ���2099-12-31 23:59:59    ʵ���ϣ�" << dt2 << endl;

			dt1.set(1900, 1, 1, 0, 0, 0);
			dt2 = dt1--;
			cout << "Ӧ���1900-01-01 00:00:00    ʵ���ϣ�" << dt2 << endl;
		}

		if (1) {
			cout << "���ԱȽ������\n";

			DateTime d1(2001, 12, 23, 12, 12, 3);
			DateTime d2(2001, 12, 23, 12, 12, 2);
			DateTime d3(2001, 12, 23, 12, 12, 3);

			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 > d2) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 < d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 <= d2) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 == d2) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 != d2) << endl;

			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 > d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d3) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 < d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 <= d3) << endl;
			cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 == d3) << endl;
			cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 != d3) << endl;

			wait_for_enter();
		}
	}
	return 0;
}