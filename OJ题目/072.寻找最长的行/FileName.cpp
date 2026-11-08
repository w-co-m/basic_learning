#include<stdio.h>
#include<string.h>
int main()
{
	char temp[101],a[200][101];
	int flag = 1,row=0;
	while (flag == 1)
	{
		fgets(temp, sizeof(temp), stdin);
		int len = strlen(temp);
		if (len > 0 && temp[len - 1] == '\n')
		{
			temp[len - 1] = '\0'; 
		}
		if (strcmp(temp,"***end***")==0)
			flag = 0;
		else
		{
			strcpy(a[row], temp);
			row++;
		}
	}
	int max_len, k;
	max_len = strlen(a[0]);
	k = 0;
	for (int i = 1; i < row; i++)
	{
		if (max_len < strlen(a[i]))
		{
			max_len = strlen(a[i]);
			k = i;
		}
	}
	printf("%d\n%s\n", max_len, a[k]);
	return 0;
}