#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_LENGTH 100

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
int speed = 100; // 游戏速度，数值越小速度越快

// 函数声明
void init_game();
void draw_board();
void move_snake();
void generate_food();
void handle_input();
int check_collision();
void gotoxy(int x, int y);
void hide_cursor();
void show_game_over();

int main() {
    srand(time(NULL));
    hide_cursor();
    init_game();

    printf("欢迎来到贪吃蛇游戏！\n");
    printf("使用 WASD 控制方向，Q 退出游戏\n");
    printf("按任意键开始游戏...\n");
    getch();

    while (!game_over) {
        draw_board();
        handle_input();
        move_snake();
        game_over = check_collision();
        Sleep(speed); // 控制游戏速度
    }

    show_game_over();

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
    system("cls"); // 清屏

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
                    }
                    else {
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
    printf("使用 WASD 控制方向，Q 退出游戏\n");
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
        // 随着得分增加，游戏速度加快
        if (speed > 50) {
            speed -= 2;
        }
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

void handle_input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
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

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hide_cursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void show_game_over() {
    system("cls");
    printf("\n");
    printf("  #############################################\n");
    printf("  #                                           #\n");
    printf("  #              游戏结束!                    #\n");
    printf("  #                                           #\n");
    printf("  #           最终得分: %-6d               #\n", score);
    printf("  #           最终长度: %-6d               #\n", snake.length);
    printf("  #                                           #\n");
    printf("  #         按任意键退出游戏...               #\n");
    printf("  #                                           #\n");
    printf("  #############################################\n");
    getch();
}