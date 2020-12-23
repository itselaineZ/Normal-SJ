/*1952339 信08 张馨月*/
/*1953429 李强 1953695 王虹量 1953080 田宇*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(int argc, char* argv[])
{
	FILE *In;
	char txt[20];
	if (argc == 1) {
		puts("文件名以下形式均可以：");
		puts("    a.txt：不带路径形式");
		puts("    ..\\data\\b.dat：相对路径形式");
		puts("    C:\\Windows\\System32\\c.dat：绝对相对路径形式");
		printf("请输入文件名: ");
		scanf("%s", txt);
		In = fopen(txt, "rb");
	}
	else
		In = fopen(argv[1], "rb");
	if (In == NULL) {
		puts("打开文件失败");
		return -1;
	}
	int i = 0, j;
	char content[20];
	while (1) {
		printf("%08x  ", i);
		int end_cnt = 16;
		for (j = 0; j < 16; ++j) {
			content[j] = fgetc(In);
			if (feof(In)) {
				end_cnt = j;
				for (; j < 16; ++j) {
					if (j == 8)
						printf("  ");
					printf("   ");
				}
				break;
			}
			if (j == 8)
				printf("- ");
			printf("%02hhx ", (int)content[j]);
		}
		printf("    ");
		for (j = 0; j < 16 && j < end_cnt; ++j)
			if (content[j] < 33 || content[j] > 126)
				putchar('.');
			else
				putchar(content[j]);
		putchar(10);
		if (feof(In))
			break;
		i += 16;
	}
	fclose(In);
	return 0;
}