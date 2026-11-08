@echo off
echo 正在编译螺旋填数程序...
echo.

REM 检查是否安装了gcc
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo 使用gcc编译...
    gcc spiral_fill.c -o spiral_fill.exe
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1:
        echo 输入: 4 5
        echo 预期输出:
        echo 1 2 3 4 5
        echo 14 15 16 17 6
        echo 13 20 19 18 7
        echo 12 11 10 9 8
        echo.
        echo 程序输出:
        (
            echo 4 5
        ) | spiral_fill.exe
        echo.
        echo 测试用例2:
        echo 输入: 3 3
        echo 预期输出:
        echo 1 2 3
        echo 8 9 4
        echo 7 6 5
        echo.
        echo 程序输出:
        (
            echo 3 3
        ) | spiral_fill.exe
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
    cl spiral_fill.c
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1:
        echo 输入: 4 5
        echo 预期输出:
        echo 1 2 3 4 5
        echo 14 15 16 17 6
        echo 13 20 19 18 7
        echo 12 11 10 9 8
        echo.
        echo 程序输出:
        (
            echo 4 5
        ) | spiral_fill.exe
        echo.
        echo 测试用例2:
        echo 输入: 3 3
        echo 预期输出:
        echo 1 2 3
        echo 8 9 4
        echo 7 6 5
        echo.
        echo 程序输出:
        (
            echo 3 3
        ) | spiral_fill.exe
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