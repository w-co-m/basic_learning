#include<stdio.h>
typedef struct file
{
	int year;
	int month;
	int date;
	int size;
}F;
void swap(F *a, F *b)
{
	F temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int n;
	scanf_s("%d", &n);
	F a[200];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d/%d/%d %d", &a[i].year, &a[i].month, &a[i].date, &a[i].size);

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].year < a[j].year)
				swap(&a[i], &a[j]);
			else if (a[i].year == a[j].year)
			{
				if (a[i].month < a[j].month)
					swap(&a[i], &a[j]);
				else if (a[i].month == a[j].month)
				{
					if (a[i].date < a[j].date)
						swap(&a[i], &a[j]);
					else if (a[i].date == a[j].date)
					{
						if (a[i].size < a[j].size)
							swap(&a[i], &a[j]);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d/%d/%d %d\n", a[i].year, a[i].month, a[i].date, a[i].size);
	}
	return 0;
}