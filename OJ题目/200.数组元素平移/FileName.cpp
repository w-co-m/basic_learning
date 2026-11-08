#include <stdio.h>

int main() {
    // 已知原始数组
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int p;

    // 读取输入的下标p
    scanf("%d", &p);

    int is_first = 1; // 标记是否为第一个输出的元素，避免末尾多余空格

    // 1. 输出后半部分：下标从 p+1 到 9
    for (int i = p + 1; i < 10; i++) {
        if (is_first) {
            printf("%d", array[i]); // 第一个元素不加空格
            is_first = 0;
        }
        else {
            printf(" %d", array[i]); // 后续元素前加空格
        }
    }

    // 2. 输出前半部分：下标从 0 到 p
    for (int i = 0; i <= p; i++) {
        if (is_first) {
            printf("%d", array[i]); // 若后半部分为空（p=9），直接输出前半部分
            is_first = 0;
        }
        else {
            printf(" %d", array[i]);
        }
    }

    printf("\n"); // 最后换行，保证格式规范
    return 0;
}