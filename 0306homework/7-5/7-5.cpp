/*1952339 ��08 ��ܰ��*/
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
		cout << "�������" << setw(2) << i << "��ѧ������Ϣ��";
		cin >> stu[i].no >> stu[i].name >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(0x3f3f3f3f, '\n');
			cout << "�������" << setw(2) << i << "��ѧ������Ϣ��";
			cin >> stu[i].no >> stu[i].name >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
		}
		stu[i].sum = 0.0f;
		for (int j = 0; j < M; ++j)
			stu[i].sum += stu[i].score[j];
		stu[i].ave = stu[i].sum / M;
		maxsc = maxsc > stu[i].sum ? maxsc : stu[i].sum;
	}
	cout << "\n10��ѧ���ĳɼ�Ϊ��\n";
	cout << setiosflags(ios::left);
	cout << setw(5) << "���" << setw(8) << "ѧ��" << setw(9) << "����" << setw(15) << "���ſγɼ�" << setw(5) << "ƽ���ɼ�\n";
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
	cout << "\n��߷�ѧ����Ϣ��\n";
	cout << setw(5) << "���" << setw(8) << "ѧ��" << setw(9) << "����" << setw(15) << "���ſγɼ�" << setw(5) << "�ܳɼ�\n";
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