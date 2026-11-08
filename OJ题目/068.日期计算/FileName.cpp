#include<stdio.h>
int is_leap_year(int x)
{
	if (x % 400 == 0) return 1;
	else if (x % 4 == 0 && x % 100 != 0) return 1;
	return 0;
}
int main()
{
	int y, d,month,day;
	scanf_s("%d %d", &y, &d);
	int year[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is_leap_year(y)) year[1] = 29;
	for (int i = 0; i < 12; i++)
	{
		month = i + 1;
		if (d <= year[i])
		{
			day = d;
			break;
		}
		else
		{
			d -= year[i];
		}
	}
	printf("%d %d", month, day);
	return 0;
}