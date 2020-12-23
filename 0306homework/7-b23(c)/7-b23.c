/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#ifndef __linux
#include<conio.h>
#endif

int Read(FILE* Fil, int n)
{
	int rt = 0, res = 1;
	char c = 0;
	while (n--) {
		fread(&c, 1, 1, Fil);
		rt = rt + ((unsigned char)c) * res;
		res *= 256;
	}
	return rt;
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		puts("usage : 7-b23-demo.exe --modify | --read");
		return 0;
	}
	FILE *Fil = fopen("game.dat", "rb");
	if (Fil == NULL) {
		puts("�ļ���ʧ��");
		return -1;
	}

	char nam[16] = { 0 };
	int value[30];
	int i = 0;
	fread(nam, 16, 1, Fil);

	const int bt[] = { 0, 2, 2, 2, 2, 4, 4, 4, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1 , -1 };
	const int sca[][2] = { {0, 0}, {0, 10000}, {0, 10000}, {0, 8192}, {0, 1024}, {0, 100000000}, {0, 1000000}, {0, 1000000}, {0, 0}, {0, 100}, {0, 100}, {0, 100}, {0, 0}, {0, 2000}, {0, 2000}, {0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 10000}, {0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100} };

	i= 1;
	while(bt[i] != -1){
		value[i] = Read(Fil, bt[i]);
		if (i == 7)
			Read(Fil, 8);
		if (i == 10)
			Read(Fil, 1);
		++i;
	}

	const char* lst[] = { "����ǳ�", "����", "����", "����", "����", "��Ǯ", "����", "����", "�ƶ��ٶ�", "�����ٶ�", "������Χ", "������", "������", "���ݶ�", "����", "����", "�ȼ�", "ħ��", "����ħ��", "ħ���˺���", "������", "ħ��������", "������", "����" , NULL };

	if (strcmp(argv[1], "--read") == 0) {
		printf("%18s��%s\n", lst[0], nam);
		i = 1;
		while (lst[i] != NULL) {
			printf("%16sֵ��%d\n", lst[i], value[i]);
			++i;
		}
		putchar(10);
	}
	else if (strcmp(argv[1], "--modify") == 0) {
		while (1) {
			printf("--------------------------------------\n��Ϸ�浵�ļ��޸Ĺ���\n--------------------------------------\n");
			printf("  a.%-10s(%s)\n", lst[0], nam);
			i = 1;
			while (lst[i] != NULL) {
				printf("  %c.%-10s(%d)\n", 'a' + i, lst[i], value[i]);
				++ i;
			}
			printf("  0.�����޸�\n");
			printf("  1.�����˳�\n");
			printf("--------------------------------------\n");
			printf("��ѡ��[a..x,0..1] ");
			char ord;
#ifdef __linux
			ord = getchar();
#else
			ord = _getch();
#endif
			printf("%c\n", ord);
			if (ord == '0')
				break;
			if (ord == '1') {
				FILE *Out = fopen("game.dat", "wb");
				fwrite(&nam, 16, 1, Out);
				char FF = (char)0xff;
				i = 1;
				while(bt[i] != -1) {
					fwrite(&value[i], bt[i], 1, Out);
					if (i == 7){
						int j = 0; 
						while (j < 8){
							fwrite(&FF, 1, 1, Out);
							++ j;
						}
					}
					if (i == 10)
						fwrite(&FF, 1, 1, Out);
					++i;
				}
				fclose(Out);
				break;
			}
			if (ord >= 'a' && ord <= 'x') {
				int p = ord - 'a';
				printf("%s.��ǰֵ=", lst[p]);
				if (ord == 'a')
					printf("%s", nam);
				else {
					printf("%d", value[p]);
					printf("����Χ[%d..%d]", sca[p][0], sca[p][1]);
				}
				printf("�������� ��");
				scanf("%d", &value[p]);
				putchar(10);
			}
			else {
				puts("������󣬳����˳����޸�δ���棡");
				return 0;
			}
		}

	}
	fclose(Fil);
	return 0;
}
