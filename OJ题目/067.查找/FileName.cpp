#include<stdio.h>
int main()
{
	int n, k,num[100];
	scanf_s("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num[i]);
	}
	int found = 0;
	for (int i = 0; i < n; i++)
	{
		if (k == num[i])
		{
			printf("%d ", i);
			found = 1;
		}
	}
	if (!found)
		printf("-1");
	return 0;
}