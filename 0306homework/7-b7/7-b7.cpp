/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;

const char* ans[] = {"OFF", "ON"};

void on_off_print(short on_off_switch)
{
	for (char i = 'A'; i <= 'J'; ++i)
		cout << setfill(' ') << setw(4) << setiosflags(ios::left) << i;
	putchar(10);
	for (int i = 0; i < 10; ++i)
		cout << setfill(' ') << setw(4) << ans[((1 << i) & on_off_switch) != 0];
	putchar(10);
}

int main()
{
	short on_off_switch = 0;
	cout << "��ʼ״̬��0x" << setfill('0') << setw(4) << hex << on_off_switch << endl;
	on_off_print(on_off_switch);
	putchar(10);
	char c;
	char ord[5];
	while (1) {
		cout << "����(\"A On / J Off\"��ʽ���룬����\"Q on / off\"�˳�)\n";
		cin >> c >> ord;
		if (c > 'Z')
			c -= 'a' - 'A';
		for (int i = 0; ord[i]; ++i)
			if (ord[i] > 'Z')
				ord[i] -= 'a' - 'A';
		while (cin.fail() || (strcmp(ord, ans[0]) != 0 && strcmp(ord, ans[1]) != 0) || ((c < 'A' || c > 'J') && c != 'Q')) {
			cin.clear();
			cin.ignore(0x3f3f3f3f, '\n');
			cout << "����(\"A On / J Off\"��ʽ���룬����\"Q on / off\"�˳�)\n";
			cin >> c >> ord;
			if (c > 'Z')
				c -= 'a' - 'A';
			for (int i = 0; ord[i]; ++i)
				if (ord[i] > 'Z')
					ord[i] -= 'a' - 'A';
		}
		if (c == 'Q')
			break;
		if (ord[1] == 'N')
			on_off_switch |= (1 << (c - 'A'));
		else if(on_off_switch & (1 << (c - 'A')))
			on_off_switch ^= (1 << (c - 'A'));
		cout << "��ǰ״̬��0x" << setfill('0') << setw(4) << setiosflags(ios :: right) << hex << on_off_switch << endl;
		cout << resetiosflags(ios :: right);
		on_off_print(on_off_switch);
		putchar(10);
	}
	return 0;
}
