# include<stdio.h>
int main() {
	long long int n, h;
	scanf("%lld %lld", &h, &n);
	long double h1 = h;
	long double s = 0.0l, h0;
	if (n == 0 || h == 0)
		printf("0.0 0.0");
	else if (n == 1)
	{
		s = h * 1.0l;
		h0 = h1 / 2.0l;
		printf("%.1Lf %.1Lf", s, h0);
	}
	else {
		s = h1 * 1.0l;
		for (int i = 1; i < n; i++)
		{
			s += h1;
			h1 = 1.0l * h1 / 2.0;
			h0 = 1.0l * h1 / 2.0;
		}
		printf("%.1Lf %.1Lf", s, h0);
	}
	return 0;
}