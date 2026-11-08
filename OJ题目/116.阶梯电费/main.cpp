#include <stdio.h>

int main() {
    double n;
    double money = 0;
    scanf("%lf", &n);
    if (n <= 110) {
        money = 0.5 * n;
    }
    else if (n <= 210) {
        money = 55 + (n - 110) * 0.55;
    }
    else {
        money = 110 + (n - 210) * 0.7;
    }
    printf("%.2f\n", money);
    return 0;
}
