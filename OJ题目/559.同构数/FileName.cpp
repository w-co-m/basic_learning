#include<stdio.h>
#include<math.h>
int is_tong(int x)
{
	int m = pow(x,2);
	int n = x;
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	int a = pow(10, count);
	if (m % a == x) return 1;
	return 0;
}
int main()
{
	int n, a[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (is_tong(a[i])) printf("%d\n", a[i]);
		else printf("No\n");
	}

	return 0;
}