#include<stdio.h>
int main()
{
	int  max=0, min=9;
	long long x;
	scanf_s("%lld", &x);
	while (x != 0)
	{
		int n = x % 10;
		x /= 10;
		if (n > max) max = n;
		if (n < min) min = n;
	}
	printf("%d %d", max, min);
	return 0;
}