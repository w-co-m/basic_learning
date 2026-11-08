#include<stdio.h>
#include<ctype.h>
typedef struct {
	int len;
	int num[100];
}X; 
X getnum(const char *string)
{
	int i = 0, length = 0;
	X result;
	for (int k = 0; k < 100; k++) {
		result.num[k] = 0;
	}
	while (string[i] != '\0')
	{
		if (isdigit(string[i]))
		{
			int num = 0;
			while (isdigit(string[i]))
			{
				num = num * 10 + (int)(string[i]-'0');
				i++;
			}
			result.num[length] = num;
			length++;
		}
		else
			i++;
	}
	result.len = length;
	return result;
}
int count_len(int x)
{
	if (x == 0) return 1;
	int i = 0;
	while(x!=0)
	{
		x /= 10;
		i++;
	}
	return i;
}
int is_continous(int x)
{
	int num_len = count_len(x);
	if (num_len == 1) return 1;
	else
	{
		int num[100] = { 0 };
		int i = 0,m=x;
		while (m != 0)
		{
			num[i] = m % 10;
			m /= 10;
			i++;
		}
		int a = num[0] - num[1];
		if (a != 1 && a != -1) return 0;
		else
		{
			for (int j = 0; j < num_len - 1; j++)
			{
				if (num[j] - num[j + 1] != a) return 0;
			}
			return 1;
		}
	}
}
int main()
{
	char a[100];
	fgets(a, sizeof(a), stdin);
	X num=getnum(a);
	char result[100][100] = {'\0'};
	for (int i = 0; i < num.len; i++)
	{
		if (is_continous(num.num[i]))
		{
			printf("%d\n", num.num[i]);
		}
	}
	return 0;
}