#include <stdio.h>

int main() {
    long long initial_height, n;
    
    // 读取输入：初始高度和弹跳次数
    scanf("%lld %lld", &initial_height, &n);
    
    // 特殊情况处理：如果n为0，则没有弹跳
    if (n == 0) {
        printf("0.0 0.0\n");
        return 0;
    }
    
    // 初始化变量
    double current_height = (double)initial_height;
    double total_distance = 0.0;
    
    // 计算第n次落地时经过的总距离和第n次反弹的高度
    for (int i = 1; i <= n; i++) {
        // 每次落地都需要计算下落的距离
        total_distance += current_height;
        
        // 更新下一次弹起的高度（反弹到原高度的一半）
        current_height /= 2.0;
        
        // 如果不是最后一次落地，还要计算反弹上升的距离
        if (i < n) {
            total_distance += current_height;
        }
    }
    
    // 输出结果：总距离和第n次反弹的高度
    printf("%.1f %.1f\n", total_distance, current_height);
    
    return 0;
}