/* 1952339 信08 张馨月 */
#include <iostream>
#include <cstdio>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

int main()
{
	char str[80], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串\n";
	p = str;
	pnum = a;
	*p = getchar();
	while (*p != '\n') {
		is_num = 0;
		while (*p >= '0' && *p <= '9') {
			*pnum = *pnum * 10 + *p - '0';
			*p = getchar();
			is_num = 1;
		}
		if (*p == '\n')
			break;
		while (((*p = getchar()) < '0' || *p > '9') && *p != '\n')
			;
		if(*p != '\n' && is_num)
			++pnum;
	}
	cout << "共有" << pnum-a+1 << "个整数\n";
	cout << *a;
	for (pa = a+1; pa <= pnum; ++pa)
		cout << ' ' << *pa;
	puts("");
	return 0;
}
