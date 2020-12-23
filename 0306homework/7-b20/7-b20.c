/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int check_kind(char* txt, FILE* In)
{
	int i = 0;
	int rt = 1;
	while ((txt[i] = fgetc(In)) != EOF) {
		if (txt[i] == '\r')
			rt = 0;
		++i;
	}
	return rt;
}

int main(int argc, char* argv[])
{
	FILE* In, *Out;
	if (argc < 3) {
		puts("输入参数错误");
		return -1;
	}
	int kind = -1;//0windows 1linux
	const char* nam[] = { "Windows格式", "Linux格式" };
	char txt[1005];
	if (strcmp(*(argv + 1), "-check") == 0) {
		if (argc > 3) {
			puts("输入参数错误");
			return -1;
		}
		else {
			In = fopen(argv[2], "rb");
			kind = check_kind(txt, In);
			puts(nam[kind]);
			fclose(In);
		}
	}
	else if (strcmp(*(argv + 1), "-convert") == 0) {
		if ((strcmp(*(argv + 2), "wtol") != 0 && strcmp(*(argv + 2), "ltow") != 0) || argc != 5) {
			puts("输入参数错误");
			return -1;
		}
		else {
			In = fopen(argv[3], "rb");
			Out = fopen(argv[4], "wb");
			kind = check_kind(txt, In);
			if (strcmp(*(argv + 2), "wtol") == 0) {
				if (kind != 0) {
					puts("文件格式错误");
					return -1;
				}
				for (int i = 0; txt[i] != EOF; ++i)
					if (txt[i] != '\r')
						fputc(txt[i], Out);
			}
			else if (strcmp(*(argv + 2), "ltow") == 0) {
				if (kind != 1) {
					puts("文件格式错误");
					return -1;
				}
				for (int i = 0; txt[i] != EOF; ++i) {
					if (txt[i] == '\n')
						fputc('\r', Out);
					fputc(txt[i], Out);
				}
			}
			else {
				puts("输入参数错误");
				return -1;
			}
			fclose(In);
			fclose(Out);
		}
	}
	else {
		puts("输入参数错误");
		return -1;
	}
	return 0;
}
