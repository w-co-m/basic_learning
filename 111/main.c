#include<stdio.h>
#include<math.h>
#include<ctype.h>

typedef struct {
    int len;
    int num[100];
} X;

X getnum(const char *string)
{
    int i = 0, length = 0;
    X result;
    // 初始化结构体数组，避免垃圾值干扰
    for (int k = 0; k < 100; k++) {
        result.num[k] = 0;
    }

    while (string[i] != '\0')
    {
        if (isdigit(string[i]))
        {
            int num = 0;
            while (isdigit(string[i]))
            {
                // 已正确：字符转数字减去 '0'
                num = num * 10 + (int)(string[i] - '0');
                i++;
            }
            // 优化：移除临时数组number，直接赋值给结构体成员
            result.num[length] = num;
            length++;
        }
        else
        {
            i++;
        }
    }
    result.len = length;
    return result;
}

int count_len(int x)
{
    if (x == 0) return 1;
    int i = 0;
    while (x != 0)
    {
        x /= 10;
        i++;
    }
    return i;
}

int is_continous(int x)
{
    // 已优化：提前计算数字位数，避免重复调用函数
    int num_len = count_len(x);
    if (num_len == 1) return 1;

    int num[100] = { 0 };
    int i = 0, m = x;
    while (m != 0)
    {
        num[i] = m % 10;
        m /= 10;
        i++;
    }

    int a = num[0] - num[1];
    if (a != 1 && a != -1) return 0;

    // 已优化：使用提前计算的num_len，循环判断更高效
    for (int j = 0; j < num_len - 1; j++)
    {
        if (num[j] - num[j + 1] != a) return 0;
    }
    return 1;
}

int main()
{
    char a[100];
    // 已优化：使用跨平台的fgets读取字符串
    fgets(a, sizeof(a), stdin);

    // 细节优化：去除fgets读取的换行符
    for (int k = 0; k < 100; k++) {
        if (a[k] == '\n') {
            a[k] = '\0';
            break;
        }
    }

    X num = getnum(a);

    // 优化：删除未使用的二维数组result
    for (int i = 0; i < num.len; i++)
    {
        if (is_continous(num.num[i]))
        {
            printf("%d\n", num.num[i]);
        }
    }
    return 0;
}
