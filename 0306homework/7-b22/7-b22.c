/*1952339 信08 张馨月*/
/*1953429 李强 1953695 王虹量 1953080 田宇*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(int argc, char* argv[])
{
	if (argc < 3) {
		puts("Usage : 7-b18-demo.exe 16进制debug格式文件名 原始文件名");
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