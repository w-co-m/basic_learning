#include <stdio.h>
#include <math.h>

int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    if (a[0] + a[1] <= a[2])
        printf("不是三角形");
    else {
        if (pow(a[0], 2) + pow(a[1], 2) == pow(a[2], 2))
            printf("%d\n", a[0] * a[1] / 2);
        else
            printf("其他三角形");
    }

    return 0;
}
