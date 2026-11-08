#include <stdio.h>

int main() {
    int m, n;
    
    // 读取行数和列数
    scanf("%d %d", &m, &n);
    
    // 创建二维数组
    int matrix[100][100] = {0};
    
    // 定义边界
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int num = 1;
    
    // 螺旋填充
    while (top <= bottom && left <= right) {
        // 从左到右填充上边
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;
        
        // 从上到下填充右边
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        
        // 从右到左填充下边
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        
        // 从下到上填充左边
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    // 输出结果
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}