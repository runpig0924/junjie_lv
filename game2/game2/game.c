#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitChar(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i=0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}	
	}
}

void DisplayChar(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d|", i);
	}
	printf("\n");
	for (i=1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}	
		printf("\n");
	}	
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{
		int i = 0;
		int j = 0;
		i = rand() % row + 1;
		j = rand() % row + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}		
	}
}

int Lei_Count(char mine[ROWS][COLS], int i, int j)
{
	int lei_count = mine[i - 1][j] +
		mine[i - 1][j - 1] +
		mine[i][j - 1] +
		mine[i + 1][j - 1] +
		mine[i + 1][j] +
		mine[i + 1][j + 1] +
		mine[i][j + 1] +
		mine[i - 1][j + 1]+ 8 * '0';
	return lei_count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i, j;
	int win = 0;
	while (win < row*col - Easy_Count)
	{
		printf("请输入排雷坐标：");
		scanf("%d %d", &i, &j);
		if (i >= 1 && i <= 9 && j >= 1 && j <= 9)
		{
			if (mine[i][j] == '0')
			{
				int lei_count = Lei_Count(mine, i, j);
				show[i][j] = lei_count + '0';
				DisplayChar(show, row, col);
				win++;
			}
			else
			{
				printf("很遗憾，你踩到雷了！\n");
				DisplayChar(mine, row, col);
				break;
			}
		}
		else
			printf("违规输入，请重新输入！\n");
	}	
	if (win == row*col - Easy_Count)
	{
		printf("恭喜你，已经找出所有的雷！\n");
		DisplayChar(show, row, col);
	}
}