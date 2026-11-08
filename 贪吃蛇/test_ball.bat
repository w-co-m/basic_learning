@echo off
echo 正在编译皮球弹跳程序...
echo.

REM 检查是否安装了gcc
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo 使用gcc编译...
    gcc ball_bounce.c -o ball_bounce.exe
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1:
        echo 输入: 100 1
        echo 预期输出: 100.0 50.0
        echo 程序输出:
        (
            echo 100 1
        ) | ball_bounce.exe
        echo.
        echo 测试用例2:
        echo 输入: 100 2
        echo 预期输出: 200.0 25.0
        echo 程序输出:
        (
            echo 100 2
        ) | ball_bounce.exe
        echo.
        echo 测试用例3:
        echo 输入: 10 2
        echo 预期输出: 20.0 2.5
        echo 程序输出:
        (
            echo 10 2
        ) | ball_bounce.exe
        echo.
        echo 测试完成！
    ) else (
        echo 编译失败，请检查代码。
    )
    goto end
)

REM 检查是否安装了cl (Visual Studio)
cl /? >nul 2>&1
if %errorlevel% == 0 (
    echo 使用Visual Studio编译器编译...
    cl ball_bounce.c
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1:
        echo 输入: 100 1
        echo 预期输出: 100.0 50.0
        echo 程序输出:
        (
            echo 100 1
        ) | ball_bounce.exe
        echo.
        echo 测试用例2:
        echo 输入: 100 2
        echo 预期输出: 200.0 25.0
        echo 程序输出:
        (
            echo 100 2
        ) | ball_bounce.exe
        echo.
        echo 测试用例3:
        echo 输入: 10 2
        echo 预期输出: 20.0 2.5
        echo 程序输出:
        (
            echo 10 2
        ) | ball_bounce.exe
        echo.
        echo 测试完成！
    ) else (
        echo 编译失败，请检查代码。
    )
    goto end
)

echo 未找到C编译器。
echo.
echo 请安装以下任一编译器：
echo 1. MinGW (包含gcc)
echo 2. TDM-GCC
echo 3. Visual Studio (包含cl)
echo.
echo 安装后重新运行此脚本。

:end
echo.
echo 按任意键退出...
pause >nul