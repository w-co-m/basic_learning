#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// 比较函数，用于排序
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // 读取数组长度
    scanf("%d", &n);

    // 动态分配数组内存
    int* nums = (int*)malloc(n * sizeof(int));

    // 读取数组元素
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // 读取目标值
    int target;
    scanf("%d", &target);

    // 对数组进行排序
    qsort(nums, n, sizeof(int), compare);

    // 初始化最接近的和与最小差值
    int closest_sum = nums[0] + nums[1] + nums[2];
    int min_diff = abs(closest_sum - target);

    // 使用双指针法寻找最接近的三数之和
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            int current_diff = abs(current_sum - target);

            // 如果当前和更接近目标值，更新结果
            if (current_diff < min_diff) {
                min_diff = current_diff;
                closest_sum = current_sum;
            }

            // 如果找到了完全匹配的和，直接返回
            if (current_sum == target) {
                printf("%d\n", current_sum);
                free(nums);
                return 0;
            }
            // 根据当前和与目标值的关系移动指针
            else if (current_sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    // 输出最接近的三数之和
    printf("%d\n", closest_sum);

    // 释放动态分配的内存
    free(nums);
    return 0;
}