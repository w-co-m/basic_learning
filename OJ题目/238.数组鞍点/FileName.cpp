#include<stdio.h>

int main()
{
	int a[4][5],x=0;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf_s("%d", &a[i][j]);
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int flag = 1;
			int num = a[i][j];
			for (int j1 = 0; j1 < 5; j1++)
			{
				if (num < a[i][j1])
				{
					flag = 0;
					break;
				}
			}
			for (int i1 = 0; i1 < 4; i1++)
			{
				if (num > a[i1][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printf("%d %d %d\n", num, i+1, j+1);
				 x = 1;
			}
			
		}
	}
	if (x != 1) printf("°°µã²»´æÔÚ\n");
	return 0;
}