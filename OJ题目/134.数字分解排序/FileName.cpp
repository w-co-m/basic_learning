#include<stdio.h>

int main()
{
	int num;
	scanf_s("%d", &num);
	int a[10] = { 0 }, count = 0;
	while (num != 0)
	{
		a[count] = num % 10;
		num = num / 10;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}