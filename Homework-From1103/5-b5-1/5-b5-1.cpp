/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<limits>
#include<iomanip>
using namespace std;

const int Maxn = 10 + 5;

int pa, pb, pc;
int stk_A[Maxn], stk_B[Maxn], stk_C[Maxn];

void cout_table(char st_pos, char ed_pos, int stp)
{
	if (st_pos == 'A')
		cout << "第" << setw(4) << setiosflags(ios::right) << stp << " 步" << '(' << setw(2) << stk_A[pa] << "): " << st_pos << "-->" << ed_pos << ' ';
	else if (st_pos == 'B')
		cout << "第" << setw(4) << setiosflags(ios::right) << stp << " 步" << '(' << setw(2) << stk_B[pb] << "): " << st_pos << "-->" << ed_pos << ' ';
	else
		cout << "第" << setw(4) << setiosflags(ios::right) << stp << " 步" << '(' << setw(2) << stk_C[pc] << "): " << st_pos << "-->" << ed_pos << ' ';
	cout << "A:";
	for (int i = 0; i < pa; ++i)
		cout << setw(2) << stk_A[i];
	for (int i = 21 - 2 * pa; i; --i)
		cout << ' ';
	cout << "B:";
	for (int i = 0; i < pb; ++i)
		cout << setw(2) << stk_B[i];
	for (int i = 21 - 2 * pb; i; --i)
		cout << ' ';
	cout << "C:";
	for (int i = 0; i < pc; ++i)
		cout << setw(2) << stk_C[i];
	for (int i = 20 - 2 * pc; i; --i)
		cout << ' ';
	cout << '\n';
}

void stk_move(char st_pos, char ed_pos)
{
	if (st_pos == 'A') {
		if (ed_pos == 'B')
			stk_B[pb++] = stk_A[--pa];
		else stk_C[pc++] = stk_A[--pa];
	}
	else if (st_pos == 'B') {
		if (ed_pos == 'A')
			stk_A[pa++] = stk_B[--pb];
		else stk_C[pc++] = stk_B[--pb];
	}
	else {
		if (ed_pos == 'B')
			stk_B[pb++] = stk_C[--pc];
		else stk_A[pa++] = stk_C[--pc];
	}
}

int Hano(int n, char now_pos, char aim_pos, int stp)
{
	if (n == 0) {
		if (stp == -1)
			return 0;
		else
			return stp;
	}
	char spare_pos = 'A' + 'B' + 'C' - now_pos - aim_pos;
	stp = Hano(n - 1, now_pos, spare_pos, stp);
	++stp;
	stk_move(now_pos, aim_pos);
	cout_table(now_pos, aim_pos, stp);
	stp = Hano(n - 1, spare_pos, aim_pos, stp);
	return stp;
}

int main()
{
	cout << "请输入汉诺塔的层数(1-10)：\n";
	int N;
	cin >> N;
	while (cin.fail() || N < 1 || N > 64) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入\n";
		cin >> N;
	}
	cout << "请输入起始柱(A-C)：\n";
	char bgn, ed;
	cin >> bgn;
	while (cin.fail() || !((bgn >= 'a' && bgn <= 'c') || (bgn >= 'A' && bgn <= 'C'))) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入\n";
		cin >> bgn;
	}
	cout << "请输入目标柱(A-C)：\n";
	cin >> ed;
	while (cin.fail() || !((ed >= 'a' && ed <= 'c') || (ed >= 'A' && ed <= 'C')) || ed == bgn) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入非法，请重新输入\n";
		cin >> ed;
	}
	if (bgn > 'C')
		bgn -= 'a' - 'A';
	if (ed > 'C')
		ed -= 'a' - 'A';
	for (int i = N; i; --i) {
		if (bgn == 'A')
			stk_A[pa++] = i;
		else if (bgn == 'B')
			stk_B[pb++] = i;
		else
			stk_C[pc++] = i;
	}
	cout << setw(21) << setiosflags(ios::left) << "初始:";
	if (bgn == 'A') {
		cout << "A:";
		for (int i = N; i; --i)
			cout << setw(2) << setiosflags(ios::right) << i;
		for (int i = 21 - 2 * N; i; --i)
			cout << ' ';
		cout << "B:";
		for (int i = 1; i <= 21; ++i)
			cout << ' ';
		cout << "C:";
		for (int i = 1; i <= 20; ++i)
			cout << ' ';
	}
	else if (bgn == 'B') {
		cout << "A:";
		for (int i = 1; i <= 21; ++i)
			cout << ' ';
		cout << "B:";
		for (int i = N; i; --i)
			cout << setw(2) << setiosflags(ios::right) << i;
		for (int i = 21 - 2 * N; i; --i)
			cout << ' ';
		cout << "C:";
		for (int i = 1; i <= 20; ++i)
			cout << ' ';
	}
	else {
		cout << "A:";
		for (int i = 1; i <= 21; ++i)
			cout << ' ';
		cout << "B:";
		for (int i = 1; i <= 21; ++i)
			cout << ' ';
		cout << "C:";
		for (int i = N; i; --i)
			cout << setw(2) << setiosflags(ios::right) << i;
		for (int i = 20 - 2 * N; i; --i)
			cout << ' ';
	}
	cout << '\n';
	Hano(N, bgn, ed, -1);
	return 0;
}
