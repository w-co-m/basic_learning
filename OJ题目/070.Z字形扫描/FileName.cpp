#include <stdio.h>

int main() {
    int m;
    // 读取方阵阶数
    scanf_s("%d", &m);

    int a[100][100];
    // 读取方阵元素
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    int is_first = 1; // 标记是否为第一个输出的元素，避免多余空格

    // 遍历所有对角线（s = i + j，范围从 0 到 2m-2）
    for (int s = 0; s <= 2 * m - 2; s++) {
        // 计算当前对角线的 i 取值范围
        int i_min = (s - (m - 1) > 0) ? (s - (m - 1)) : 0; // i 的最小值
        int i_max = (s < m - 1) ? s : (m - 1);             // i 的最大值

        // 蛇形遍历：s 为偶数时从下往上（i 从大到小），奇数时从上往下（i 从小到大）
        if (s % 2 == 0) {
            for (int i = i_max; i >= i_min; i--) {
                int j = s - i; // 计算对应的列索引
                if (is_first) {
                    printf("%d", a[i][j]);
                    is_first = 0;
                }
                else {
                    printf(" %d", a[i][j]);
                }
            }
        }
        else {
            for (int i = i_min; i <= i_max; i++) {
                int j = s - i; // 计算对应的列索引
                if (is_first) {
                    printf("%d", a[i][j]);
                    is_first = 0;
                }
                else {
                    printf(" %d", a[i][j]);
                }
            }
        }
    }

    printf("\n"); // 最后换行
    return 0;
}