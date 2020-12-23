/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

struct student {
	int no;
	char name[9];
	int score;
	int rank;
};

int cmp1(const student a, const student b)
{
	if (a.score == b.score)
		return a.no - b.no;
	return b.score - a.score;
}

int cmp2(const student a, const student b)
{
	return a.no - b.no;
}

int main()
{
	ifstream infile;
	infile.open("student.txt", ios::in);
	if (infile.is_open() == 0) {
		cout << "打开文件失败\n";
		return -1;
	}
	int N;
	infile >> N;
	student* p, * q, * head = new(nothrow) student[N];
	if (head == NULL) {
		cout << "申请失败\n";
		return -1;
	}
	p = head;
	for (int i = 1; i <= N; ++p, ++i)
		infile >> p->no >> p->name >> p->score;

	student* t = new(nothrow) student;
	if (t == NULL) {
		cout << "申请失败\n";
		return -1;
	}

	p = head;
	for (int i = 1; i < N; ++p, ++i) {
		q = p + 1;
		for (int j = i + 1; j <= N; ++q, ++j)
			if (cmp1(*p, *q) > 0) {
				*t = *p;
				*p = *q;
				*q = *t;
			}
	}
	head->rank = 1;
	p = head + 1;
	for (int i = 2; i <= N; ++p, ++i)
		if (p->score == (p - 1)->score)
			p->rank = (p - 1)->rank;
		else
			p->rank = i;
	p = head;
	for (int i = 1; i < N; ++p, ++i) {
		q = p + 1;
		for (int j = i + 1; j <= N; ++q, ++j)
			if (cmp2(*p, *q) > 0) {
				*t = *p;
				*p = *q;
				*q = *t;
			}
	}
	p = head;
	for (int i = 1; i <= N; ++p, ++i)
		cout << p->no << ' ' << p->name << ' ' << p->score << ' ' << p->rank << endl;
	return 0;
}