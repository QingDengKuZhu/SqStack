#include "Test.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void gotoxy(const short x, const short y)
{
	COORD pos;	/*COORD在windows.h中定义*/
	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); /* 设置光标位置 */

	return;
}


void Menu(void)
{
	system("cls");
	gotoxy(10, 5);                        /*在文本窗口中设置光标*/
	cprintf("			顺序栈的测试			");
	gotoxy(8, 8);
	cprintf("-----------------------------Menu-----------------------------\n");
	gotoxy(8, 9);
	cprintf("| 1.入栈                             2.输出栈                |\n");
	gotoxy(8, 10);
	cprintf("| 3.出栈                             4.输出栈长度            |\n");
	gotoxy(8, 11);
	cprintf("| 5.清空栈                           6.销毁栈                |\n");
	gotoxy(8, 12);
	cprintf("| 7.返回栈顶元素                     8.判断栈是否为空        |\n");
	gotoxy(8, 13);
	cprintf("| 9.进制转换                                                 |\n");
	gotoxy(8, 14);
	cprintf("--------------------------------------------------------------\n");
	
    return;
}

size_t InputPos(const char notice[])
{
	int pos;		/*保存待输入的位序*/
	unsigned n;		/*保存scanf的返回值*/
	
	do 
	{
		printf(notice);
		n = scanf("%d", &pos);
		fflush(stdin);

		/*判断输入的位序是否在合理的范围内*/
		if (pos<1 || n!=1)
		{
			printf("位序必须大于0!!!\n");
		}
	} while (pos<1 || n!=1);

	return (size_t)pos;
}

int InputValue(const char notice[])
{	
	int e;
	unsigned n;

	do 
	{
		printf(notice);
		n = scanf("%d", &e);
		fflush(stdin);

		if (n != 1)
		{
			printf("请输入满足条件的数值!\n");
		}

	} while (n!=1);
	
	return e;
}