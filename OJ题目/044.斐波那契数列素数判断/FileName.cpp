#include<stdio.h>
#include<math.h>
int get_num(int n)
{
	int k = n - 1;
	int a[1000];
	a[0] = 1;
	a[1] = 1;
	if (k == 0 || k == 1) return 0;
	else 
	{
		int count = 2;
		while (1)
		{
			a[count] = a[count - 1] + a[count - 2];
			if (count == k) break;
			else count++;
	    }
		return a[k];
	}
}
int is_Prime(int n)
{
	for (int i = 2; int(i < sqrt(n)); i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int num,n;
	scanf_s("%d", &n);
	num = get_num(n);
	if (is_Prime(num)) printf("yes");
	else printf("%d", num);
	return 0;
}