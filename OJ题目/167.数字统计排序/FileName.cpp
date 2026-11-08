#include<stdio.h>
typedef struct M
{
	int shu;
	int ci;
}m;
int main()
{
	int n,temp,count=0,flag=1;
	m num[1001];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &temp);
		for (int j = 0; j < count; j++)
		{
			if (num[j].shu == temp)
			{
				flag = 0;
				num[j].ci++;
			}
		}
		if (flag == 1)
		{
			num[count].shu = temp;
			num[count].ci = 1;
			count++;
		}
		flag = 1;
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (num[i].ci < num[j].ci)
			{
				m x = num[i];
				num[i] = num[j];
				num[j] = x;
			}
			else if (num[i].ci == num[j].ci && num[i].shu > num[j].shu)
			{
				m x = num[i];
				num[i] = num[j];
				num[j] = x;
			}
		}
	}
	for (int i = 0; i < count; i++)
		printf("%d %d\n", num[i].shu, num[i].ci);
	return 0;
}
