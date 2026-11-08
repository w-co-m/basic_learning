#include<stdio.h>
#include<string.h>
int main()
{
	char a[300], splited_a[100][300],result[100][300];
	fgets(a,sizeof(a),stdin);
	int i = 0,row=0;
	int col = 0;
	while (a[i])
	{
		
		if (a[i] == ' ')
		{
			splited_a[row][col] = '\0';
			row++;
			col = 0;
		}
		else
		{
			splited_a[row][col] = a[i];
			col++;
		}

		i++;
	}
	splited_a[row][col] = '\0';
	int n = 0;
	for (int j = 0; j < row + 1; j++)
	{
		
		if (splited_a[j][0] == '-')
		{
			int flag = 0;
			for (int k = 0; k < n; k++)
			{
				if (strcmp(result[k], splited_a[j])==0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				strcpy(result[n], splited_a[j]);
				n++;
			}
		}
	}
	char temp[300];
	for (int p = 0; p < n; p++)
	{
		for (int q = p + 1; q < n; q++)
		{
			if (strcmp(result[p], result[q]) > 0)
			{
				strcpy(temp, result[p]);
				strcpy(result[p],result[q]);
				strcpy(result[q],temp);
			}
		}
	}
	if (n==0)
	{
		printf("no\n");
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			printf("%s", result[j]);
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}