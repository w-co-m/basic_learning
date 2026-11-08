#include<stdio.h>
#include<string.h>
#include<cmath>
int get_num(char x)
{
	if ('0' <= x && x <= '9')
	{
		int num;
		num = int(x - '0');
		return num;
	}
	else
		return -1;
}
int is_Prime(int x)
{
	if (x == 2)
		return 1;
	int flag = 1;
	for (int i = 2; i<int(sqrt(x)); i++)
	{
		if (x % i == 0) flag = 0;
	}
	return flag;
}
int max_yin(int n)
{
	if (n == 0)
		return 0;
	else if (is_Prime(n))
		return n;
	for (int i = n-1; i >= int(sqrt(n)); i--)
	{
		if (n % i == 0)
			return i;
	}
}
int main()
{
	char a[100];
	int num = 0,site=0;
	fgets(a, sizeof(a), stdin);
	for (int i = 0; i < strlen(a); i++)
	{
		if (get_num(a[i]) != -1)
		{
			num = num * 10;
			num += get_num(a[i]);
		}
	}

	printf("%d", max_yin(num));
	
	return 0;
}