#include<stdio.h>
#include<math.h>
int main()
{
    double x, sq, cu, sr;
    printf("Please input a positive number:");
    scanf_s("%1f", &x);
    sq = x * x;
    cu = x * x * x;
    sr = sqrt(x);
    printf("The square of %.2f is %.2f\n", x, sq);
    printf("The cube of %.2f is %.2f\n", x, cu);
    printf("The square-root of %.2f is %.2f\n", x, sr);
    return 0;
}
