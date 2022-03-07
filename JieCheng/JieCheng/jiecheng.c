//«Û1£°+2£°+3£°+4£°.....+ n!
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int i = 0;
	int ret = 1;
	int sum = 0;
	int num = 0;
	printf("«Î ‰»Î£∫");
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		ret = ret*i;
		sum = sum + ret;
	}
	printf("%d", sum);
	return 0;
}