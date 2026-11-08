#include<stdio.h>
int main()
{
	int n, m, a[100][100], t, k, count = 0, p[100] = {0};
	scanf_s("%d %d %d %d", &n, &m, &t, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf_s("%d", &a[i][j]);
	}
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == k)
			{
				if (i != 0 )
				{
					if (a[i - 1][j] != k)
					{
						int flag = 1;
						for (int x = 0; x < t; x++)
						{
							if (p[x] == a[i - 1][j]) flag = 0;
						}
						if (flag == 1)
						{
							p[count] = a[i - 1][j];
							count++;
						}
					}
				}
				if (i != n-1)
				{
					if (a[i + 1][j] != k)
					{
						int flag = 1;
						for (int x = 0; x < t; x++)
						{
							if (p[x] == a[i + 1][j]) flag = 0;
						}
						if (flag == 1)
						{
							p[count] = a[i + 1][j];
							count++;
						}
					}
				}
				if (j != 0)
				{
					if (a[i ][j-1] != k)
					{
						int flag = 1;
						for (int x = 0; x < t; x++)
						{
							if (p[x] == a[i][j-1]) flag = 0;
						}
						if (flag == 1)
						{
							p[count] = a[i][j-1];
							count++;
						}
					}
				}
				if (j != m-1)
				{
					if (a[i ][j+1] != k)
					{
						int flag = 1;
						for (int x = 0; x < t; x++)
						{
							if (p[x] == a[i ][j+1]) flag = 0;
						}
						if (flag == 1)
						{
							p[count] = a[i][j+1];
							count++;
						}
					}
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}