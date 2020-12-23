/* 1952339 信08 张馨月 */
#include <iostream>
#include <string>
using namespace std;

const double eps = 0.0001;
const int hm = 100000000;
const int mm = 10000000;
const int ml = 1000000;
const int lakh = 100000;
const int tth = 10000;
const int th = 1000;
const char chistr[] = "零壹贰叁肆伍陆柒捌玖";

string result;

int main()
{
	cout << "请输入[0-100亿)之间的数字:\n";
	double x;
	cin >> x;
	while (cin.fail() || x < 0.0) {
		cin.clear();
		cin.ignore(0x3f3f3f3f, '\n');
		cout << "输入非法，请重新输入!\n";
		cin >> x;
	}
	cout << "大写结果是：\n";
	int b1, b2, b3, b4, b5, b6, b7, b8, b9, b01, b02;
	b1 = int(x / hm), x -= 1.0 * b1 * hm;
	b2 = int(x / mm), x -= 1.0 * b2 * mm;
	b3 = int(x / ml), x -= 1.0 * b3 * ml;
	b4 = int(x / lakh), x -= 1.0 * b4 * lakh;
	b5 = int(x / tth), x -= 1.0 * b5 * tth;
	b6 = int(x / th), x -= 1.0 * b6 * th;
	b7 = int(x / 100), x -= 1.0 * b7 * 100;
	b8 = int(x / 10), x -= 1.0 * b8 * 10;
	b9 = int(x), x -= b9;
	b01 = int((x + eps) * 10), x -= b01 * 0.1;
	b02 = int((x + eps) * 100);
	int sum = b3 + b4 + b5 + b6 + b7 + b8 + b9 + b01 + b02;
	int wan = b3 + b4 + b5, ge = b7 + b8 + b9;
	bool wanflg = 0, geflg = 0, fst = 0;
	if (b1) {
		if (b1 > 9) {
			result.append(&chistr[b1/10*2], 2);
			result += "拾";
			b1 %= 10;
		}
		result.append(&chistr[b1*2], 2);
		result += "亿";
		fst = 1;
	}
	if (b2) {
		result.append(&chistr[b2], 2);
		result += "仟";
		fst = 1;
	}
	else if (!sum) {
		if (!b1)
			result.append(&chistr[0], 2);
		result += "圆整";
		cout << result << endl;
		return 0;
	}
	else if (fst && wan)
		wanflg = 1;
	sum -= b3;
	wan -= b3;
	if (b3) {
		if (wanflg && fst)
			wanflg = 0, result.append(&chistr[0], 2);
		result.append(&chistr[b3*2], 2);
		result += "佰";
		fst = 1;
	}
	else if (!sum) {
		result += "万圆整";
		cout << result << endl;
		return 0;
	}
	else if (wan && fst)
		wanflg = 1;
	sum -= b4;
	wan -= b4;
	if (b4) {
		if (wanflg && fst)
			wanflg = 0, result.append(&chistr[0], 2);
		result.append(&chistr[b4*2], 2);
		result += "拾";
		fst = 1;
	}
	else if (!sum) {
		result += "万圆整";
		cout << result << endl;
		return 0;
	}
	else if (wan)
		wanflg = 1;
	sum -= b5;
	if (b5) {
		if (wanflg && fst)
			wanflg = 0, result.append(&chistr[0], 2);
		result.append(&chistr[b5*2], 2);
		fst = 1;
	}
	if (b2 + b3 + b4 + b5)
		result += "万";
	if (ge + b01 + b02 == 0) {
		if (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9 == 0)
			result.append(&chistr[0], 2);
		result += "圆整";
		cout << result << endl;
		return 0;
	}
	sum -= b6;
	if (b6) {
		result.append(&chistr[b6*2], 2);
		result += "仟";
		fst = 1;
	}
	else if (!sum) {
		result += "圆整";
		cout << result << endl;
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b7;
	ge -= b7;
	if (b7) {
		if (geflg && fst)
			geflg = 0, result.append(&chistr[0], 2);
		result.append(&chistr[b7*2], 2);
		result += "佰";
		fst = 1;
	}
	else if (!sum) {
		result += "圆整";
		cout << result << endl;
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b8;
	ge -= b8;
	if (b8) {
		if (geflg && fst)
			geflg = 0, result.append(&chistr[0], 2);
		result.append(&chistr[b8*2], 2);
		result += "拾";
		fst = 1;
	}
	else if (!sum) {
		result += "圆整";
		cout << result << endl;
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b9;
	if (b9) {
		if (geflg && fst)
			geflg = 0, result.append(&chistr[0], 2);
		result.append(&chistr[b9*2], 2);
		fst = 1;
	}
	if (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9)
		result += "圆";
	if (!sum) {
		result += "整";
		cout << result << endl;
		return 0;
	}
	if (b01 && b02) {
		result.append(&chistr[b01*2], 2);
		result += "角";
		result.append(&chistr[b02*2], 2);
		result += "分";
	}
	else if (b01) {
		result.append(&chistr[b01*2], 2);
		result += "角整";
	}
	else {
		if (fst)
			result.append(&chistr[0], 2);
		result.append(&chistr[b02], 2);
		result += "分";
	}
	cout << result << endl;
	return 0;
}
