#define _CRT_SECURE_NO_WARNINGS 1

#define MinNum 1
#define MaxNum 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu()
{
	printf("**********************\n");
	printf("*****��ӭ������Ϸ*****\n");
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
		printf("����������(%d~%d)��", MinNum, MaxNum);
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("��ϲ���¶��ˣ�\n");
			break;
		}
		else if (MinNum < num && num < randnum)
			printf("��С�ˣ�\n");
		else if (randnum < num && num< MaxNum)
			printf("�´��ˣ�\n");
		else
		{
			printf("Υ�����룬���������룡\n");
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
		printf("����������(%d~%d)��", MinNum, MaxNum);
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("ƽ�֣���������%d,���ֵ�����%d��\n", num, randnum);
			break;
		}
		else if (MinNum < num && num < randnum)
		{
			printf("���ˣ���������%d,���ֵ�����%d��\n", num, randnum);
			break;
		}
			
		else if (randnum < num && num< MaxNum)
		{
			printf("Ӯ�ˣ���������%d,���ֵ�����%d��\n", num, randnum);
			break;
		}
		else
		{
			printf("Υ�����룬���������룡\n");
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
		printf("�Ƿ������Ϸ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			do
			{
				printf("��ѡ����Ϸ��");
				printf("<< 1.������ >>--<< 2.�ȴ�С >>");
				scanf("%d", &game_chose);
				switch (game_chose)
				{
				case 1:
					game_guss();
					printf("�Ƿ������Ϸ��1/0:");
					scanf("%d", &game_again);
					if (game_again ==1)
						continue;
					else
						break;
					
				case 2:
					game_compare();
					printf("�Ƿ������Ϸ��1/0:");
					scanf("%d", &game_again);
					if (game_again == 1)
						continue;
					else
						break;
				default:
					printf("Υ�����룬���������룡");
					break;
				}
			} while (game_chose != 1 && game_chose != 2);
			break;
		case 0:
			printf("��Ϸ�˳���\n");
			break;
		default:
			printf("Υ�����룬������ѡ��\n");
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