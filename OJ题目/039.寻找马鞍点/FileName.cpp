#include <stdio.h>

int main() {
    int m, n;
    
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    // 读取矩阵元素
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 遍历矩阵的每个元素，寻找马鞍点
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current = matrix[i][j];
            int is_row_min = 1;  // 标记是否是行最小值
            int is_col_max = 1;  // 标记是否是列最大值

            // 1. 检查当前元素是否是所在行的最小值
            for (int k = 0; k < n; k++) {
                if (matrix[i][k] < current) {  // 有比当前元素小的，不是行最小
                    is_row_min = 0;
                    break;
                }
            }

            // 2. 如果是行最小，再检查是否是所在列的最大值
            if (is_row_min) {
                for (int k = 0; k < m; k++) {
                    if (matrix[k][j] > current) {  // 有比当前元素大的，不是列最大
                        is_col_max = 0;
                        break;
                    }
                }
            }

            // 3. 既是行最小又是列最大，找到马鞍点
            if (is_row_min && is_col_max) {
                printf("%d %d %d\n", i, j, current);
                return 0;  // 找到后直接退出程序
            }
        }
    }

    // 遍历完所有元素都没有找到，输出 no
    printf("no\n");
    return 0;
}