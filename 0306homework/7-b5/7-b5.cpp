/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct student {
	int no;
	char name[15];
	char school[15];
	bool tg;
	student* next;
};

int main()
{
	srand((unsigned int)time(0));
	ifstream infile;
	infile.open("stulist.txt", ios::in);
	ofstream outfile;
	outfile.open("result.txt", ios::out);
	if (infile.is_open() == 0) {
		cout << "���ļ�ʧ��\n";
		return -1;
	}
	int N, M;
	infile >> N >> M;
	student* stu = new student[M];
	for (int i = 0; i < M; stu[i].tg = 0, ++i) 
		infile >> stu[i].no >> stu[i].name >> stu[i].school;

	while (N) {
		int p = rand() % M;
		if (!stu[p].tg) {
			stu[p].tg = 1;
			outfile << stu[p].no << ' ' << stu[p].name << ' ' << stu[p].school << '\n';
			--N;
		}
	}

	delete []stu;
	cout << "ɸѡ���\n";
	return 0;
}//α�����ʱ��Ҫ��ο��ٷ���һЩλ��