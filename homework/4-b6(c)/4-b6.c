/* 1952339 ��08 ��ܰ�� */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu(const HANDLE hout) {
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.�ü�ͷ��������������(�߽�ֹͣ����ʾHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n");
	printf("6.�ü�ͷ��������������(�߽���ƣ���ʾHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n");
	printf("0.�˳�\n");
	return _getch() - '0';
}

void move_cursor(const HANDLE hout, short lft_arw, short arw, short revlv) {
	//lft_arw: 1��ʾ�����������(��case 1 and case 2)
	//arw: 1��ʾֻ����ͨ���������Ҽ�һ�����(��case 3 and case 4)
	//revlv: 1��ʾҪ��߽����
	int x = 34, y = 8;
	gotoxy(hout, x, y);

	char c;
	short flg = 0;

	if (arw) {
		while ((c = _getch()) != -1 && c != '\n') {
			if (c == 'q' || c == 'Q')
				break;
			if (c == -32)
				c = _getch(), flg = 1;
			if (c == ' ') {
				putchar(' ');
				gotoxy(hout, x, y);
				continue;
			}
			if (!flg)
				continue;
			if (c == 72) {
				if (y - 1)
					gotoxy(hout, x, --y);
				else if (revlv)
					gotoxy(hout, x, y = MAX_Y);
			}
			else if (c == 75) {
				if (x - 1)
					gotoxy(hout, --x, y);
				else if (revlv)
					gotoxy(hout, x = MAX_X, y);
			}
			else if (c == 77) {
				if (x + 1 <= MAX_X)
					gotoxy(hout, ++x, y);
				else if (revlv)
					gotoxy(hout, x = 1, y);
			}
			else if (c == 80) {
				if (y + 1 <= MAX_Y)
					gotoxy(hout, x, ++y);
				else if (revlv)
					gotoxy(hout, x, y = 1);
			}
			flg = 0;
		}
	}
	else {
		while ((c = _getch()) != -1 && c != '\n') {
			if (c == 'q' || c == 'Q')
				break;
			if (c == -32)
				c = _getch(), flg = 1;
			if (c == ' ') {
				putchar(' ');
				gotoxy(hout, x, y);
				continue;
			}
			if (c == 'i' || c == 'I') {
				if (y - 1)
					gotoxy(hout, x, --y);
				else if (revlv)
					gotoxy(hout, x, y = MAX_Y);
			}
			else if (c == 'j' || (c == 'J' && !flg)) {
				if (x - 1)
					gotoxy(hout, --x, y);
				else if (revlv)
					gotoxy(hout, x = MAX_X, y);
			}
			else if (c == 'l' || c == 'L') {
				if (x + 1 <= MAX_X)
					gotoxy(hout, ++x, y);
				else if (revlv)
					gotoxy(hout, x = 1, y);
			}
			else if (c == 'k' || (c == 'K' && (lft_arw || !flg))) {
				if (y + 1 <= MAX_Y)
					gotoxy(hout, x, ++y);
				else if (revlv)
					gotoxy(hout, x, y = 1);
			}
			flg = 0;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	while (1) {
		cls(hout);
		int ord = menu(hout);
		printf("[��ѡ��0-6] ");
		if (ord == 0)
			return 0;
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);

		switch (ord) {
			case 1: {
				move_cursor(hout, 1, 0, 0);
				break;
			}
			case 2: {
				move_cursor(hout, 1, 0, 1);
				break;
			}
			case 3: {
				move_cursor(hout, 0, 1, 0);
				break;
			}
			case 4: {
				move_cursor(hout, 0, 1, 1);
				break;
			}
			case 5: {
				move_cursor(hout, 0, 0, 0);
				break;
			}
			case 6: {
				move_cursor(hout, 0, 0, 1);
				break;
			}
			default: {
				return 0;
			}
		}

		gotoxy(hout, 0, 23);
		printf("��Ϸ���������س����˳�.\n");
		while ((_getch()) != '\r')
			;
	}
	return 0;
}
