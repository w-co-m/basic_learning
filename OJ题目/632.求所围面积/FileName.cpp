#include <stdio.h>

int main() {
    double y[10];  
    int count = 0; 
    char c;        


    while (count < 10) {
        while ((c = getchar()) == ' ' || c == '\n' || c == '\t') {
            continue;
        }

        if (c == '!') {
            break;
        }

        ungetc(c, stdin);

        scanf("%lf", &y[count]);
        count++;
    }

    // 计算面积
    double area = 0.0;
    for (int i = 0; i < count - 1; i++) {
        // 梯形面积公式：(上底 + 下底) * 高 / 2，这里高为 1
        area += (y[i] + y[i + 1]) / 2.0;
    }

    // 输出结果，精确到小数点后 2 位
    printf("%.2lf\n", area);

    return 0;
}