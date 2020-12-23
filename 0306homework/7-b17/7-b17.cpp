/*1952339 ��08 ��ܰ��*/
/*1953429 ��ǿ 1950056 ���ĺ� 1953080 ����*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream In;
	char txt[20];
	if (argc == 1) {
		cout << "�ļ���������ʽ�����ԣ�\n";
		cout << "    a.txt������·����ʽ\n";
		cout << "    ..\\data\\b.dat�����·����ʽ\n";
		cout << "    C:\\Windows\\System32\\c.dat���������·����ʽ\n";
		cout << "�������ļ���: ";
		cin >> txt;
		In.open(txt, ios::in | ios::binary);
	}
	else
		In.open(argv[1], ios::in | ios::binary);
	if (In.is_open() == 0) {
		cout << "���ļ�ʧ��\n";
		return -1;
	}
	int i = 0, j;
	char content[20];
	while (1) {
		cout << setw(8) << setfill('0') << hex << i;
		putchar(32);
		putchar(32);
		for (j = 0; j < 16; ++j) {
			content[j] = In.get();
			if (content[j] == EOF) {
				for (; j < 16; ++j) {
					if (j == 8)
						cout << "  ";
					cout << "   ";
				}
				break;
			}
			if (j == 8)
				cout << "- ";
			cout << setw(2) << setfill('0') << hex << (int)content[j] << ' ';
		}
		cout << "    ";
		for (j = 0; j < 16 && content[j] != EOF; ++j)
			if (content[j] < 33 || content[j] > 126)
				cout << '.';
			else
				cout << content[j];
		putchar(10);
		if (content[j] == EOF)
			break;
		i += 16;
	}
	In.close();
	return 0;
}