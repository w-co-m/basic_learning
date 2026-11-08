#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],result[100];
	gets(a);
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] > 47 && a[i] < 58)
			result[i] = '*';
		else if (a[i] > 64 && a[i] < 91)
			result[i] = a[i] + 32;
		else if (a[i] > 96 && a[i] < 123)
			result[i] = a[i] - 32;
		else
			result[i] = '@';
	}
	result[len] = '\0';
	puts(result);
	return 0;
}