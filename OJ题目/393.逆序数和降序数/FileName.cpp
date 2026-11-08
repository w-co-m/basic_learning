#include<stdio.h>
int main()
{
	int num, ni=0, jiang=0, sum,a[100],count=0;
	scanf_s("%d", &num);
	while (num != 0)
	{
		a[count] = num % 10;
		num /= 10;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		ni = 10 * ni + a[i];
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		jiang = 10 * jiang + a[i];
	}
	sum = ni + jiang;
	printf("%d", sum);
	return 0;
}