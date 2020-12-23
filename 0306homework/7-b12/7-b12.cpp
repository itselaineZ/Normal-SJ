/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring> 
using namespace std;

int usage(const char* procname)
{
	cout << "Usage: " << procname << " Ҫ����ѧ��/all ƥ��ѧ��/all Դ������/all ���ƶȷ�ֵ(60-100) ���(filename/screen)" << endl;
	cout << "               1959999          1959998      all          80                screen" << endl;
	cout << "               1959999          all          7-b2.cpp     75                result.txt" << endl;
	cout << "               all              all          7-b2.cpp     80                check.dat" << endl;
	cout << "               all              all          all          85                screen" << endl;

	return 0;
}

bool num_check(const char* id)
{
	for (int i = 0; id[i]; ++i)
		if (id[i] < '0' || id[i] > '9')
			return 0;
	return 1;
}

int main(int argc, char* argv[])
{
	if (argc < 6) {
		usage(argv[0]);
		return -1;
	}
	bool all_tg1 = !strcmp(argv[1], "all");
	if (!all_tg1 && strlen(argv[1]) < 7) {
		cout << "Ҫ����ѧ�Ų���7λ\n";
		return -1;
	}
	if (!all_tg1 && !num_check(argv[1])) {
		cout << "Ҫ����ѧ�Ų���7λ����\n";
		return -1;
	}
	bool all_tg2 = !strcmp(argv[2], "all");
	if (!all_tg2 && strlen(argv[2]) < 7) {
		cout << "Ҫƥ���ѧ�Ų���7λ\n";
		return -1;
	}
	if (all_tg1 && !all_tg2) {
		cout << "���ѧ����all, ƥ��ѧ�ű�����all\n";
		return -1;
	}
	if (!all_tg2 && !num_check(argv[2])) {
		cout << "Ҫƥ���ѧ�Ų���7λ����\n";
		return -1;
	}
	if (strlen(argv[3]) > 32) {
		cout << "Դ�����ļ���������32�ֽ�\n";
		return -1;
	}
	int threshold = atoi(argv[4]);
	if (threshold < 60 || threshold > 100)
		threshold = 80;
	if (strlen(argv[5]) > 32) {
		cout << "�������ļ���������32�ֽ�\n";
		return -1;
	}
	cout << "�������ͨ��\n";
	cout << "���ѧ�ţ�" << argv[1] << '\n';
	cout << "ƥ��ѧ�ţ�" << argv[2] << '\n';
	cout << "Դ�ļ�����" << argv[3] << '\n';
	cout << "ƥ����ֵ��" << threshold << '\n';
	cout << "���Ŀ�꣺" << argv[5] << '\n';
	return 0;
}//7-b12-demo all all 5 ab 1.txt
