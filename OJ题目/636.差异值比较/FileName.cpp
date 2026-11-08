#include <stdio.h>

int main() {
    int m;
    // 读取序列长度 m
    scanf("%d", &m);

    // 存储 m 个实数（m≤10，数组大小足够）
    double nums[10];
    for (int i = 0; i < m; i++) {
        scanf("%lf", &nums[i]); // double 对应格式符 %lf
    }

    // 计算第一个差异值，初始化最大值和最小值
    double max_diff, min_diff, diff;
    diff = nums[1] - nums[0];
    max_diff = diff;
    min_diff = diff;

    // 遍历剩余元素，计算差异值并更新极值
    for (int i = 2; i < m; i++) {
        diff = nums[i] - nums[i - 1];
        if (diff > max_diff) {
            max_diff = diff;
        }
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    // 保留两位小数输出，最大值在前，最小值在后
    printf("%.2f %.2f\n", max_diff, min_diff);
    return 0;
}