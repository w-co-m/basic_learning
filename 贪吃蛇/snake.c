#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25
#define MAX_LENGTH 100

// 游戏元素符号
#define SNAKE_HEAD 'O'
#define SNAKE_BODY 'o'
#define FOOD '@'
#define WALL '#'
#define EMPTY ' '

// 颜色定义
#define COLOR_RED     12
#define COLOR_GREEN   10
#define COLOR_YELLOW  14
#define COLOR_BLUE    9
#define COLOR_MAGENTA 13
#define COLOR_CYAN    11
#define COLOR_WHITE   15
#define COLOR_PINK    13
#define COLOR_ORANGE  6

// 音效频率定义
#define SOUND_EAT 523  // 吃到食物的音效 (C5)
#define SOUND_LEVEL_UP 659  // 升级音效 (E5)
#define SOUND_COLLISION 220  // 碰撞音效 (A3)
#define SOUND_GAME_OVER 175  // 游戏结束音效 (F3)

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
int speed = 120; // 游戏速度，数值越小速度越快
int game_level = 1; // 游戏等级
int sound_enabled = 1; // 音效开关

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
void set_color(int color);
void draw_welcome_screen();
void draw_game_frame();
void draw_score_panel();
void play_sound(int frequency, int duration);
void toggle_sound();

int main() {
    srand(time(NULL));
    hide_cursor();
    
    draw_welcome_screen();
    getch();
    
    init_game();
    
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
    speed = 120;
    game_level = 1;
    sound_enabled = 1;
}

void draw_board() {
    // 绘制游戏框架
    draw_game_frame();
    
    // 绘制食物
    gotoxy(food.x + 1, food.y + 1);
    set_color(COLOR_RED);
    printf("%c", FOOD);
    
    // 绘制蛇身
    for (int i = 0; i < snake.length; i++) {
        gotoxy(snake.body[i].x + 1, snake.body[i].y + 1);
        if (i == 0) {
            // 蛇头
            set_color(COLOR_GREEN);
            printf("%c", SNAKE_HEAD);
        } else {
            // 蛇身
            // 根据蛇身位置改变颜色，创建彩虹效果
            int color = COLOR_CYAN + (i % 4);
            if (color > COLOR_WHITE) color = COLOR_CYAN;
            set_color(color);
            printf("%c", SNAKE_BODY);
        }
    }
    
    // 绘制分数面板
    draw_score_panel();
    
    // 显示控制提示
    gotoxy(2, HEIGHT + 5);
    set_color(COLOR_WHITE);
    printf("控制: WASD 移动 | Q 退出 | M 静音");
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
        score += 10 * game_level;
        
        // 播放吃到食物的音效
        if (sound_enabled) {
            play_sound(SOUND_EAT, 100);
        }
        
        // 随着得分增加，游戏速度加快
        if (speed > 40) {
            speed -= 3;
        }
        
        // 每50分提升一个等级
        int old_level = game_level;
        game_level = score / 50 + 1;
        
        // 如果升级了，播放升级音效
        if (game_level > old_level && sound_enabled) {
            play_sound(SOUND_LEVEL_UP, 200);
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
            case 'm':
            case 'M':
                toggle_sound();
                break;
        }
    }
}

int check_collision() {
    // 检查是否撞墙
    if (snake.body[0].x < 0 || snake.body[0].x >= WIDTH ||
        snake.body[0].y < 0 || snake.body[0].y >= HEIGHT) {
        if (sound_enabled) {
            play_sound(SOUND_COLLISION, 300);
            play_sound(SOUND_GAME_OVER, 500);
        }
        return 1;
    }
    
    // 检查是否撞到自己
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && 
            snake.body[0].y == snake.body[i].y) {
            if (sound_enabled) {
                play_sound(SOUND_COLLISION, 300);
                play_sound(SOUND_GAME_OVER, 500);
            }
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

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void show_game_over() {
    system("cls");
    set_color(COLOR_RED);
    printf("\n");
    printf("  #####################################################\n");
    printf("  #                                                   #\n");
    printf("  #                  GAME OVER!                       #\n");
    printf("  #                                                   #\n");
    set_color(COLOR_YELLOW);
    printf("  #               最终得分: %-8d                 #\n", score);
    printf("  #               最终长度: %-8d                 #\n", snake.length);
    printf("  #               游戏等级: %-8d                 #\n", game_level);
    set_color(COLOR_MAGENTA);
    printf("  #                                                   #\n");
    printf("  #              按任意键退出游戏...                  #\n");
    printf("  #                                                   #\n");
    printf("  #####################################################\n");
    set_color(COLOR_WHITE);
    getch();
}

void draw_welcome_screen() {
    system("cls");
    set_color(COLOR_GREEN);
    printf("\n");
    printf("  #####################################################\n");
    printf("  #                                                   #\n");
    printf("  #              欢迎来到贪吃蛇游戏!                  #\n");
    printf("  #                                                   #\n");
    set_color(COLOR_CYAN);
    printf("  #         *****************************************  #\n");
    printf("  #         *                                       *  #\n");
    printf("  #         *           经典贪吃蛇游戏              *  #\n");
    printf("  #         *                                       *  #\n");
    printf("  #         *     使用 WASD 键控制蛇的移动          *  #\n");
    printf("  #         *     吃到 @ 可以增加分数和长度         *  #\n");
    printf("  #         *     避免撞墙或撞到自己的身体          *  #\n");
    printf("  #         *     按 Q 键退出游戏                   *  #\n");
    printf("  #         *     按 M 键开启/关闭音效              *  #\n");
    printf("  #         *                                       *  #\n");
    printf("  #         *         按任意键开始游戏              *  #\n");
    printf("  #         *                                       *  #\n");
    printf("  #         *****************************************  #\n");
    set_color(COLOR_GREEN);
    printf("  #                                                   #\n");
    printf("  #####################################################\n");
    set_color(COLOR_WHITE);
}

void draw_game_frame() {
    // 绘制上边框
    gotoxy(0, 0);
    set_color(COLOR_BLUE);
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("%c", WALL);
    }
    
    // 绘制左右边框
    for (int y = 1; y <= HEIGHT; y++) {
        gotoxy(0, y);
        printf("%c", WALL);
        gotoxy(WIDTH + 1, y);
        printf("%c", WALL);
    }
    
    // 绘制下边框
    gotoxy(0, HEIGHT + 1);
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("%c", WALL);
    }
}

void draw_score_panel() {
    // 绘制分数面板背景
    gotoxy(0, HEIGHT + 2);
    set_color(COLOR_PINK);
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("=");
    }
    
    // 显示分数信息
    gotoxy(2, HEIGHT + 3);
    set_color(COLOR_YELLOW);
    printf("得分: %d", score);
    
    gotoxy(15, HEIGHT + 3);
    printf("长度: %d", snake.length);
    
    gotoxy(28, HEIGHT + 3);
    printf("等级: %d", game_level);
    
    gotoxy(40, HEIGHT + 3);
    printf("速度: %d", (120 - speed + 50) / 10);
    
    gotoxy(2, HEIGHT + 4);
    if (sound_enabled) {
        set_color(COLOR_GREEN);
        printf("音效: 开启");
    } else {
        set_color(COLOR_RED);
        printf("音效: 关闭");
    }
}

void play_sound(int frequency, int duration) {
    if (sound_enabled) {
        Beep(frequency, duration);
    }
}

void toggle_sound() {
    sound_enabled = !sound_enabled;
}