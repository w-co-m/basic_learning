#include<stdio.h>
#include<math.h>
int main()
{
	int n, num[100];
	float aran=0,fc=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num[i]);
		aran += num[i];
	}
	aran /= n;
	for (int i = 0; i < n; i++)
	{
		fc += pow(num[i] - aran, 2);
	}
	fc /= n;
	int result = fc / 1;
	printf("%d\n", result);
	return 0;
}
