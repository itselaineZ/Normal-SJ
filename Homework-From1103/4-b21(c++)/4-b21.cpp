/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

const double eps = 0.00001;

double dabs(double x)
{
	return x < 0.0 ? -x : x;
}

double Cal(double a, double b, char op) 
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return  a * b;
	if (op == '/') {
		if (b == 0)
			return 0;
		return a / b;
	}
	return 0.0;
}

int Set_order(char op1, char op2, char op3, int a, int b, int c, int d) 
{
	double x;
	bool tg = 0;
	x = Cal(Cal(Cal(a * 1.0, b * 1.0, op1), c * 1.0, op2), d * 1.0, op3);//123
	if (dabs(x - 24) < eps) {
		cout << "((" << a << op1 << b << ')' << op2 << c << ')' << op3 << d << "=24\n";
		tg = 1;
	}
	x = Cal(Cal(a * 1.0, Cal(b * 1.0, c * 1.0, op2), op1), d * 1.0, op3);//213
	if (dabs(x - 24) < eps) {
		cout << '(' << a << op1 << '(' << b << op2 << c << "))" << op3 << d << "=24\n";
		tg = 1;
	}
	x = Cal(a * 1.0, Cal(b * 1.0, Cal(c * 1.0, d * 1.0, op3), op2), op1);//321
	if (dabs(x - 24) < eps) {
		cout << a << op1 << '(' << b << op2 << '(' << c << op3 << d << "))=24\n";
		tg = 1;
	}
	x = Cal(a * 1.0, Cal(Cal(b * 1.0, c * 1.0, op2), d * 1.0, op3), op1);//231
	if (dabs(x - 24) < eps) {
		cout << a << op1 << "((" << b << op2 << c << ')' << op3 << d << ")=24\n";
		tg = 1;
	}
	x = Cal(Cal(a, b, op1), Cal(c, d, op3), op2);//132
	if (dabs(x - 24) < eps) {
		cout << '(' << a << op1 << b << ')' << op2 << '(' << c << op3 << d << ")=24\n";
		tg = 1;
	}
	return tg;
}

bool Dfs(char op1, char op2, char op3, int a, int b, int c, int d)
{
	int flg = 0;
	if (op1 && op2 && op3) {
		flg = Set_order(op1, op2, op3, a, b, c, d) || flg;
		return flg;
	}
	if (!op1) {
		flg = Dfs('+', op2, op3, a, b, c, d) || flg;
		flg = Dfs('-', op2, op3, a, b, c, d) || flg;
		flg = Dfs('*', op2, op3, a, b, c, d) || flg;
		flg = Dfs('/', op2, op3, a, b, c, d) || flg;
	}
	else if (!op2) {
		flg = Dfs(op1, '+', op3, a, b, c, d) || flg;
		flg = Dfs(op1, '-', op3, a, b, c, d) || flg;
		flg = Dfs(op1, '*', op3, a, b, c, d) || flg;
		flg = Dfs(op1, '/', op3, a, b, c, d) || flg;
	}
	else {
		flg = Dfs(op1, op2, '+', a, b, c, d) || flg;
		flg = Dfs(op1, op2, '-', a, b, c, d) || flg;
		flg = Dfs(op1, op2, '*', a, b, c, d) || flg;
		flg = Dfs(op1, op2, '/', a, b, c, d) || flg;
	}
	return flg;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int min(int a, int b, int c, int d)
{
	return min(min(min(a, b), c), d);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c, int d)
{
	return max(max(max(a, b), c), d);
}

int get_id(int a, int b, int c, int d)
{
	return a * 1000000 + b * 10000 + c * 100 + d;
}

int main()
{
	int x1, x2, x3, x4;
	cout << "请输入四个（1-10）之间的整数 :\n";
	cin >> x1 >> x2 >> x3 >> x4;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(0x3f3f3f, '\n');
		cout << "请输入四个（1-10）之间的整数 :\n";
		cin >> x1 >> x2 >> x3 >> x4;
	}
	bool flg = Dfs(0, 0, 0, x1, x2, x3, x4);
	int ID = get_id(x1, x2, x3, x4);
	if (!flg)
		cout << "无解\n";
	int a, b, c, d;
	a = min(x1, x2, x3, x4);
	d = max(x1, x2, x3, x4);
	if (x1 == a) {
		if (x2 == d)
			b = x3, c = x4;
		else if (x3 == d)
			b = x2, c = x4;
		else
			b = x2, c = x3;
	}
	else if (x2 == a) {
		if (x1 == d)
			b = x3, c = x4;
		else if (x3 == d)
			b = x1, c = x4;
		else
			b = x1, c = x3;
	}
	else if (x3 == a) {
		if (x1 == d)
			b = x2, c = x4;
		else if (x2 == d)
			b = x1, c = x4;
		else
			b = x1, c = x2;
	}
	else {
		if (x1 == d)
			b = x3, c = x2;
		else if (x2 == d)
			b = x1, c = x3;
		else
			b = x1, c = x2;
	}
	if (b > c)
		swap(b, c);
	if (a != b && b != c && c != d) {
		if(get_id(a, b, c, d) != ID)
			flg = Dfs(0, 0, 0, a, b, c, d) || flg;
		if(get_id(a, b, d, c) != ID)
			flg = Dfs(0, 0, 0, a, b, d, c) || flg;
		if(get_id(a, c, b, d) != ID)
			flg = Dfs(0, 0, 0, a, c, b, d) || flg;
		if (get_id(a, c, d, b) != ID)
			flg = Dfs(0, 0, 0, a, c, d, b) || flg;
		if (get_id(a, d, b, c) != ID)
			flg = Dfs(0, 0, 0, a, d, b, c) || flg;
		if (get_id(a, d, c, b) != ID)
			flg = Dfs(0, 0, 0, a, d, c, b) || flg;
		if (get_id(b, a, c, d) != ID)
			flg = Dfs(0, 0, 0, b, a, c, d) || flg;
		if (get_id(b, a, d, c) != ID)
			flg = Dfs(0, 0, 0, b, a, d, c) || flg;
		if (get_id(b, c, a, d) != ID)
			flg = Dfs(0, 0, 0, b, c, a, d) || flg;
		if (get_id(b, c, d, a) != ID)
			flg = Dfs(0, 0, 0, b, c, d, a) || flg;
		if (get_id(b, d, a, c) != ID)
			flg = Dfs(0, 0, 0, b, d, a, c) || flg;
		if (get_id(b, d, c, a) != ID)
			flg = Dfs(0, 0, 0, b, d, c, a) || flg;
		if (get_id(c, a, b, d) != ID)
			flg = Dfs(0, 0, 0, c, a, b, d) || flg;
		if (get_id(c, a, d, b) != ID)
			flg = Dfs(0, 0, 0, c, a, d, b) || flg;
		if (get_id(c, b, a, d) != ID)
			flg = Dfs(0, 0, 0, c, b, a, d) || flg;
		if (get_id(c, b, d, a) != ID)
			flg = Dfs(0, 0, 0, c, b, d, a) || flg;
		if (get_id(c, d, a, b) != ID)
			flg = Dfs(0, 0, 0, c, d, a, b) || flg;
		if (get_id(c, d, b, a) != ID)
			flg = Dfs(0, 0, 0, c, d, b, a) || flg;
		if (get_id(d, a, b, c) != ID)
			flg = Dfs(0, 0, 0, d, a, b, c) || flg;
		if (get_id(d, a, c, b) != ID)
			flg = Dfs(0, 0, 0, d, a, c, b) || flg;
		if (get_id(d, b, a, c) != ID)
			flg = Dfs(0, 0, 0, d, b, a, c) || flg;
		if (get_id(d, b, c, a) != ID)
			flg = Dfs(0, 0, 0, d, b, c, a) || flg;
		if (get_id(d, c, a, b) != ID)
			flg = Dfs(0, 0, 0, d, c, a, b) || flg;
		if (get_id(d, c, b, a) != ID)
			flg = Dfs(0, 0, 0, d, c, b, a) || flg;
	}
	else {
		if (a == b) {
			if (b == c) {
				if (c == d)
					;
				else {
					if (get_id(a, b, c, d) != ID)
						flg = Dfs(0, 0, 0, a, b, c, d) || flg;
					if (get_id(a, b, d, c) != ID)
						flg = Dfs(0, 0, 0, a, b, d, c) || flg;
				}
			}
			else {
				if (c != d) {
					if (get_id(a, b, c, d) != ID)
						flg = Dfs(0, 0, 0, a, b, c, d) || flg;
					if (get_id(a, b, d, c) != ID)
						flg = Dfs(0, 0, 0, a, b, d, c) || flg;
					if (get_id(a, c, b, d) != ID)
						flg = Dfs(0, 0, 0, a, c, b, d) || flg;
					if (get_id(a, c, d, b) != ID)
						flg = Dfs(0, 0, 0, a, c, d, b) || flg;
					if (get_id(a, d, b, c) != ID)
						flg = Dfs(0, 0, 0, a, d, b, c) || flg;
					if (get_id(a, d, c, b) != ID)
						flg = Dfs(0, 0, 0, a, d, c, b) || flg;
					if (get_id(c, a, b, d) != ID)
						flg = Dfs(0, 0, 0, c, a, b, d) || flg;
					if (get_id(c, a, d, b) != ID)
						flg = Dfs(0, 0, 0, c, a, d, b) || flg;
					if (get_id(c, d, a, b) != ID)
						flg = Dfs(0, 0, 0, c, d, a, b) || flg;
					if (get_id(d, a, b, c) != ID)
						flg = Dfs(0, 0, 0, d, a, b, c) || flg;
					if (get_id(d, a, c, b) != ID)
						flg = Dfs(0, 0, 0, d, a, c, b) || flg;
					if (get_id(d, c, a, b) != ID)
						flg = Dfs(0, 0, 0, d, c, a, b) || flg;
				}//12
				else {
					if (get_id(a, b, c, d) != ID)
						flg = Dfs(0, 0, 0, a, b, c, d) || flg;
					if (get_id(a, c, b, d) != ID)
						flg = Dfs(0, 0, 0, a, c, b, d) || flg;
					if (get_id(a, c, d, b) != ID)
						flg = Dfs(0, 0, 0, a, c, d, b) || flg;
					if (get_id(c, a, b, d) != ID)
						flg = Dfs(0, 0, 0, c, a, b, d) || flg;
					if (get_id(c, a, d, b) != ID)
						flg = Dfs(0, 0, 0, c, a, d, b) || flg;
					if (get_id(c, d, a, b) != ID)
						flg = Dfs(0, 0, 0, c, d, a, b) || flg;
				}
			}
		}
		else {
			if (b == c) {
				if (c == d) {
					if (get_id(a, b, c, d) != ID)
						flg = Dfs(0, 0, 0, a, b, c, d) || flg;
					if (get_id(b, a, c, d) != ID)
						flg = Dfs(0, 0, 0, b, a, c, d) || flg;
				}
				else {
					if (get_id(a, b, c, d) != ID)
						flg = Dfs(0, 0, 0, a, b, c, d) || flg;
					if (get_id(a, b, d, c) != ID)
						flg = Dfs(0, 0, 0, a, b, d, c) || flg;
					if (get_id(a, d, b, c) != ID)
						flg = Dfs(0, 0, 0, a, d, b, c) || flg;
					if (get_id(b, a, c, d) != ID)
						flg = Dfs(0, 0, 0, b, a, c, d) || flg;
					if (get_id(b, a, d, c) != ID)
						flg = Dfs(0, 0, 0, b, a, d, c) || flg;
					if (get_id(b, c, a, d) != ID)
						flg = Dfs(0, 0, 0, b, c, a, d) || flg;
					if (get_id(b, c, d, a) != ID)
						flg = Dfs(0, 0, 0, b, c, d, a) || flg;
					if (get_id(b, d, a, c) != ID)
						flg = Dfs(0, 0, 0, b, d, a, c) || flg;
					if (get_id(b, d, c, a) != ID)
						flg = Dfs(0, 0, 0, b, d, c, a) || flg;
					if (get_id(d, a, b, c) != ID)
						flg = Dfs(0, 0, 0, d, a, b, c) || flg;
					if (get_id(d, b, a, c) != ID)
						flg = Dfs(0, 0, 0, d, b, a, c) || flg;
					if (get_id(d, b, c, a) != ID)
						flg = Dfs(0, 0, 0, d, b, c, a) || flg;
				}
			}
			else {
				if (get_id(a, b, c, d) != ID)
					flg = Dfs(0, 0, 0, a, b, c, d) || flg;
				if (get_id(a, c, b, d) != ID)
					flg = Dfs(0, 0, 0, a, c, b, d) || flg;
				if (get_id(a, c, d, b) != ID)
					flg = Dfs(0, 0, 0, a, c, d, b) || flg;
				if (get_id(b, a, c, d) != ID)
					flg = Dfs(0, 0, 0, b, a, c, d) || flg;
				if (get_id(b, c, a, d) != ID)
					flg = Dfs(0, 0, 0, b, c, a, d) || flg;
				if (get_id(b, c, d, a) != ID)
					flg = Dfs(0, 0, 0, b, c, d, a) || flg;
				if (get_id(c, a, b, d) != ID)
					flg = Dfs(0, 0, 0, c, a, b, d) || flg;
				if (get_id(c, a, d, b) != ID)
					flg = Dfs(0, 0, 0, c, a, d, b) || flg;
				if (get_id(c, b, a, d) != ID)
					flg = Dfs(0, 0, 0, c, b, a, d) || flg;
				if (get_id(c, b, d, a) != ID)
					flg = Dfs(0, 0, 0, c, b, d, a) || flg;
				if (get_id(c, d, a, b) != ID)
					flg = Dfs(0, 0, 0, c, d, a, b) || flg;
				if (get_id(c, d, b, a) != ID)
					flg = Dfs(0, 0, 0, c, d, b, a) || flg;
			}//12
		}
	}
	return 0;
}