/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

const double eps = 1e-5;

double Cal(double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}

int main()
{
	int N;
	double x[10] = { 0 }, y[10] = { 0 };
	cout << "请输入多边形的顶点数量(4-7)\n";
	cin >> N;
	while (cin.fail() || N < 4 || N > 7) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "请输入多边形的顶点数量(4-7)\n";
		cin >> N;
	}
	cout << "请按顺时针/逆时针方向输入" << N << "个顶点的x，y坐标：\n";
	for (int i = 1; i <= N; ++i) {
		cout << "请输入第" << i << "个顶点的坐标：\n";
		cin >> x[i] >> y[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(0x3f3f3f3f, '\n');
			cout << "请输入第" << i << "个顶点的坐标：\n";
			cin >> x[i] >> y[i];
		}
	}
	if (Cal(x[N] - x[N - 1], y[N] - y[N - 1], x[1] - x[N], y[1] - y[N]) < eps) {
		cout << "不是凸" << N << "边形\n";
		return 0;
	}
	bool tg = (Cal(x[N]-x[N-1], y[N]-y[N-1], x[1]-x[N], y[1]-y[N]) > 0.0);
	if (tg != (Cal(x[1] - x[N], y[1] - y[N], x[2] - x[1], y[2] - y[1]) > 0.0)) {
		cout << "不是凸" << N << "边形\n";
		return 0;
	}
	for (int i = 2; i < N; ++i) {
		if (tg != (Cal(x[i] - x[i-1], y[i] - y[i-1], x[i+1] - x[i], y[i+1] - y[i]) > 0.0) || Cal(x[i] - x[i - 1], y[i] - y[i - 1], x[i + 1] - x[i], y[i + 1] - y[i]) < eps) {
			cout << "不是凸" << N << "边形\n";
			return 0;
		}
	}
	double S = 0.0;
	for (int i = 3; i <= N; ++i) 
		S += Cal(x[i] - x[1], y[i] - y[1], x[i - 1] - x[1], y[i - 1] - y[1]) / 2.0;
	cout << "凸" << N << "边形的面积=" << S << '\n';
	return 0;
}