#include<stdio.h>

// 定义矩形结构体
typedef struct {
    int x1;  // 左下角横坐标
    int y1;  // 左下角纵坐标
    int x2;  // 右上角横坐标
    int y2;  // 右上角纵坐标
} Rectangle;

int main() {
    int n;          // 矩形的个数
    int area = 0;   // 覆盖的总面积
    // 坐标系范围是0到100，所以数组大小为101x101
    int grid[101][101] = {0};  // 0表示未覆盖，1表示已覆盖

    // 输入矩形的个数
    scanf("%d", &n);

    // 定义存储矩形的数组
    Rectangle rects[100];

    // 输入每个矩形的坐标
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
    }

    // 计算覆盖的总面积
    for (int i = 0; i < n; i++) {
        // 遍历矩形内部的所有单位正方形
        // 注意：这里的x和y是单位正方形的左下角坐标
        for (int x = rects[i].x1; x < rects[i].x2; x++) {
            for (int y = rects[i].y1; y < rects[i].y2; y++) {
                // 如果该单位正方形未被覆盖，则标记为已覆盖并增加面积
                if (grid[x][y] == 0) {
                    grid[x][y] = 1;
                    area++;
                }
            }
        }
    }

    // 输出覆盖的总面积
    printf("%d\n", area);

    return 0;
}