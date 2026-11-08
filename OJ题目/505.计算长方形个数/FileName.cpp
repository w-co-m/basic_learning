#include<stdio.h>
int main()
{
	int m, n,sum;
	scanf_s("%d %d",&m, &n);
	sum = (m * (m + 1) / 2 )* (n * (n + 1) / 2);
	printf("%d", sum);
	return 0;
}