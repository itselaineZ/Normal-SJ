/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iomanip>
#ifndef _linux
#include<conio.h>
#endif
using namespace std;

int Read(fstream *Fil, int n)
{
	int rt = 0, res = 1;
	char c;
	while (n --) {
		(*Fil).read(&c, sizeof(char));
		rt = rt + ((unsigned char)c) * res;
		res *= 256;
	}
	return rt;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		puts("usage : 7-b23-demo.exe --modify | --read");
		return 0;
	}
	fstream Fil("game.dat", ios::in | ios::out | ios::binary);
	if (Fil.is_open() == 0) {
		cout << "�ļ���ʧ��";
		return -1;
	}
	
	char nam[16] = {0};
	int value[30];
	Fil.read(nam, 16*sizeof(char));

	const int bt[] = { 0, 2, 2, 2, 2, 4, 4, 4, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1 , -1};
	const int sca[][2] = { {0, 0}, {1024, 8192}, {0, 8192}, {0, 1024}, {0, 100000000}, {0, 1000000}, {0, 1000000}, {0, 0}, {0, 100}, {0, 100}, {0, 100}, {0, 0}, {0, 2000}, {0, 2000}, {0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 20000}, {0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100} };
	
	for (int i = 1; bt[i] != -1; ++i) {
		value[i] = Read(&Fil, bt[i]);
		if (i == 7)
			Read(&Fil, 8);
		if (i == 10)
			Read(&Fil, 1);
	}

	const char* lst[] = {"����ǳ�", "ħ��", "����", "����", "����", "��Ǯ", "����", "����", "�ƶ��ٶ�", "���ݶ�", "������Χ", "������", "������", "�����ٶ�", "����", "����", "�ȼ�", "����", "����ħ��", "ħ���˺���", "������", "ħ��������", "������", "����" , NULL};

	if (strcmp(argv[1], "--read") == 0) {
		cout << setw(18) << lst[0] << "��" << nam << endl;
		for (int i = 1; lst[i] != NULL; ++i) {
			cout << setw(18) << lst[i] << "ֵ��" << value[i] << endl;
		}
		cout << endl;
	}
	else if (strcmp(argv[1], "--modify") == 0) {
		while (1) {
			cout << "--------------------------------------\n��Ϸ�浵�ļ��޸Ĺ���\n--------------------------------------\n";
			cout << "  " << 'a' << '.' << setw(10) << setiosflags(ios::left) << lst[0] << "(" << nam << ")\n";
			for (int i = 1; lst[i] != NULL; ++i) {
				cout << "  " << char('a' + i) << '.' << setw(10) << setiosflags(ios::left) << lst[i] << "(" << value[i] << ")\n";
			}
			cout << "  0.�����޸�\n";
			cout << "  1.�����˳�\n";
			cout << "--------------------------------------\n";
			cout << "��ѡ��[a..x,0..1] ";
			char ord;
#ifdef _linux
			ord = getchar();
#else
			ord = _getch();
#endif
			cout << ord << endl;
			if (ord == '0')
				break;
			if (ord == '1') {
				Fil.seekp(0, ios::beg);
				Fil.write(nam, 16);
				char FF = (char)0xff;
				for (int i = 1; bt[i] != -1; ++i) {
					Fil.write((char *)&value[i], bt[i]);
					if (i == 7)
						for (int j = 0; j < 8; ++j)
							Fil.write(&FF, sizeof(FF));
					if (i == 10)
						Fil.write(&FF, 1);
				}
				break;
			}
			if (ord >= 'a' && ord <= 'x') {
				int p = ord - 'a';
				cout << lst[p] << ".��ǰֵ=";
				if (ord == 'a')
					cout << nam;
				else {
					cout << value[p];
					cout << "����Χ[" << sca[p][0] << ".." << sca[p][1] << "]";
				}
				cout << "�������� ��";
				cin >> value[p];
				cout << endl;
			}
			else {
				cout << "������󣬳����˳����޸�δ���棡\n";
				return 0;
			}
		}
		
	}
	Fil.close();
	return 0;
}