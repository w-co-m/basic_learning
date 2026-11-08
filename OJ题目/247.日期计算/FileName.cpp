#include<stdio.h>
int is_run(int y)
{
	if (y % 400 == 0) return 1;
	else if (y % 4 == 0 && y % 100 != 0) return 1;
	else return 0;
}
int main()
{
	int year, day, month=0;
	scanf_s("%d %d", &year, &day);
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int r_mon[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int *a;
	if (is_run(year)) a = r_mon;
	else a=mon;
	while (day > a[month])
	{
		day -= a[month];
		month++;
	}
	printf("%d %d", month+1, day);
	return 0;
}