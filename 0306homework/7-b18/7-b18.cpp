/*1952339 ��08 ��ܰ��*/
/*1953429 ��ǿ 1950056 ���ĺ� 1953080 ����*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << "Usage : 7-b18-demo.exe 16����debug��ʽ�ļ��� ԭʼ�ļ���\n";
		return 0;
	}
	ifstream In(argv[1], ios::in | ios::binary);
	ofstream Out(argv[2], ios::out | ios::binary);
	int i;
	char content[20], c, wrd;
	while (1) {
		In >> content;
		for (i = 0; i <= 16; ++i) {
			wrd = 0;
			int cnt = 0;
			while ((cnt < 3 && (c = In.get()) == ' ') || (c == '-' && cnt < 2))
				++ cnt;
			if (c == EOF)
				break;
			if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
				wrd = wrd * 16 + (c >= 'a' && c <= 'f' ? c - 'a' + 10 : c - '0');
				c = In.get();
				wrd = wrd * 16 + (c >= 'a' && c <= 'f' ? c - 'a' + 10 : c - '0');
				Out << wrd;
			}
		}
		if (c == EOF)
			break;
		In.ignore(25, '\n');
	}
	In.close();
	Out.close();
	return 0;
}