/* 1952339 ��08 ��ܰ�� */
#include <iostream>
#include <cstdio>
using namespace std;

#define  N  10	/* �������ת��10������ */

int main()
{
	char str[80], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���\n";
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
	cout << "����" << pnum-a+1 << "������\n";
	cout << *a;
	for (pa = a+1; pa <= pnum; ++pa)
		cout << ' ' << *pa;
	puts("");
	return 0;
}
