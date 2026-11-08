@echo off
echo 正在编译贪吃蛇游戏...
echo.

REM 检查是否安装了gcc
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo 使用gcc编译...
    gcc snake.c -o snake.exe
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 运行游戏: snake.exe
        echo.
        snake.exe
    ) else (
        echo 编译失败，请检查代码。
    )
    goto end
)

REM 检查是否安装了cl (Visual Studio)
cl /? >nul 2>&1
if %errorlevel% == 0 (
    echo 使用Visual Studio编译器编译...
    cl snake.c
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 运行游戏: snake.exe
        echo.
        snake.exe
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