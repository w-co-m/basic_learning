#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 100  // 总座位数
#define ROWS 20          // 总排数
#define SEATS_PER_ROW 5  // 每排座位数

// 标记座位是否被占用：0=未占用，1=已占用
int seat_status[TOTAL_SEATS + 1] = { 0 };

// 分配p张票，返回分配的座位号（存入result数组）
void allocate_seats(int p, int result[]) {
    int i, j, k;
    int found = 0;  // 标记是否找到相邻座位

    // 第一步：优先找同一排的连续p个座位（按排从小到大，同排内从左到右）
    for (i = 0; i < ROWS; i++) {
        int row_start = i * SEATS_PER_ROW + 1;  // 当前排的起始座位号
        int row_end = (i + 1) * SEATS_PER_ROW;  // 当前排的结束座位号

        // 检查当前排是否有连续p个空座位
        for (j = row_start; j <= row_end - p + 1; j++) {
            int is_continuous = 1;
            // 检查j到j+p-1的座位是否都为空
            for (k = j; k < j + p; k++) {
                if (seat_status[k] == 1) {
                    is_continuous = 0;
                    break;
                }
            }
            // 找到连续空座位，分配
            if (is_continuous) {
                for (k = j; k < j + p; k++) {
                    result[k - j] = k;
                    seat_status[k] = 1;  // 标记为已占用
                }
                found = 1;
                return;  // 找到后直接返回
            }
        }
        if (found) break;
    }

    // 第二步：无连续座位，分配全局最小的p个空座位
    if (!found) {
        int idx = 0;
        for (i = 1; i <= TOTAL_SEATS && idx < p; i++) {
            if (seat_status[i] == 0) {
                result[idx] = i;
                seat_status[i] = 1;
                idx++;
            }
        }
    }
}

int main() {
    int n;
    // 读取购票指令数量
    scanf_s("%d", &n);

    int p_list[100];  // 存储n个购票数量
    // 读取n个购票数量
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &p_list[i]);
    }

    // 处理每个购票指令
    for (int i = 0; i < n; i++) {
        int p = p_list[i];
        int result[5] = { 0 };  // 最多购5张票，存储分配的座位号
        allocate_seats(p, result);

        // 输出分配的座位号（按从小到大）
        for (int j = 0; j < p; j++) {
            if (j > 0) printf(" ");
            printf("%d", result[j]);
        }
        printf("\n");
    }

    return 0;
}