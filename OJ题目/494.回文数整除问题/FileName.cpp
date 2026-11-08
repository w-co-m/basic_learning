#include<stdio.h>
int is_huiwen(int x)
{
	if (x / 10000 == x % 10)
	{
		if ((x / 10 % 10) == (x / 1000 % 10))
			return 1;
	}
	return 0;
}
int main()
{
	int M,count=0;
	scanf_s("%d", &M);
	for (int i = 10000; i < 100000; i++)
	{
		if (is_huiwen(i))
		{
			if (i % M == 0)
			{
				count++;
			}
		}
	}
	printf("%d %d", M, count);
	return 0;
}