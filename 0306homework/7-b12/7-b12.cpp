/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring> 
using namespace std;

int usage(const char* procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl;
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
		cout << "要检查的学号不是7位\n";
		return -1;
	}
	if (!all_tg1 && !num_check(argv[1])) {
		cout << "要检查的学号不是7位数字\n";
		return -1;
	}
	bool all_tg2 = !strcmp(argv[2], "all");
	if (!all_tg2 && strlen(argv[2]) < 7) {
		cout << "要匹配的学号不是7位\n";
		return -1;
	}
	if (all_tg1 && !all_tg2) {
		cout << "检查学号是all, 匹配学号必须是all\n";
		return -1;
	}
	if (!all_tg2 && !num_check(argv[2])) {
		cout << "要匹配的学号不是7位数字\n";
		return -1;
	}
	if (strlen(argv[3]) > 32) {
		cout << "源程序文件名超过了32字节\n";
		return -1;
	}
	int threshold = atoi(argv[4]);
	if (threshold < 60 || threshold > 100)
		threshold = 80;
	if (strlen(argv[5]) > 32) {
		cout << "输出结果文件名超过了32字节\n";
		return -1;
	}
	cout << "参数检查通过\n";
	cout << "检查学号：" << argv[1] << '\n';
	cout << "匹配学号：" << argv[2] << '\n';
	cout << "源文件名：" << argv[3] << '\n';
	cout << "匹配阈值：" << threshold << '\n';
	cout << "输出目标：" << argv[5] << '\n';
	return 0;
}//7-b12-demo all all 5 ab 1.txt
