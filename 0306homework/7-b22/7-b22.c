/*1952339 ��08 ��ܰ��*/
/*1953429 ��ǿ 1953695 ������ 1953080 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(int argc, char* argv[])
{
	if (argc < 3) {
		puts("Usage : 7-b18-demo.exe 16����debug��ʽ�ļ��� ԭʼ�ļ���");
		return 0;
	}
	FILE* In = fopen(argv[1], "rb");
	FILE* Out = fopen(argv[2], "wb");
	int i;
	char content[20], c, wrd;
	while (1) {
		fscanf(In, "%s", content);
		for (i = 0; i <= 16; ++i) {
			wrd = 0;
			int cnt = 0;
			while ((cnt < 3 && (c = fgetc(In)) == ' ') || (c == '-' && cnt < 2))
				++cnt;
			if (feof(In))
				break;
			if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
				wrd = wrd * 16 + (c >= 'a' && c <= 'f' ? c - 'a' + 10 : c - '0');
				c = fgetc(In);
				wrd = wrd * 16 + (c >= 'a' && c <= 'f' ? c - 'a' + 10 : c - '0');
				fprintf(Out, "%c", wrd);
			}
		}
		if (c == EOF)
			break;
		
		while (fgetc(In) != '\n')
			;
	}
	fclose(In);
	fclose(Out);
	return 0;
}