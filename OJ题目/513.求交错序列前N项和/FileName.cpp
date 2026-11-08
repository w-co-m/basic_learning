#include <stdio.h>
#include <math.h>

int main() {
    int N;
    float sum = 0;

    scanf_s("%d", &N);

    for (int i = 1; i <= N; i++) {
        
        sum += pow(-1, i + 1) * (float)i / (2 * i - 1);
    }

    printf("%.3f\n", sum);
    return 0;
}