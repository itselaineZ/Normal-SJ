/* 1952339 ��08 ��ܰ�� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "11-b1-TString.h"
#include "11-b1-TStringAdv.h"
using namespace std;

#if defined(__linux) || defined(__linux__)
#include <sys/time.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
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
		TStringAdv a = "hahahaha";
		TStringAdv b = "apap";
		cout << "\n���ڲ���assign������ʵ��\n";
		cout << a << endl;
		a.assign("landslaff");
		cout << "Ӧ�����landslaff  ʵ����Ϊ��" << a << endl;
		a.assign("w");
		cout << "Ӧ�����w          ʵ����Ϊ��" << a << endl;
		a.assign(b);
		cout << "Ӧ�����apap       ʵ����Ϊ��" << a << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "hahahaha";
		TStringAdv b = "apap";
		cout << "\n���ڲ���append������ʵ��\n";
		cout << a << endl;
		a.append("landslaff");
		cout << "Ӧ�����hahahahalandslaff  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.append("w");
		cout << "Ӧ�����hahahahaw          ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.append(b);
		cout << "Ӧ�����hahahahaapap       ʵ����Ϊ��" << a << endl;
		wait_for_enter();
	}


	if (1) {
		TStringAdv a = "hahahaha";
		TStringAdv b = "apap";
		cout << "\n���ڲ���insert������ʵ��\n";
		cout << a << endl;
		a.insert("landslaff", 1);
		cout << "Ӧ�����landslaffhahahaha  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert("landslaff", 9);
		cout << "Ӧ�����hahahahalandslaff  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert("landslaff", 3);
		cout << "Ӧ�����halandslaffhahaha  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert("k", 1);
		cout << "Ӧ�����khahahaha  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert("k", 9);
		cout << "Ӧ�����hahahahak  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert("k", 3);
		cout << "Ӧ�����hakhahaha  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert(b, 1);
		cout << "Ӧ�����apaphahahaha  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert(b, 9);
		cout << "Ӧ�����hahahahaapap  ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.insert(b, 3);
		cout << "Ӧ�����haapaphahaha  ʵ����Ϊ��" << a << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "hahahaha";
		TStringAdv b = "aha";
		cout << "\n���ڲ���erase������ʵ��\n";
		cout << a << endl;
		a.erase("ah");
		cout << "Ӧ�����hahaha      ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.erase("a");
		cout << "Ӧ�����hhahaha     ʵ����Ϊ��" << a << endl;
		a = "hahahaha";
		a.erase(b);
		cout << "Ӧ�����hhaha       ʵ����Ϊ��" << a << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "someonelikeyou";
		cout << "\n���ڲ���substr������ʵ��\n";
		cout << a << endl;
		cout << "Ӧ�����some      ʵ����Ϊ��" << a.substr(1, 4) << endl;
		cout << "Ӧ�����likeyou   ʵ����Ϊ��" << a.substr(8) << endl;
		cout << "Ӧ�����<NULL>    ʵ����Ϊ��" << a.substr(13, 5) << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "someonelikeyou";
		cout << "\n���ڲ���at������ʵ��\n";
		cout << a << endl;
		cout << "Ӧ�����s      ʵ����Ϊ��" << a.at(0) << endl;
		a.at(0) = 'k';
		cout << "Ӧ�����k      ʵ����Ϊ��" << a.at(0) << endl;
		wait_for_enter();
	}

#if !(defined(__linux) || defined(__linux__))
	system("pause"); //Linux����Ҫ
#endif

	return 0;
}
