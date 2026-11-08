#include<stdio.h>
int main()
{
	int n, a[10],m,count=0;
	scanf_s("%d", &n);
	m = n;
	while (m != 0)
	{
		m /= 10;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		a[i] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < count; i++)
	{
		if (a[i] != 0) printf("%d ", a[i]);
	}
	return 0;
}