#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int MaxGY(int num1, int num2)
{
	int i=1,maxgy,k;
	if (num1 < num2)
		k = num1;
	else
		k = num2;
	for ( i = 1; i <= k; i++)
	{
		if (num1%i == 0 && num2%i == 0)
			maxgy = i;
	}
	return maxgy;
}

int MinGB(int num3, int num4)
{
	int i = 1, mingb, k;
	if (num3 > num4)
		k = num3;
	else
		k = num4;
	for (i = 1; ; i++)
	{
		if (i%num3 == 0 && i%num4 == 0)
		{
			mingb = i;
			break;
		}
	}
	return mingb;
}
int main()
{
	int x, y,z1,z2;
	printf("请输入两个数：");
	scanf("%d%d", &x, &y);
	z1 = MaxGY(x, y);
	z2 = MinGB(x, y);
	printf("最大公约数为%d\n", z1);
	printf("最小公倍数为%d\n", z2);
	return 0;
}