/* 1952339 信08 张馨月 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* ------------------------------------------------------------------------------ */
/* ---- 允许按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环 ---- */
/* ------------------------------------------------------------------------------ */

void Print_alph(char bg_ch, char ed_ch,int delta) {
	if (bg_ch == ed_ch)
		return;
	putchar(bg_ch);
	return Print_alph(bg_ch+delta, ed_ch, delta);
}

void Print_spc(int l, int r) {
	if (l == r)
		return;
	putchar(32);
	return Print_spc(l+1, r);
}

void Print_0(char bg_ch, char ed_ch, int num) {
	int spc = ed_ch - bg_ch + 1 - num;
	Print_spc(1, spc);
	Print_alph(bg_ch+num-1, bg_ch, -1);
	Print_alph(bg_ch, bg_ch+num, 1);
	putchar(10);
	if (bg_ch + num == ed_ch)
		return ;
	return Print_0(bg_ch, ed_ch, num + 1);
}

void Print_1(char bg_ch, char ed_ch, int num) {
	int spc = ed_ch - bg_ch + 1 - num;
	Print_spc(1, spc);
	Print_alph(ed_ch-num, ed_ch, 1);
	Print_alph(ed_ch-2, ed_ch-num-1, -1);
	putchar(10);
	if (num == 1)
		return ;
	return Print_1(bg_ch, ed_ch, num - 1);
}

/***************************************************************************
  函数名称：
  功    能：正向或反向打印三角塔
  输入参数：order - 0 ：正三角形塔
			order - 1 ：倒三角形塔
  返 回 值：
  说    明：
***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* 按需实现，函数中不允许任何形式的循环 */
	if (!order)
		Print_0(start_ch, end_ch+1, 1);
	else
		Print_1(start_ch, end_ch+1, end_ch-start_ch+1);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	while (1) {
		cout << "请输入结束字符(A~Z)" << endl;
		end_ch = getchar();			//读缓冲区第一个字符
		while (getchar() != '\n')	//清空缓冲区剩余字符
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}
