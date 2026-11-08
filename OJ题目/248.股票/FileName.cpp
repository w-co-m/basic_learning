#include<stdio.h>
int main()
{
	int m, p, n,jiao,pri,cash=0,k;
	scanf_s("%d %d %d", &m, &p, &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &jiao, &pri);
		m += jiao;
		cash = cash - (jiao)*pri;
		k = pri;
	}
	int x = cash + m * k;
	printf("%d\n", x);
	return 0;
}