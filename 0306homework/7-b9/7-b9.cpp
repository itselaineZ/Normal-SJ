/*1952339 ��08 ��ܰ��*/
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
	{'A', "�������ȱ�",        18.5},
	{'B', "���༦�ȱ�",        18.5},
	{'C', "�°¶��������ȱ�",  18.5},
	{'D', "�������������",    14.0},
	{'E', "�ϱ��������",      16.5},
	{'F', "�����ƽ���(4��)", 11.5},
	{'G', "˱ָԭζ��(1��)",   11.5},
	{'H', "������Ǽ�(3��)",   11.5},
	{'I', "�°¶�������(2��)", 12.5},
	{'J', "�������׻�",        11.0},
	{'K', "��������(2��)",     11.5},
	{'L', "�ƽ𼦿�(5��)",     11.0},
	{'M', "����ɫ��",          13.0},
	{'N', "����(С)",          8.5},
	{'O', "����(��)",          11.5},
	{'P', "����(��)",          13.5},
	{'Q', "ܽ��������",        8.5},
	{'R', "�춹��",            6.5},
	{'S', "����������",        7.0},
	{'T', "�������װ�",        8.5},
	{'U', "��ʽ��̢",          7.5},
	{'V', "���¿���(С)",      7.0},
	{'W', "���¿���(��)",      9.5},
	{'X', "���¿���(��)",      11.5},
	{'Y', "�����֭����",      12.0},
	{'Z', "����������",        11.0},
	{'\0', NULL,               0}
};

const struct SPECIAL special[] = {
	{"ANV", "�������ȱ����������",     22},
	{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 100},
	{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
	{"JJ","�������׻�(2��С)",       9.5},
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
	cout << "                      KFC 2020������\n";
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
	cout << "���Ż���Ϣ����\n";
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
	cout << "���������˵������\n";
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
	cout << "\n��ĸ���ִ�Сд������˳�򣬵�������0���˳�����\n";
	cout << "\n��㵥��";
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
		cout << "\n���ĵ��=";
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
		cout << "\n���ƣ�" << cost << '\n';
		cout << "�㵥��ɣ������������.";
		ord = getchar();
	}
	return 0;
}
