#include <stdio.h>
int main()
{
	int n,hang,lie;
	scanf_s("%d", &n);
	n = n%100-2;
	lie = ((n-1) / 11 )*2+ 1;
	hang = n % 11;
	if (hang == 0) hang = 11;
	printf("%d %d", hang, lie);
	return 0;
}