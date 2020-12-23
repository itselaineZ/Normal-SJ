/* 1952339 ��08 ��ܰ�� */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <cstdio>
#include <ctime>
#include <conio.h>	//��getch����˲���Ҫ֧��Linux
#include <string.h>	//Dev/CB��strlen��Ҫ
using namespace std;

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */



/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
	struct tm* tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&input_time);	//localtimeΪϵͳ����

	/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	cout << tt->tm_year + 1900 << '-' << tt->tm_mon + 1 << '-' << tt->tm_mday << ' ' << tt->tm_hour << ':' << tt->tm_min << ':' << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	cout << tp->tj_year << '-' << tp->tj_month << '-' << tp->tj_day << ' ' << tp->tj_hour << ':' << tp->tj_minute << ':' << tp->tj_second << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��

	/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */

	result.tj_year = 1970;
	result.tj_month = 0;
	result.tj_day = 0;
	result.tj_hour = result.tj_minute = result.tj_second = 0;

	const int yrs_4 = (365 * 4 + 1) * 24 * 60 * 60, yrs_1 = 365 * 24 * 60 * 60;
	const int dys = 24 * 60 * 60, hrs = 60 * 60, mts = 60, MTH = 12;
	int mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	input_time += hrs * 8;

	result.tj_year += input_time / yrs_4 * 4;
	input_time %= yrs_4;

	if (input_time >= yrs_1*3+dys){
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
	
	for(int i = 1; i <= MTH && input_time >= mth[i] * dys; ++ i){
		input_time -= mth[i]*dys;
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

	/* ʵ�ֹ��̽��� */

	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int test_time[] = { 1, 123456789, 349823021, 987654321, 1202990407, 1216468807, 1250312143, 1272636353, 1326193524, 1336549496, 1392837128, 1625675376, 2052743737 };
	int i;
	struct tj_time* tp;

	for (i = 0; i < sizeof(test_time) / sizeof(int); i++) {
		cout << "����            ��" << test_time[i] << endl;
		cout << "ϵͳת���Ľ��  ��";
		system_time_output(test_time[i]);

		cout << "�Զ���ת���Ľ����";
		tp = tj_time_convert(test_time[i]);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "��ǰϵͳʱ��    ��" << t << endl;
		cout << "ϵͳת���Ľ��  ��";
		system_time_output(t);

		cout << "�Զ���ת���Ľ����";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}
