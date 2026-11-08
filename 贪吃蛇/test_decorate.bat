@echo off
echo 正在编译装饰水果程序...
echo.

REM 检查是否安装了gcc
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo 使用gcc编译...
    gcc decorate_cake.c -o decorate_cake.exe
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1:
        echo 输入: 20 [回车] 9 6 12 [回车]
        echo 预期输出: 1
        echo 程序输出:
        (
            echo 20
            echo 9 6 12
        ) | decorate_cake.exe
        echo.
        echo 测试用例2:
        echo 输入: 10 [回车] 2 3 4 [回车]
        echo 预期输出: 2
        echo 程序输出:
        (
            echo 10
            echo 2 3 4
        ) | decorate_cake.exe
        echo.
        echo 测试用例3:
        echo 输入: 5 [回车] 6 1 1 [回车]
        echo 预期输出: Error!
        echo 程序输出:
        (
            echo 5
            echo 6 1 1
        ) | decorate_cake.exe
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
    cl decorate_cake.c
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1:
        echo 输入: 20 [回车] 9 6 12 [回车]
        echo 预期输出: 1
        echo 程序输出:
        (
            echo 20
            echo 9 6 12
        ) | decorate_cake.exe
        echo.
        echo 测试用例2:
        echo 输入: 10 [回车] 2 3 4 [回车]
        echo 预期输出: 2
        echo 程序输出:
        (
            echo 10
            echo 2 3 4
        ) | decorate_cake.exe
        echo.
        echo 测试用例3:
        echo 输入: 5 [回车] 6 1 1 [回车]
        echo 预期输出: Error!
        echo 程序输出:
        (
            echo 5
            echo 6 1 1
        ) | decorate_cake.exe
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