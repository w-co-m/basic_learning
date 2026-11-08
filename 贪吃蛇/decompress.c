#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 51
#define MAX_OUTPUT_LENGTH 101

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    int output_index = 0;
    
    // 读取输入
    fgets(input, sizeof(input), stdin);
    
    // 移除换行符
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // 解压缩字符串
    int i = 0;
    while (i < len) {
        // 获取当前字符
        char ch = input[i];
        i++;
        
        // 读取连续的数字
        int num = 0;
        while (i < len && isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
            i++;
        }
        
        // 如果有数字且大于等于3，则重复字符
        if (num >= 3) {
            for (int j = 0; j < num; j++) {
                output[output_index++] = ch;
            }
        } else {
            // 如果没有数字或数字小于3，则只输出一个字符
            output[output_index++] = ch;
        }
        
        // 安全检查，防止缓冲区溢出
        if (output_index >= MAX_OUTPUT_LENGTH - 1) {
            break;
        }
    }
    
    // 添加字符串结束符
    output[output_index] = '\0';
    
    // 输出结果
    printf("%s\n", output);
    
    return 0;
}