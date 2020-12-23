/* 1952339 信08 张馨月 */
#include <iostream>
using namespace std;

const double eps = 0.0001;
const int hm = 100000000;
const int mm = 10000000;
const int ml = 1000000;
const int lakh = 100000;
const int tth = 10000;
const int th = 1000;
/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	cout << "请输入[0-100亿)之间的数字:\n";
	double x;
	cin >> x;
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
			daxie(b1/10, 0);
			cout << "拾";
			b1 %= 10;
		}
		daxie(b1, 0);
		cout << "亿";
		fst = 1;
	}
	if (b2) {
		daxie(b2, 0);
		cout << "仟";
		fst = 1;
	}
	else if (!sum) {
		if (!b1)
			daxie(0, 1);
		cout << "圆整\n";
		return 0;
	}
	else if (fst && wan)
		wanflg = 1;
	sum -= b3;
	wan -= b3;
	if (b3) {
		if (wanflg && fst)
			wanflg = 0, daxie(0, 1);
		daxie(b3, 0);
		cout << "佰";
		fst = 1;
	}
	else if (!sum) {
		cout << "万圆整\n";
		return 0;
	}
	else if (wan && fst)
		wanflg = 1;
	sum -= b4;
	wan -= b4;
	if (b4) {
		if (wanflg && fst)
			wanflg = 0, daxie(0, 1);
		daxie(b4, 0);
		cout << "拾";
		fst = 1;
	}
	else if (!sum) {
		cout << "万圆整\n";
		return 0;
	}
	else if (wan)
		wanflg = 1;
	sum -= b5;
	if (b5) {
		if (wanflg && fst)
			wanflg = 0, daxie(0, 1);
		daxie(b5, 0);
		fst = 1;
	}
	if (b2 + b3 + b4 + b5)
		cout << "万";
	if (ge + b01 + b02 == 0) {
		if (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9 == 0)
			daxie(0, 1);
		cout << "圆整\n";
		return 0;
	}
	sum -= b6;
	if (b6) {
		daxie(b6, 0);
		cout << "仟";
		fst = 1;
	}
	else if (!sum) {
		cout << "圆整\n";
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b7;
	ge -= b7;
	if (b7) {
		if (geflg && fst)
			geflg = 0, daxie(0, 1);
		daxie(b7, 0);
		cout << "佰";
		fst = 1;
	}
	else if (!sum) {
		cout << "圆整\n";
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b8;
	ge -= b8;
	if (b8) {
		if (geflg && fst)
			geflg = 0, daxie(0, 1);
		daxie(b8, 0);
		cout << "拾";
		fst = 1;
	}
	else if (!sum) {
		cout << "圆整\n";
		return 0;
	}
	else if (ge && fst)
		geflg = 1;
	sum -= b9;
	if (b9) {
		if (geflg && fst)
			geflg = 0, daxie(0, 1);
		daxie(b9, 0);
		fst = 1;
	}
	if (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9)
		cout << "圆";
	if (!sum) {
		cout << "整\n";
		return 0;
	}
	if (b01 && b02) {
		daxie(b01, 0);
		cout << "角";
		daxie(b02, 0);
		cout << "分\n";
	}
	else if (b01) {
		daxie(b01, 0);
		cout << "角整\n";
	}
	else {
		if(fst)
			daxie(0, 1);
		daxie(b02, 0);
		cout << "分\n";
	}
	return 0;
}
