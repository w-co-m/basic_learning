#include<stdio.h>
int issushu(int n) {
    int m;
    m = n / 2 + 1;
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    else {
        for (int i=1;i*i<= n; i+=1) {
            if (n % i == 0) {
                return 0;
            }
            return 1;
        }
    }
}
int main() {
    int a;
    scanf_s("%d",& a);
    if (issushu(a)) {
        printf("这是一个素数\n");
    }
    else {
        printf("这不是素数\n");
    }
    return 0;
}
