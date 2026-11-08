#include<stdio.h>

int get_num(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    int a = 1, b = 1, res = 0;
    for (int count = 3; count <= n; count++) {
        res = a + b;
        a = b;    
        b = res;  
    }
    return res;
}

int main()
{
    float sum = 0.0;
    int n = 0;
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        int a = get_num(i + 3);  
        int b = get_num(i + 2);  
        sum += (float)a / b;
    }
    printf("%.2f", sum);
    return 0;
}