贪吃蛇游戏说明
==============

这个项目包含两个版本的贪吃蛇游戏：

1. snake.c - Windows专用版本
   - 使用Windows API和conio.h库
   - 提供更好的游戏体验，支持实时按键控制
   - 包含彩色界面和音效
   - 需要Windows环境和相应编译器

2. snake_standard.c - 标准C版本
   - 使用标准C库编写
   - 兼容性更好，可在多种平台编译
   - 使用字符输入控制方向

3. decompress.c - 字符串解压缩程序
   - 实现了简单的字符串解压缩算法
   - 将压缩后的字符串还原为原始字符串
   - 例如：a5b3aba13b4 -> aaaaabbbabaaaaaaaaaaaaabbbb

4. bracket_match.c - 括号匹配检查程序
   - 检查表达式中的括号是否正确匹配
   - 支持三种括号：()、[]、{}
   - 使用栈数据结构实现算法

5. ball_bounce.c - 皮球弹跳问题程序
   - 计算皮球在第n次落地时经过的总距离
   - 计算第n次反弹的高度
   - 使用数学方法解决物理问题

6. three_sum_closest.c - 最接近的三数之和程序
   - 在给定数组中找到三个数，使其和最接近目标值
   - 使用双指针算法优化时间复杂度
   - 返回最接近的三数之和

7. difference.c - 差异值比较程序
   - 计算连续数值序列中相邻元素的差异值
   - 找出差异值的最大值和最小值
   - 输出保留两位小数的结果

8. matrix_01.c - 0-1矩阵程序
   - 查找矩阵中每行最长的连续1序列
   - 输出每行最长连续1序列的起始位置和结束位置
   - 处理没有1的行情况

9. spiral_fill.c - 螺旋填数程序
   - 创建m行n列的数组，将1-m*n的数字螺旋填入
   - 按照右下左上（顺时针方向）螺旋式填充
   - 输出填好的数组

10. mersenne.py - 梅森质数程序
    - 计算2^P-1的位数和最后500位数字
    - 输出梅森数的最高位数字
    - 使用Python实现高精度数学计算

编译和运行方法： 

Windows系统：
-----------
方法1：使用MinGW
1. 安装MinGW或TDM-GCC
2. 打开命令提示符
3. 进入项目目录
4. 编译命令：
   gcc snake.c -o snake.exe        (编译Windows版本贪吃蛇)
   gcc snake_standard.c -o snake.exe (编译标准版本贪吃蛇)
   gcc decompress.c -o decompress.exe (编译解压缩程序)
   gcc bracket_match.c -o bracket_match.exe (编译括号匹配程序)
   gcc ball_bounce.c -o ball_bounce.exe (编译皮球弹跳程序)
   gcc three_sum_closest.c -o three_sum_closest.exe (编译三数之和程序)
   gcc difference.c -o difference.exe (编译差异值比较程序)
   gcc matrix_01.c -o matrix_01.exe (编译0-1矩阵程序)
   gcc spiral_fill.c -o spiral_fill.exe (编译螺旋填数程序)
5. 运行程序：
   snake.exe 或 decompress.exe 或 bracket_match.exe 或 ball_bounce.exe 或 three_sum_closest.exe 或 difference.exe 或 matrix_01.exe 或 spiral_fill.exe

方法2：使用Visual Studio
1. 打开Visual Studio
2. 创建新项目
3. 将代码复制到源文件中
4. 编译并运行

方法3：使用提供的批处理文件
1. 双击运行 compile.bat (编译贪吃蛇游戏)
2. 双击运行 test_decompress.bat (编译并测试解压缩程序)
3. 双击运行 test_bracket.bat (编译并测试括号匹配程序)
4. 双击运行 test_ball.bat (编译并测试皮球弹跳程序)
5. 双击运行 test_three_sum.bat (编译并测试三数之和程序)
6. 双击运行 test_difference.bat (编译并测试差异值比较程序)
7. 双击运行 test_matrix.bat (编译并测试0-1矩阵程序)
8. 双击运行 test_spiral.bat (编译并测试螺旋填数程序)

方法4：运行Python程序
1. 确保系统已安装Python
2. 打开命令提示符
3. 进入项目目录
4. 运行命令：
   python mersenne.py (运行梅森质数程序)
   双击运行 test_mersenne.bat (测试梅森质数程序)

Linux/Mac系统：
--------------
1. 打开终端
2. 进入项目目录
3. 编译命令：
   gcc snake_standard.c -o snake
   gcc decompress.c -o decompress
   gcc bracket_match.c -o bracket_match
   gcc ball_bounce.c -o ball_bounce
   gcc three_sum_closest.c -o three_sum_closest
   gcc difference.c -o difference
   gcc matrix_01.c -o matrix_01
   gcc spiral_fill.c -o spiral_fill
4. 运行程序：
   ./snake 或 ./decompress 或 ./bracket_match 或 ./ball_bounce 或 ./three_sum_closest 或 ./difference 或 ./matrix_01 或 ./spiral_fill
5. 运行Python程序：
   python mersenne.py

游戏玩法：
---------
- 使用WASD键控制蛇的方向
- 吃到@符号表示的食物可以增加分数和蛇的长度
- 避免撞墙或撞到自己的身体
- 按Q键退出游戏
- 按M键开启/关闭音效（仅Windows版本）

解压缩程序使用方法：
-------------------
- 程序运行后等待用户输入
- 输入压缩后的字符串（如：a5b3aba13b4）
- 程序将输出解压缩后的原始字符串

括号匹配程序使用方法：
---------------------
- 程序运行后等待用户输入
- 输入包含括号的表达式
- 程序将判断括号是否匹配，输出"yes"或"no"

皮球弹跳程序使用方法：
---------------------
- 程序运行后等待用户输入
- 输入两个数字：初始高度和落地次数n
- 程序将输出第n次落地时经过的总距离和第n次反弹的高度

三数之和程序使用方法：
---------------------
- 程序运行后等待用户输入
- 输入数组长度n
- 输入n个整数的数组
- 输入目标值target
- 程序将输出最接近target的三个数之和

差异值比较程序使用方法：
-----------------------
- 程序运行后等待用户输入
- 输入整数m（2 ≤ m ≤ 10）
- 输入m个实数
- 程序将输出差异值的最大值和最小值

0-1矩阵程序使用方法：
--------------------
- 程序运行后等待用户输入
- 输入矩阵的行数m和列数n
- 输入m行n列的0-1矩阵
- 程序将输出每行最长连续1序列的起始位置和结束位置

螺旋填数程序使用方法：
---------------------
- 程序运行后等待用户输入
- 输入正整数m和n
- 程序将输出m行n列的螺旋填充数组

梅森质数程序使用方法：
---------------------
- 程序运行后等待用户输入
- 输入素数P（1000<P<300000）
- 程序将输出2^P-1的位数、最后500位数字和最高位数字

Windows版本特色功能：
--------------------
- 彩色游戏界面
- 实时按键响应
- 游戏音效（吃食物、升级、碰撞等）
- 渐进式难度（随着得分增加，速度加快）
- 等级系统

注意事项：
--------
- Windows版本提供更好的游戏体验
- 标准版本兼容性更好，但需要按回车确认每个操作
- 游戏难度会随着蛇长度增加而提高