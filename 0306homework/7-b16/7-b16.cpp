/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;

const int Max = 1005;

int check_kind(char *txt, ifstream &In)
{
	int i = 0;
	int rt = 1;
	while ((txt[i] = In.get()) != EOF) {
		if (txt[i] == '\r')
			rt = 0;
		++i;
	}
	return rt;
}

int main(int argc, char *argv[])
{
	ifstream In;
	ofstream Out;
	if (argc < 3) {
		cout << "输入参数错误\n";
		return -1;
	}
	int kind = -1;//0windows 1linux
	const char* nam[] = {"Windows格式", "Linux格式"};
	char txt[Max];
	if (strcmp(*(argv + 1), "-check") == 0) {
		if (argc > 3) {
			cout << "输入参数错误\n";
			return -1;
		}
		else {
			In.open(argv[2], ios::in | ios::binary);
			kind = check_kind(txt, In);
			cout << nam[kind] << '\n';
		}
	}
	else if (strcmp(*(argv + 1), "-convert") == 0){
		if ((strcmp(*(argv + 2), "wtol") != 0 && strcmp(*(argv + 2), "ltow") != 0) || argc != 5) {
			cout << "输入参数错误\n";
			return -1;
		}
		else {
			In.open(argv[3], ios::in | ios::binary);
			Out.open(argv[4], ios::out | ios::binary);
			kind = check_kind(txt, In);
			if (strcmp(*(argv + 2), "wtol") == 0) {
				if (kind != 0) {
					cout << "文件格式错误\n";
					return -1;
				}
				for (int i = 0; txt[i] != EOF; ++i)
					if (txt[i] != '\r')
						Out << txt[i];
			}
			else if(strcmp(*(argv + 2), "ltow") == 0){
				if (kind != 1) {
					cout << "文件格式错误\n";
					return -1;
				}
				for (int i = 0; txt[i] != EOF; ++i) {
					if (txt[i] == '\n')
						Out << '\r';
					Out << txt[i];
				}
			}
			else {
				cout << "输入参数错误\n";
				return -1;
			}
		}
	}
	else {
		cout << "输入参数错误\n";
		return -1;
	}
	In.close();
	Out.close();
	return 0;
}
