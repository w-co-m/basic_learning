#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 辅助函数：将字符串转为小写
void to_lower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// 核心函数：统计单词出现次数并输出
void count(char* str, char* target) {
    int count = 0;
    char lower_target[9] = { 0 };  // 目标单词长度≤8，留1位存结束符
    strcpy(lower_target, target);
    to_lower(lower_target);  // 目标单词转小写

    // 按空格分割字符串为单个单词（strtok会修改原字符串，这里先备份无影响）
    char* word = strtok(str, " ");
    while (word != NULL) {
        to_lower(word);  // 当前单词转小写
        // 对比单词（长度+内容都匹配才计数）
        if (strcmp(word, lower_target) == 0) {
            count++;
        }
        word = strtok(NULL, " ");  // 取下一个单词
    }

    // 输出结果：小写单词 + 空格 + 次数
    printf("%s %d\n", lower_target, count);
}

int main() {
    char string[101] = { 0 };  // 字符串长度≤100
    char word[9] = { 0 };      // 目标单词长度≤8

    // 读取整行字符串（包含空格），处理换行符
    fgets(string, sizeof(string), stdin);
    // 去掉fgets读取的换行符（避免分割出空单词）
    string[strcspn(string, "\n")] = '\0';

    // 读取待统计的单词（无空格）
    scanf_s("%s", word);

    // 调用统计函数
    count(string, word);

    return 0;
}