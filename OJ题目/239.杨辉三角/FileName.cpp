#include<stdio.h>


int main()
{
	int n;
	int san[100][100] = {0};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (j == i)
			{
				san[i][j] = 1;
				printf("%d\n", san[i][j]);
			}
			else if (j == 0)
			{
				san[i][j] = 1;
				printf("%d ", san[i][j]);
			}
			
			else
			{
				san[i][j] = san[i - 1][j - 1] + san[i - 1][j];
				printf("%d ", san[i][j]);
			}

		}
	}
	return 0;
}