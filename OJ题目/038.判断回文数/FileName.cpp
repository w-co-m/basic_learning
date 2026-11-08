#include<stdio.h>
int main()
{
	int num, a[10], count = 0,sum=0;
	scanf_s("%d", &num);
	while (num != 0)
	{
		a[count] = num % 10;
		sum += a[count];
		num /= 10;
		count++;
	}
	int x = 1;
	for (int i = 0; i < count / 2; i++)
	{
		if (a[i] != a[count - i-1]) x = 0;
	}
	if (x) printf("%d\n", sum);
	else printf("no\n");
	return 0;
}