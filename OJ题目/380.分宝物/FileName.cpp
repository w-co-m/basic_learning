#include <stdio.h>
#include <stdlib.h>  // abs()
#include <stdbool.h>

// 判断是否为质数
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 生成前count个质数
void generate_primes(int prime[], int count) {
    int num = 2, index = 0;
    while (index < count) {
        if (is_prime(num)) {
            prime[index++] = num;
        }
        num++;
    }
}

// 回溯函数：递归分配物品，寻找最小差值
// index：当前处理到第index件物品（0~4）
// sumA：当前A的总价值
// sumB：当前B的总价值
// treasure：5件物品的价值数组
// min_diff：指向最小差值的指针（用于修改全局最小值）
void backtrack(int index, int sumA, int sumB, int treasure[], int *min_diff) {
    // 终止条件：所有5件物品分配完毕
    if (index == 5) {
        int diff = abs(sumA - sumB);
        if (diff < *min_diff) {
            *min_diff = diff; // 更新最小差值
        }
        return;
    }

    // 选择1：当前物品分给A，递归处理下一件
    backtrack(index + 1, sumA + treasure[index], sumB, treasure, min_diff);

    // 选择2：当前物品分给B，递归处理下一件（回溯的核心：尝试另一种选择）
    backtrack(index + 1, sumA, sumB + treasure[index], treasure, min_diff);
}

int main() {
    int n;
    scanf_s("%d", &n);

    // 步骤1：生成前23个质数（满足n+4≤23）
    int prime[23];
    generate_primes(prime, 23);

    // 步骤2：提取第n~n+4个质数（共5件物品）
    int treasure[5];
    for (int i = 0; i < 5; i++) {
        treasure[i] = prime[n - 1 + i];
    }

    // 步骤3：回溯寻找最小差值
    int min_diff = 10000; // 初始化为大数
    backtrack(0, 0, 0, treasure, &min_diff); // 从第0件物品开始，A、B初始总和为0

    // 输出结果
    printf("%d\n", min_diff);

    return 0;
}