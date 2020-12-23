/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

const int N = 10;
const int M = 3;

struct student {
	int no;
	char name[9];
	float score[M];
	float ave, sum;
};

int main()
{
	student stu[N + 5];
	float maxsc = 0.0f;
	for (int i = 1; i <= N; ++i) {
		cout << "请输入第" << setw(2) << i << "个学生的信息：";
		cin >> stu[i].no >> stu[i].name >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(0x3f3f3f3f, '\n');
			cout << "请输入第" << setw(2) << i << "个学生的信息：";
			cin >> stu[i].no >> stu[i].name >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
		}
		stu[i].sum = 0.0f;
		for (int j = 0; j < M; ++j)
			stu[i].sum += stu[i].score[j];
		stu[i].ave = stu[i].sum / M;
		maxsc = maxsc > stu[i].sum ? maxsc : stu[i].sum;
	}
	cout << "\n10个学生的成绩为：\n";
	cout << setiosflags(ios::left);
	cout << setw(5) << "序号" << setw(8) << "学号" << setw(9) << "姓名" << setw(15) << "三门课成绩" << setw(5) << "平均成绩\n";
	cout << "=============================================\n";
	for (int i = 1; i <= N; ++i) {
		cout << setw(5) << i;
		cout << setw(8) << stu[i].no;
		cout << setw(9) << stu[i].name;
		for (int j = 0; j < M; ++j)
			cout << setw(5) << stu[i].score[j];
		cout << setw(5) << setprecision(4) << stu[i].ave;
		putchar(10);
	}
	cout << "\n最高分学生信息：\n";
	cout << setw(5) << "序号" << setw(8) << "学号" << setw(9) << "姓名" << setw(15) << "三门课成绩" << setw(5) << "总成绩\n";
	cout << "=============================================\n";
	for(int i = 1; i <= N; ++ i)
		if (stu[i].sum == maxsc) {
			cout << setw(5) << i;
			cout << setw(8) << stu[i].no;
			cout << setw(9) << stu[i].name;
			for (int j = 0; j < M; ++j)
				cout << setw(5) << stu[i].score[j];
			cout << setw(5) << stu[i].sum;
			putchar(10);
		}
	return 0;
}