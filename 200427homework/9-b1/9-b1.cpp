/* 1952339 ��08 ��ܰ�� */
#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
public:
	int calc_days();     //�����ǵ���ĵڼ���
	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������� */
	Days(int, int, int);
};

/* �˴��������Ա����������ʵ�� */

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


/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
