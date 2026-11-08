#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 51
#define STACK_SIZE 51

// 定义栈结构
char stack[STACK_SIZE];
int top = -1;

// 入栈操作
void push(char ch) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = ch;
    }
}

// 出栈操作
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // 返回空字符表示栈空
}

// 判断栈是否为空
bool is_empty() {
    return top == -1;
}

// 获取栈顶元素
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

// 判断是否为左括号
bool is_left_bracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// 判断是否为右括号
bool is_right_bracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// 判断两个括号是否匹配
bool is_matching_pair(char left, char right) {
    if (left == '(' && right == ')') return true;
    if (left == '[' && right == ']') return true;
    if (left == '{' && right == '}') return true;
    return false;
}

// 判断表达式中的括号是否匹配
bool is_balanced(char expression[]) {
    top = -1; // 重置栈
    
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        
        // 如果是左括号，入栈
        if (is_left_bracket(ch)) {
            push(ch);
        }
        // 如果是右括号
        else if (is_right_bracket(ch)) {
            // 如果栈为空，说明没有匹配的左括号
            if (is_empty()) {
                return false;
            }
            // 弹出栈顶元素，检查是否匹配
            char top_char = pop();
            if (!is_matching_pair(top_char, ch)) {
                return false;
            }
        }
        // 其他字符忽略
    }
    
    // 最后检查栈是否为空，空则说明所有括号都匹配
    return is_empty();
}

int main() {
    char expression[MAX_LENGTH];
    
    // 读取输入
    fgets(expression, sizeof(expression), stdin);
    
    // 移除换行符
    int len = strlen(expression);
    if (len > 0 && expression[len-1] == '\n') {
        expression[len-1] = '\0';
    }
    
    // 判断括号是否匹配
    if (is_balanced(expression)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}