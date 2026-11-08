#include<stdio.h>
int main()
{
	int m, a[100][100], sum[1000] = { 0 };
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum[i] += a[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum[i+m] += a[j][i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		sum[2 * m] += a[i][i];
		sum[2 * m + 1] += a[i][m - 1 - i];
	}
	for (int i = 0; i < 2 * m + 1; i++)
	{
		for (int j = 0; j < 2 * m + 1 - i; j++)
		{
			if (sum[j] < sum[j + 1])
			{
				int temp = sum[j];
				sum[j] = sum[j + 1];
				sum[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 2 * m + 2; i++) printf("%d ", sum[i]);
	return 0;
}