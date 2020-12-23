/* 1952339 信08 张馨月 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu(const HANDLE hout) {
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用箭头键控制上下左右(边界停止，演示HPKM可移动的错误，此项不需要实现)\n");
	printf("6.用箭头键控制上下左右(边界回绕，演示HPKM可移动的错误，此项不需要实现)\n");
	printf("0.退出\n");
	return _getch() - '0';
}

void move_cursor(const HANDLE hout, short lft_arw, short arw, short revlv) {
	//lft_arw: 1表示左键可以下移(即case 1 and case 2)
	//arw: 1表示只可以通过上下左右键一起控制(即case 3 and case 4)
	//revlv: 1表示要求边界回绕
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	while (1) {
		cls(hout);
		int ord = menu(hout);
		printf("[请选择0-6] ");
		if (ord == 0)
			return 0;
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		/* 显示初始的边框及其中的随机字符 */
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
		printf("游戏结束，按回车键退出.\n");
		while ((_getch()) != '\r')
			;
	}
	return 0;
}
