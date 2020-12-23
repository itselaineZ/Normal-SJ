/*1952339 信08 张馨月*/
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

struct student {
	int *no;
	char *name;
	int *score;
	student* next;
};

int main()
{
	ifstream infile;
	infile.open("list.txt", ios::in);
	if (infile.is_open() == 0) {
		cout << "打开文件失败\n";
		return -1;
	}
	int x;
	student* p = NULL, * q = NULL, * head = NULL;
	for (int i = 1; ; ++i) {
		infile >> x;
		if (x == 9999999)
			break;
		if (i > 1)
			q = p;
		p = new student;
		if (p == NULL)
			return -1;
		if (i == 1)
			head = p;
		else
			q->next = p;
		p->no = new(nothrow) int;
		if (p->no == NULL)
			return -1;
		p->name = new(nothrow) char[9];
		if (p->name == NULL)
			return - 1;
		p->score = new(nothrow) int;
		if (p->score == NULL)
			return -1;
		*(p->no) = x;
		infile >> p->name >> *(p->score);
		p->next = NULL;
	}

	for (p = head; p; p = p->next)
		cout << *(p->no) << ' ' << p->name << ' ' << *(p->score) << endl;

	p = head;
	while (p) {
		q = p->next;
		delete p->no;
		delete p->name;
		delete p->score;
		delete p;
		p = q;
	}
	return 0;
}