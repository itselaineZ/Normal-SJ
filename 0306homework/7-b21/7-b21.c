/*1952339 ��08 ��ܰ��*/
/*1953429 ��ǿ 1953695 ������ 1953080 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(int argc, char* argv[])
{
	FILE *In;
	char txt[20];
	if (argc == 1) {
		puts("�ļ���������ʽ�����ԣ�");
		puts("    a.txt������·����ʽ");
		puts("    ..\\data\\b.dat�����·����ʽ");
		puts("    C:\\Windows\\System32\\c.dat���������·����ʽ");
		printf("�������ļ���: ");
		scanf("%s", txt);
		In = fopen(txt, "rb");
	}
	else
		In = fopen(argv[1], "rb");
	if (In == NULL) {
		puts("���ļ�ʧ��");
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