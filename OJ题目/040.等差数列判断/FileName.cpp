#include<stdio.h>
int main()
{
	int n, num[100] = {0}, dif, x = 1;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num[i]);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	dif = num[1] - num[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (num[i + 1] - num[i] != dif) x = 0;
	}
	if (x) printf("%d\n", dif);
	else printf("no\n");
	return 0;
}