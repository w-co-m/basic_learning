#include<stdio.h>
int is_run(int y)
{
	if (y % 400 == 0) return 1;
	else if (y % 4 == 0 && y % 100 != 0) return 1;
	else return 0;
}
int count_day(int y, int m, int d)
{
	int day=0;
	int r_month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int n_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int* mon;
	if (is_run(y)) mon = r_month;
	else mon = n_month;
	for (int i = 1; i < y; i++)
	{
		if (is_run(i)) day += 366;
		else day += 365;
	}
	for (int i = 0; i < m-1; i++)
	{
		day += mon[i];
	}
	day += d;
	return day;
}
int count_gap(int y,int m,int d)
{
	int gap;
	gap = count_day(y, m, d) - count_day(2021, 11, 14);
	return gap;
}
int main()
{
	int y, m, d;
	scanf_s("%d %d %d", &y, &m, &d);
	int gap = count_gap(y, m, d);
	gap %= 7;
	if (gap < 0) gap += 7;
	switch (gap)
	{
	case 1:printf("Monday"); break;
	case 2:printf("Tuesday"); break;
	case 3:printf("Wednesday"); break;
	case 4:printf("Thursday"); break;
	case 5:printf("Friday"); break;
	case 6:printf("Saturday"); break;
	case 0:printf("Sunday"); break;
	}
	
	return 0;
}