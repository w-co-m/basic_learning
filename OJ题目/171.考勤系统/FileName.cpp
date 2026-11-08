#include<stdio.h>
typedef struct M
{
	int name;
	int time;
}Student;
int main()
{
	int n,k, temp,start_h,start_min,end_hour,end_min,count=0,flag=1;
	Student a[100] = {0};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d:%d %d:%d", &k, &start_h, &start_min, &end_hour, &end_min);
		temp = 60 * end_hour + end_min - (60 * start_h + start_min);
		for (int j = 0; j < count; j++)
		{
			if (k == a[j].name)
			{
				a[j].time += temp;
				flag = 0;
			}
		}
		
		if (flag == 1)
		{
			a[count].name = k;
			a[count].time += temp;
			count++;
		}
		flag = 1;
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (a[i].time < a[j].time)
			{
				Student x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
			else if (a[i].time == a[j].time)
			{
				if (a[i].name > a[j].name)
				{
					Student x = a[i];
					a[i] = a[j];
					a[j] = x;
				}
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d %d\n", a[i].name, a[i].time);
	}
	return 0;
}