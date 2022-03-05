#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"

void menu()
{
	printf("******************\n");
	printf("****  1.play  ****\n");
	printf("****  0.exit  ****\n");
	printf("******************\n");
}

void game()
{
	//雷的存储
	char mine[ROWS][COLS] = { '0' };
	char show[ROWS][COLS] = { '0' };
	//初始化雷区
	InitChar(mine, ROWS, COLS, '0');
	InitChar(show, ROWS, COLS, '*');
	//打印雷区
	/*DisplayChar(mine, ROW, COL);*/
	printf("\n");
	DisplayChar(show, ROW, COL);
	//布置雷区
	SetMine(mine, ROW, COL);
	/*DisplayChar(mine, ROW, COL);*/
	//扫雷
	FindMine(mine,show, ROW, COL);
}

void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("游戏退出！\n");
			break;
		case 1:
			printf("游戏开始！\n");
			game();
			break;
		default:
			printf("违规输入，请重新输入！\n");
			break;
		}
	} while (input);
	
}

int main()
{
	test();
	return 0;
}