#include<stdio.h>
int is_jishu(int x)
{
	if (x % 2 == 1) return 1;
	return 0;
}
int main()
{
	int n;
	scanf_s("%d", &n);
	if (is_jishu(n)) n = 3 * n + 1;
	printf("%d\n", n);
	return 0;
}