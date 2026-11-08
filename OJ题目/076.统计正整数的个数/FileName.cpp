#include<stdio.h>
int main()
{
	int n, result[100000] = {0};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf_s("%d", &a);
		if (a > 0)
			result[a]++;
	}
	for (int i = 0; i < 100000; i++)
	{
		if (result[i] > 0)
			printf("%d:%d\n", i, result[i]);
	}
	return 0;
}