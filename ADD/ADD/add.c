//Çót=1-1/2+1/3-1/4+....+1/m
#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
float add(int m)
{
	float t = 0;
	int s = 1;
	float i = 1;
	for (i; i <= m; i++)
	{
		t = t + s*(1 / i);
		s = s*(-1);
	}
	return t;
}

int main()
{
	int m = 0;
	float sum = 0;
	printf("ÇëÊäÈëm:");
	scanf("%d", &m);
	sum = add(m);
	printf("%f\n", sum);
}