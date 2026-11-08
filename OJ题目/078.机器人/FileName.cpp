#include<stdio.h>
int main()
{
	int row, col, re_col,re_row=0,count=0,flag=1;
	scanf_s("%d %d %d", &row, &col, &re_col);
	re_col--;
	getchar();
	char a[100][100];
	int point[100][100] = {0};
	for (int i = 0; i < row; i++)
	{
		fgets(a[i], sizeof(a[i]), stdin);
	}
	while (re_row >= 0 and re_row < row and re_col >= 0 and re_col < col and flag==1)
	{
		point[re_row][re_col] = 1;
		if (a[re_row][re_col] == 'N')
			re_row--;
		else if (a[re_row][re_col] == 'S')
			re_row++;
		else if (a[re_row][re_col] == 'E')
			re_col++;
		else if (a[re_row][re_col] == 'W')
			re_col--;
		count++;
		if (point[re_row][re_col] == 1)
			flag = 0;
	 }
	if (flag == 1)
		printf("out %d", count);
	else
		printf("loop %d", count);
	return 0;
}