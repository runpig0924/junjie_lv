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
	//�׵Ĵ洢
	char mine[ROWS][COLS] = { '0' };
	char show[ROWS][COLS] = { '0' };
	//��ʼ������
	InitChar(mine, ROWS, COLS, '0');
	InitChar(show, ROWS, COLS, '*');
	//��ӡ����
	/*DisplayChar(mine, ROW, COL);*/
	printf("\n");
	DisplayChar(show, ROW, COL);
	//��������
	SetMine(mine, ROW, COL);
	/*DisplayChar(mine, ROW, COL);*/
	//ɨ��
	FindMine(mine,show, ROW, COL);
}

void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("��Ϸ�˳���\n");
			break;
		case 1:
			printf("��Ϸ��ʼ��\n");
			game();
			break;
		default:
			printf("Υ�����룬���������룡\n");
			break;
		}
	} while (input);
	
}

int main()
{
	test();
	return 0;
}