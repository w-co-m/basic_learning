#include<stdio.h>
void control(int x, int L[],int len)
{
	for (int k = 1; k <= len; k++)
	{
		if (k % x == 0)
		{
			L[k] = !L[k];
		}
	}
}
int main()
{
	int m, n;
	int light[100] = {0};
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		control(i, light, n);
	}
	for (int i = 1; i <= n; i++)
	{
		if (light[i] == 1) printf("%d ",i);
	}
	return 0;
}