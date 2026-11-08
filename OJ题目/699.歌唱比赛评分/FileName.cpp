#include<stdio.h>
int main()
{
	int num, n,grade[100],zz;
	float aran=0;
	scanf_s("%d %d", &num, &n);
	for (int i = 0; i < num; i++) scanf_s("%d", &grade[i]);
	zz = grade[n - 1];
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (grade[j] > grade[j + 1])
			{
				int temp = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = temp;
			}
		}
	}
	if (grade[0] == zz)
	{
		for (int i = 0; i < num - 1; i++)
		{
			aran += grade[i];
		}
		aran /= (num - 1);
	}
	else if (grade[num-1] == zz)
	{
		for (int i = 1; i < num ; i++)
		{
			aran += grade[i];
		}
		aran /= (num - 1);
	}
	else 
	{
		for (int i = 1; i < num-1; i++)
		{
			aran += grade[i];
		}
		aran /= (num - 2);
	}
	printf("%.2f", aran);
	return 0;
}