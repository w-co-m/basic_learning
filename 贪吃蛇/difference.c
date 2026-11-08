#include <stdio.h>

int main() {
    int m;
    double numbers[10];
    
    // 读取整数 m
    scanf("%d", &m);
    
    // 读取 m 个实数
    for (int i = 0; i < m; i++) {
        scanf("%lf", &numbers[i]);
    }
    
    // 初始化最大值和最小值为第一个差异值
    double max_diff = numbers[1] - numbers[0];
    double min_diff = numbers[1] - numbers[0];
    
    // 计算所有差异值并更新最大值和最小值
    for (int i = 1; i < m; i++) {
        double diff = numbers[i] - numbers[i-1];
        if (diff > max_diff) {
            max_diff = diff;
        }
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    // 输出结果，保留两位小数
    printf("%.2f %.2f\n", max_diff, min_diff);
    
    return 0;
}