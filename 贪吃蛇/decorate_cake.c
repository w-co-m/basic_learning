#include <stdio.h>

int main() {
    int N, a, b, c;
    
    // 读取输入
    scanf("%d", &N);
    scanf("%d %d %d", &a, &b, &c);
    
    // 检查是否能装饰蛋糕
    if (a == 0 && b == 0 && c == 0) {
        printf("Error!\n");
        return 0;
    }
    
    // 计算每种水果最多能装饰多少个蛋糕
    int max_by_tomato = (a == 0) ? N : N / a;
    int max_by_kiwi = (b == 0) ? N : N / b;
    int max_by_mango = (c == 0) ? N : N / c;
    
    // 取最小值，即为最多能装饰的蛋糕数
    int result = max_by_tomato;
    if (max_by_kiwi < result) {
        result = max_by_kiwi;
    }
    if (max_by_mango < result) {
        result = max_by_mango;
    }
    
    // 如果结果为0，输出Error!
    if (result == 0) {
        printf("Error!\n");
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}