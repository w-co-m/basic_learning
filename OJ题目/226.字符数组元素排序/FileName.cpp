#include<stdio.h>
#include<string.h>
int main()
{
	char a[101]={'\0'}, b[101];
	gets(a);
	int len = strlen(a);
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
		printf("%c", a[i]);
	return 0;
}