#include<stdio.h>
int n;
int count = 0;
void backtrack(int pos, int prev, int sum, int op)
{
	if (pos > n)
	{
		if (op == 1) sum += prev;
		else sum -= prev;
		if (sum == 0) count++;
		return;
	}
	int new_prev = 10 * prev + pos;
	backtrack(pos + 1, new_prev, sum, op);
	int new_sum = sum;
	if (op == 1) new_sum += prev;
	else new_sum -= prev;
	backtrack(pos + 1, pos, new_sum, 1);
	backtrack(pos + 1, pos, new_sum, 0);
}
int main()
{
	scanf_s("%d", &n);
	backtrack(2, 1, 0, 0);
	printf("%d\n", count);
	return 0;
}