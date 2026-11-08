#include <stdio.h>

int main() {
    int m, n;
    
    // 读取矩阵的行数和列数
    scanf("%d %d", &m, &n);
    
    // 处理每一行
    for (int i = 0; i < m; i++) {
        int row[100];
        
        // 读取当前行的数据
        for (int j = 0; j < n; j++) {
            scanf("%d", &row[j]);
        }
        
        // 查找当前行最长的连续1序列
        int max_length = 0;
        int start_pos = -1;
        int end_pos = -1;
        
        int current_length = 0;
        int current_start = -1;
        
        for (int j = 0; j < n; j++) {
            if (row[j] == 1) {
                // 如果是1，增加当前连续序列长度
                if (current_length == 0) {
                    current_start = j; // 记录当前序列的起始位置
                }
                current_length++;
            } else {
                // 如果是0，检查当前序列是否是最长的
                if (current_length > max_length) {
                    max_length = current_length;
                    start_pos = current_start;
                    end_pos = j - 1;
                }
                current_length = 0; // 重置当前序列长度
            }
        }
        
        // 检查最后一段连续1序列（如果行末以1结尾）
        if (current_length > max_length) {
            max_length = current_length;
            start_pos = current_start;
            end_pos = n - 1;
        }
        
        // 输出结果
        if (max_length == 0) {
            // 如果这一行没有1
            printf("-1 -1\n");
        } else {
            // 输出最长连续1序列的起始位置和结束位置
            printf("%d %d\n", start_pos, end_pos);
        }
    }
    
    return 0;
}