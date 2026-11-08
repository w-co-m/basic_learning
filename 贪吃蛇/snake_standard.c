#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 15
#define MAX_LENGTH 50

// 游戏元素符号
#define SNAKE_HEAD 'O'
#define SNAKE_BODY '*'
#define FOOD '$'
#define WALL '#'
#define EMPTY ' '

// 方向枚举
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// 坐标结构体
typedef struct {
    int x;
    int y;
} Point;

// 蛇结构体
typedef struct {
    Point body[MAX_LENGTH];
    int length;
    Direction direction;
} Snake;

// 全局变量
Snake snake;
Point food;
int score = 0;
int game_over = 0;

// 函数声明
void init_game();
void draw_board();
void move_snake();
void generate_food();
int check_collision();

int main() {
    srand(time(NULL));
    init_game();
    
    printf("欢迎来到贪吃蛇游戏！\n");
    printf("这是一个简化版本，使用awsd控制方向\n");
    printf("按回车键开始游戏...\n");
    getchar();
    
    char input;
    while (!game_over) {
        draw_board();
        printf("请输入方向 (a=左, d=右, w=上, s=下, q=退出): ");
        scanf(" %c", &input);
        
        switch (input) {
            case 'w':
            case 'W':
                if (snake.direction != DOWN) // 不允许反向移动
                    snake.direction = UP;
                break;
            case 's':
            case 'S':
                if (snake.direction != UP)
                    snake.direction = DOWN;
                break;
            case 'a':
            case 'A':
                if (snake.direction != RIGHT)
                    snake.direction = LEFT;
                break;
            case 'd':
            case 'D':
                if (snake.direction != LEFT)
                    snake.direction = RIGHT;
                break;
            case 'q':
            case 'Q':
                game_over = 1;
                break;
        }
        
        if (!game_over) {
            move_snake();
            game_over = check_collision();
        }
    }
    
    printf("\n游戏结束！最终得分: %d\n", score);
    printf("蛇的最终长度: %d\n", snake.length);
    
    return 0;
}

void init_game() {
    // 初始化蛇的位置
    snake.length = 3;
    snake.direction = RIGHT;
    
    // 蛇身初始位置在屏幕中央
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;
    snake.body[1].x = WIDTH / 2 - 1;
    snake.body[1].y = HEIGHT / 2;
    snake.body[2].x = WIDTH / 2 - 2;
    snake.body[2].y = HEIGHT / 2;
    
    // 生成第一个食物
    generate_food();
    
    // 初始化分数
    score = 0;
    game_over = 0;
}

void draw_board() {
    // 清屏
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    
    // 绘制上边框
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("%c", WALL);
    }
    printf("\n");
    
    // 绘制游戏区域
    for (int y = 0; y < HEIGHT; y++) {
        printf("%c", WALL); // 左边框
        
        for (int x = 0; x < WIDTH; x++) {
            // 检查当前位置是否是蛇头
            if (x == snake.body[0].x && y == snake.body[0].y) {
                printf("%c", SNAKE_HEAD);
            }
            // 检查当前位置是否是蛇身
            else {
                int is_body = 0;
                for (int i = 1; i < snake.length; i++) {
                    if (x == snake.body[i].x && y == snake.body[i].y) {
                        printf("%c", SNAKE_BODY);
                        is_body = 1;
                        break;
                    }
                }
                // 检查当前位置是否是食物
                if (!is_body) {
                    if (x == food.x && y == food.y) {
                        printf("%c", FOOD);
                    } else {
                        printf("%c", EMPTY);
                    }
                }
            }
        }
        
        printf("%c\n", WALL); // 右边框
    }
    
    // 绘制下边框
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("%c", WALL);
    }
    printf("\n");
    
    // 显示分数和其他信息
    printf("得分: %d\n", score);
    printf("长度: %d\n", snake.length);
}

void move_snake() {
    // 创建新头部位置
    Point new_head = snake.body[0];
    
    // 根据方向更新头部位置
    switch (snake.direction) {
        case UP:
            new_head.y--;
            break;
        case DOWN:
            new_head.y++;
            break;
        case LEFT:
            new_head.x--;
            break;
        case RIGHT:
            new_head.x++;
            break;
    }
    
    // 如果吃到食物，增加蛇长度
    if (new_head.x == food.x && new_head.y == food.y) {
        snake.length++;
        score += 10;
        generate_food();
    }
    
    // 移动身体（从尾部向头部）
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }
    
    // 更新头部位置
    snake.body[0] = new_head;
}

void generate_food() {
    int valid_position = 0;
    
    while (!valid_position) {
        // 随机生成食物位置
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
        
        // 确保食物不在蛇身上
        valid_position = 1;
        for (int i = 0; i < snake.length; i++) {
            if (food.x == snake.body[i].x && food.y == snake.body[i].y) {
                valid_position = 0;
                break;
            }
        }
    }
}

int check_collision() {
    // 检查是否撞墙
    if (snake.body[0].x < 0 || snake.body[0].x >= WIDTH ||
        snake.body[0].y < 0 || snake.body[0].y >= HEIGHT) {
        return 1;
    }
    
    // 检查是否撞到自己
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && 
            snake.body[0].y == snake.body[i].y) {
            return 1;
        }
    }
    
    return 0;
}