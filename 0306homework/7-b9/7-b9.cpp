/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;

struct KFC {
	char id;
	const char* name;
	double v;
};

struct SPECIAL {
	const char* id, * name;
	double v;
};

const struct KFC list[] = {
	{'A', "香辣鸡腿堡",        18.5},
	{'B', "劲脆鸡腿堡",        18.5},
	{'C', "新奥尔良烤鸡腿堡",  18.5},
	{'D', "鸡肉火腿帕尼尼",    14.0},
	{'E', "老北京鸡肉卷",      16.5},
	{'F', "香辣黄金鸡柳(4条)", 11.5},
	{'G', "吮指原味鸡(1块)",   11.5},
	{'H', "热辣香骨鸡(3块)",   11.5},
	{'I', "新奥尔良烤翅(2块)", 12.5},
	{'J', "劲爆鸡米花",        11.0},
	{'K', "香辣鸡翅(2块)",     11.5},
	{'L', "黄金鸡块(5块)",     11.0},
	{'M', "鲜蔬色拉",          13.0},
	{'N', "薯条(小)",          8.5},
	{'O', "薯条(中)",          11.5},
	{'P', "薯条(大)",          13.5},
	{'Q', "芙蓉蔬荟汤",        8.5},
	{'R', "红豆派",            6.5},
	{'S', "醇香土豆泥",        7.0},
	{'T', "香甜粟米棒",        8.5},
	{'U', "葡式蛋挞",          7.5},
	{'V', "百事可乐(小)",      7.0},
	{'W', "百事可乐(中)",      9.5},
	{'X', "百事可乐(大)",      11.5},
	{'Y', "九珍果汁饮料",      12.0},
	{'Z', "纯纯玉米饮",        11.0},
	{'\0', NULL,               0}
};

const struct SPECIAL special[] = {
	{"ANV", "香辣鸡腿堡工作日午餐",     22},
	{"ABCGGIIKKOUWWW", "超值全家桶", 100},
	{"KIIRRJUWW", "缤纷小吃桶",      65},
	{"JJ","劲爆鸡米花(2份小)",       9.5},
	{NULL, NULL, 0}
};

int find_p(char key)
{
	if (key > 'Z')
		key -= 'a' - 'A';
	for (int i = 0; list[i].id; ++i)
		if (list[i].id == key)
			return i;
	return -1;
}

int menu()
{
	system("mode con cols=120 lines=45");
	cout << "=============================================================\n";
	cout << "                      KFC 2020春季菜\n";
	cout << "=============================================================\n";
	int all_kinds = 0;
	for (int i = 0; ; ++i) {
		if (!list[i << 1].id) {
			all_kinds = i << 1;
			break;
		}
		putchar(32);
		cout << list[i<<1].id << ' ' << setw(20) << list[i<<1].name << setw(7) << list[i<<1].v;
		if (!list[i << 1 | 1].id) {
			all_kinds = i << 1 | 1;
			putchar(10);
			break;
		}
		cout << '|';
		cout << list[i<<1|1].id << ' ' << setw(20) << list[i<<1|1].name << setw(7) << list[i<<1|1].v;
		putchar(10);
	}
	putchar(10);
	cout << "【优惠信息】：\n";
	for (int i = 0; special[i].id; ++i) {
		cout << special[i].name << '=';
		bool tg = 0;
		for (int j = 0; special[i].id[j]; ++j) {
			int cnt = 1;
			for (; special[i].id[j] == special[i].id[j + 1]; ++cnt, ++j);
			if (tg)
				putchar('+');
			else
				tg = 1;
			cout << list[find_p(special[i].id[j])].name;
			if (cnt != 1)
				cout << '*' << cnt;
		}
		cout << '=' << special[i].v << '\n';
	}
	putchar(10);
	cout << "【输入规则说明】：\n";
	cout << special[0].id << '=';
	bool tg = 0;
	for (int i = 0; special[0].id[i]; ++i) {
		if (tg)
			putchar('+');
		else
			tg = 1;
		cout << list[find_p(special[0].id[i])].name;
		int cnt = 1;
		for (; special[0].id[i] == special[0].id[i + 1]; ++cnt, ++i);
		if (cnt != 1)
			cout << '*' << cnt;
	}
	cout << "\n字母不分大小写，不限顺序，单独输入0则退出程序\n";
	cout << "\n请点单：";
	return all_kinds;
}

int main()
{

	int cnt[100], od[100];
	char ord;
	while (1) {
		int all_kinds = menu();
		memset(cnt, 0, sizeof cnt);
		memset(od, 0, sizeof od);
		bool tg = 0;
		int id = 0;
		while ((ord = getchar()) && ord != '\n' && ord != '0') {
			id = find_p(ord);
			if (id == -1) {
				cin.ignore(0x3f3f3f3f, '\n');
				break;
			}
			++cnt[id], ++od[id];
		}
		if (id == -1)
			continue;
		if (ord == '0')
			return 0;
		double cost = 0.0;
		for (int i = 0; special[i].id; ++i) {
			int tg = 1;
			for (int p = 0; special[i].id[p] && tg; ++p) {
				int tot = 1;
				for (; special[i].id[p] == special[i].id[p + 1]; ++tot, ++p);
				int id = find_p(special[i].id[p]);
				if (cnt[id] < tot)
					tg = 0;
				else
					tg = tg < cnt[id] / tot ? tg : cnt[id] / tot;
			}
			if (tg) {
				cost += special[i].v * tg;
				for (int p = 0; special[i].id[p]; ++p) {
					int tot = 1;
					for (; special[i].id[p] == special[i].id[p + 1]; ++tot, ++p);
					int id = find_p(special[i].id[p]);
					cnt[id] -= tg * tot;
				}
			}
		}
		for(int i = 0; i < all_kinds; ++ i)
			if (cnt[i])
				cost += list[i].v*cnt[i];
		cout << "\n您的点餐=";
		tg = 0;
		for (int i = 0; i < all_kinds; ++i)
			if(od[i]){
				if (tg)
					putchar('+');
				else
					tg = 1;
				cout << list[i].name;
				if (od[i] > 1)
					cout << '*' << od[i];
			}
		cout << "\n共计：" << cost << '\n';
		cout << "点单完成，按任意键继续.";
		ord = getchar();
	}
	return 0;
}
