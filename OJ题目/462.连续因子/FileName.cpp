#include<stdio.h>
#include<cmath>
int judge(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int  n, i, j, start = 0, l = 0, s = 1;
    scanf_s("%d", &n);
    if (judge(n))
        printf("1\n%d\n", n);
    else {
        for (i = 2; i <= sqrt(n); i++) {
            s = 1;
            for (j = i; s * j <= n; j++) {
                s = s * j;
                if (n % s == 0 && j - i + 1 > l) {
                    start = i;
                    l = j - i + 1;
                }
            }
        }
        printf("%d\n", l);
        for (i = start; i < start + l; i++) {
            if (i == start) {
                printf("%lld", i);
            }
            else {
                printf("*%lld", i);
            }
        }
        printf("\n");
    }
    return 0;
}