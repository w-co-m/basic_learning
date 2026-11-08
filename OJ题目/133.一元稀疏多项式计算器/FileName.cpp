#include <stdio.h>


// 定义多项式项的结构体：系数+指数
typedef struct {
    int coef;  // 系数
    int exp;   // 指数
} PolyItem;

int main() {
    int n, m, t;
    scanf_s("%d %d %d", &n, &m, &t);
    PolyItem poly1[100], poly2[100], result[200];  // 结果数组足够存储所有项
    int idx1 = 0, idx2 = 0, res_idx = 0;  // 三个数组的遍历指针

    // 读取第一个多项式的n项（系数+指数）
    for (int i = 0; i < n; i++) {
        scanf_s("%d %d", &poly1[i].coef, &poly1[i].exp);
    }

    // 读取第二个多项式的m项，若为减法则系数取反
    for (int i = 0; i < m; i++) {
        scanf_s("%d %d", &poly2[i].coef, &poly2[i].exp);
        if (t == 1) {  // 减法：第二个多项式系数取反
            poly2[i].coef = -poly2[i].coef;
        }
    }

    // 双指针合并两个多项式（已按指数递增排序）
    while (idx1 < n && idx2 < m) {
        if (poly1[idx1].exp == poly2[idx2].exp) {
            // 指数相等，系数相加
            int sum_coef = poly1[idx1].coef + poly2[idx2].coef;
            if (sum_coef != 0) {  // 系数不为0才保留
                result[res_idx].coef = sum_coef;
                result[res_idx].exp = poly1[idx1].exp;
                res_idx++;
            }
            idx1++;
            idx2++;
        }
        else if (poly1[idx1].exp < poly2[idx2].exp) {
            // 第一个多项式当前项指数更小，直接保留
            result[res_idx].coef = poly1[idx1].coef;
            result[res_idx].exp = poly1[idx1].exp;
            res_idx++;
            idx1++;
        }
        else {
            // 第二个多项式当前项指数更小，直接保留
            result[res_idx].coef = poly2[idx2].coef;
            result[res_idx].exp = poly2[idx2].exp;
            res_idx++;
            idx2++;
        }
    }

    // 处理第一个多项式剩余的项
    while (idx1 < n) {
        result[res_idx].coef = poly1[idx1].coef;
        result[res_idx].exp = poly1[idx1].exp;
        res_idx++;
        idx1++;
    }

    // 处理第二个多项式剩余的项
    while (idx2 < m) {
        result[res_idx].coef = poly2[idx2].coef;
        result[res_idx].exp = poly2[idx2].exp;
        res_idx++;
        idx2++;
    }

    // 输出结果（处理格式）
    if (res_idx == 0) {  // 结果为空（所有项系数和为0）
        printf("0\n");
        return 0;
    }

    int first = 1;  // 标记是否是第一项
    for (int i = 0; i < res_idx; i++) {
        int c = result[i].coef;
        int e = result[i].exp;

        // 处理符号
        if (!first) {
            if (c > 0) {
                printf("+");
            }
            else if (c < 0) {
                printf("-");
                c = -c;  // 后续只处理正数系数
            }
        }
        else {
            first = 0;
            if (c < 0) {
                printf("-");
                c = -c;  // 后续只处理正数系数
            }
        }

        // 处理系数和指数
        if (e == 0) {
            // 常数项（指数为0）
            printf("%d", c);
        }
        else if (e == 1) {
            // 指数为1，不输出指数
            if (c != 1) {
                printf("%d", c);
            }
            printf("x");
        }
        else {
            // 指数>1
            if (c != 1) {
                printf("%d", c);
            }
            printf("x^%d", e);
        }
    }
    printf("\n");

    return 0;
}