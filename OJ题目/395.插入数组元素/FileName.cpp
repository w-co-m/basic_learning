#include<stdio.h>
int main()
{
	int n, a[100], num;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &num);
	a[n] = num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n+1; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}