#include<stdio.h>
int main(void)
{
	int i=0;
	int sum=0;
	for (i; i < 10; ++i) {
		sum += i * i;
	}
	printf("%d\n",sum);
	return 0;
	
}