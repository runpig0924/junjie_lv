#define _CRT_SECURE_NO_WARNINGS 1

#define MinNum 1
#define MaxNum 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu()
{
	printf("**********************\n");
	printf("*****欢迎来到游戏*****\n");
	printf("*** 1.play  0.exit ***\n");
	printf("**********************\n");
}

void game_guss()
{
	int num;
	int randnum;
	randnum = rand() % (MaxNum - MinNum+1) + 1;
	while (1)
	{
		printf("请输入数字(%d~%d)：", MinNum, MaxNum);
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("恭喜，猜对了！\n");
			break;
		}
		else if (MinNum < num && num < randnum)
			printf("猜小了！\n");
		else if (randnum < num && num< MaxNum)
			printf("猜大了！\n");
		else
		{
			printf("违规输入，请重新输入！\n");
		}
	}
}

void game_compare()
{
	int num;
	int randnum;
	randnum = rand() % (MaxNum - MinNum + 1) + 1;
	while (1)
	{
		printf("请输入数字(%d~%d)：", MinNum, MaxNum);
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("平局！您的数是%d,对手的数是%d。\n", num, randnum);
			break;
		}
		else if (MinNum < num && num < randnum)
		{
			printf("输了！您的数是%d,对手的数是%d。\n", num, randnum);
			break;
		}
			
		else if (randnum < num && num< MaxNum)
		{
			printf("赢了！您的数是%d,对手的数是%d。\n", num, randnum);
			break;
		}
		else
		{
			printf("违规输入，请重新输入！\n");
		}
	}
}

void test()
{
	int input;
	int game_chose;
	char game_again;
	do
	{
		menu();
		printf("是否进入游戏？");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			do
			{
				printf("请选择游戏：");
				printf("<< 1.猜数字 >>--<< 2.比大小 >>");
				scanf("%d", &game_chose);
				switch (game_chose)
				{
				case 1:
					game_guss();
					printf("是否继续游戏？1/0:");
					scanf("%d", &game_again);
					if (game_again ==1)
						continue;
					else
						break;
					
				case 2:
					game_compare();
					printf("是否继续游戏？1/0:");
					scanf("%d", &game_again);
					if (game_again == 1)
						continue;
					else
						break;
				default:
					printf("违规输入，请重新输入！");
					break;
				}
			} while (game_chose != 1 && game_chose != 2);
			break;
		case 0:
			printf("游戏退出！\n");
			break;
		default:
			printf("违规输入，请重新选择！\n");
			break;
		}
	} while (input!=0);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}