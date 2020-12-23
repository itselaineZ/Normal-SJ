/* 1952339 信08 张馨月 */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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
	cout << endl << "按回车键继续";
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
		cout << "\n现在测试assign函数的实现\n";
		cout << a << endl;
		a.assign("landslaff");
		cout << "应输出：landslaff  实际上为：" << a << endl;
		a.assign("w");
		cout << "应输出：w          实际上为：" << a << endl;
		a.assign(b);
		cout << "应输出：apap       实际上为：" << a << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "hahahaha";
		TStringAdv b = "apap";
		cout << "\n现在测试append函数的实现\n";
		cout << a << endl;
		a.append("landslaff");
		cout << "应输出：hahahahalandslaff  实际上为：" << a << endl;
		a = "hahahaha";
		a.append("w");
		cout << "应输出：hahahahaw          实际上为：" << a << endl;
		a = "hahahaha";
		a.append(b);
		cout << "应输出：hahahahaapap       实际上为：" << a << endl;
		wait_for_enter();
	}


	if (1) {
		TStringAdv a = "hahahaha";
		TStringAdv b = "apap";
		cout << "\n现在测试insert函数的实现\n";
		cout << a << endl;
		a.insert("landslaff", 1);
		cout << "应输出：landslaffhahahaha  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert("landslaff", 9);
		cout << "应输出：hahahahalandslaff  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert("landslaff", 3);
		cout << "应输出：halandslaffhahaha  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert("k", 1);
		cout << "应输出：khahahaha  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert("k", 9);
		cout << "应输出：hahahahak  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert("k", 3);
		cout << "应输出：hakhahaha  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert(b, 1);
		cout << "应输出：apaphahahaha  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert(b, 9);
		cout << "应输出：hahahahaapap  实际上为：" << a << endl;
		a = "hahahaha";
		a.insert(b, 3);
		cout << "应输出：haapaphahaha  实际上为：" << a << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "hahahaha";
		TStringAdv b = "aha";
		cout << "\n现在测试erase函数的实现\n";
		cout << a << endl;
		a.erase("ah");
		cout << "应输出：hahaha      实际上为：" << a << endl;
		a = "hahahaha";
		a.erase("a");
		cout << "应输出：hhahaha     实际上为：" << a << endl;
		a = "hahahaha";
		a.erase(b);
		cout << "应输出：hhaha       实际上为：" << a << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "someonelikeyou";
		cout << "\n现在测试substr函数的实现\n";
		cout << a << endl;
		cout << "应输出：some      实际上为：" << a.substr(1, 4) << endl;
		cout << "应输出：likeyou   实际上为：" << a.substr(8) << endl;
		cout << "应输出：<NULL>    实际上为：" << a.substr(13, 5) << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv a = "someonelikeyou";
		cout << "\n现在测试at函数的实现\n";
		cout << a << endl;
		cout << "应输出：s      实际上为：" << a.at(0) << endl;
		a.at(0) = 'k';
		cout << "应输出：k      实际上为：" << a.at(0) << endl;
		wait_for_enter();
	}

#if !(defined(__linux) || defined(__linux__))
	system("pause"); //Linux不需要
#endif

	return 0;
}
