#include<stdio.h>
int main()
{
	int row, col, a[100][100],result[100][100];
	scanf_s("%d %d", &row, &col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			scanf_s("%d", &a[i][j]);
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			result[i][j] = a[row - 1 - j][i];
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}