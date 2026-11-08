#include<stdio.h>
typedef struct a
{
	int x1;
	int y1;
	int x2;
	int y2;
	int name;
}AREA;
typedef struct c
{
	int x;
	int y;
}CLICK;
int is_click(AREA a, CLICK c)
{
	if (c.x >= a.x1 && c.x <= a.x2 && c.y >= a.y1 && c.y <= a.y2)
		return 1;
	else
		return 0;
}
int main()
{
	int M, N;
	AREA a[100];
	CLICK c[100];
	scanf_s("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		a[i].name = i + 1;
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %d", &c[i].x,&c[i].y);
	}
	for (int i = 0; i < N; i++)
	{
		int flag = 0;
		for (int j = M-1; j >= 0; j--)
		{
			if (is_click(a[j], c[i]))
			{
				flag = 1;
				printf("%d\n", a[j].name);
				AREA temp = a[j];
				a[j] = a[M - 1];
				a[M - 1] = temp;
				break;
			}
		}
		if (!flag) printf("IGNORED\n");
	}
	return 0;
}