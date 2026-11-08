#include <stdio.h>

int main() {
    int m, n;
    int histogram[16] = { 0 };
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gray_level;
            scanf("%d", &gray_level);
            histogram[gray_level]++;
        }
    }

    for (int i = 0; i < 16; i++) {
        if (histogram[i] > 0) {
            printf("%d %d\n", i, histogram[i]);
        }
    }

    return 0;
}