#include<stdio.h>

int get_num(int n)
{
    if (n == 0) {
        return 7;
    }
    if (n == 1) {
        return 11;
    }
   
    int a = 7, b = 11, res = 0;
   
    for (int count = 2; count <= n; count++) {
        res = a + b;
        a = b;    
        b = res;  
    }
    return res;
}

int main()
{
    int n;
    scanf_s("%d", &n);
    int num = get_num(n);
    printf("%d", num);
    return 0;
}