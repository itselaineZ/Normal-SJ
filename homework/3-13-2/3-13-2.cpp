/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	cout << "请输入当月利润：" << endl;
	int x;
	cin >> x;
	cout << "应发奖金数：" << endl;
	int tg = x <= 100000;
	switch (tg) {
		case 1 :
			cout << (int)(0.1 * x) << endl;
			break;
		default: {
		    tg  = x <= 200000;
			switch (tg) {
				case 1:
					cout << (int)(10000 + 0.075 * (x - 100000.0)) << endl;
					break;
				default:{
				    tg = x <= 400000;
					switch (tg) {
						case 1:
							cout << (int)(17500 + 0.05 * (x - 200000.0)) << endl;
							break;
						default: {
						    tg = x <= 600000;
							switch (tg) {
								case 1:
									cout << (int)(27500 + 0.03 * (x - 400000.0)) << endl;
									break;
								default:{
								    tg = x <= 1000000;
									switch (tg) {
										case 1:
											cout << (int)(33500 + 0.015 * (x - 600000.0)) << endl;
											break;
										default:
											cout << (int)(33500 + 6000 + 0.01 * (x - 1000000.0)) << endl;
											break;
									}
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}
	return 0;
}
