/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

const char ord[][5] = { "-w", "-s", "-f" };

int usage(const char* procname)
{
	cout << "Usage: " << procname << " [" << ord[0] << " 大小] [" << ord[1] << " 数量] [" << ord[2] << "] IP地址" << endl;
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
	if (argc < 1) {
		usage(argv[0]);
		return -1;

	}
	int cnt = 0, lst = argc-1;
	for (int i = 0; argv[lst][i]; ++i) {
		++cnt;
		int ip = 0;
		bool in = 0;
		while (argv[lst][i] != '.' && argv[lst][i])
			ip = ip * 10 + argv[lst][i] - '0', ++ i, in = 1;
		if (ip < 0 || ip > 255 || !in) {
			cout << "IP地址错误\n";
			return -1;
		}
		if (argv[lst][i] == 0)
			break;
	}
	if (cnt != 4) {
		cout << "IP地址错误\n";
		return -1;
	}
	int l = 128, n = 100, t = 0;
	for (int i = 1; i < lst; ++i) {
		if (argv[i][0] != '-') {
			cout << "不是以-开头的合法参数\n";
			return -1;
		}
		else if (i+1 < lst && argv[i+1][0] != '-')
			++i;
	}

	for (int i = 1; i < lst;) {
		if (strcmp(argv[i], ord[0]) == 0) {
			if (argv[i + 1][0] == '-' || i + 1 == lst) {
				cout << "参数" << ord[0] << "没有后续参数\n";
				return -1;
			}
			else {
				l = atoi(argv[i + 1]);
				if (l < 32 || l > 16384)
					l = 64;
				i += 2;
			}
		}
		else if (strcmp(argv[i], ord[1]) == 0) {
			if (argv[i + 1][0] == '-' || i + 1 == lst) {
				cout << "参数" << ord[1] << "没有后续参数\n";
				return -1;
			}
			else {
				n = atoi(argv[i + 1]);
				if (n < 0 || n > 2048)
					n = 128;
				i += 2;
			}

		}
		else if (strcmp(argv[i], ord[2]) == 0)
			t = 1, ++i;
		else {
			cout << "参数" << argv[i] << "不存在\n";
			return -1;
		}
	}

	cout << "参数检查通过\n";
	cout << ord[0] << "参数：" << n << '\n';
	cout << ord[1] << "参数：" << l << '\n';
	cout << ord[2] << "参数：" << t << '\n';
	cout << "IP地址：" << argv[lst] << '\n';
	
	return 0;
}//7-b12-demo all all 5 ab 1.txt