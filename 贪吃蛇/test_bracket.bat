@echo off
echo 正在编译括号匹配程序...
echo.

REM 检查是否安装了gcc
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo 使用gcc编译...
    gcc bracket_match.c -o bracket_match.exe
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1: [(d+f)*02]
        echo 预期输出: yes
        echo 程序输出:
        echo [(d+f)*02] | bracket_match.exe
        echo.
        echo 测试用例2: [(2+3))
        echo 预期输出: no
        echo 程序输出:
        echo [(2+3)) | bracket_match.exe
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
    cl bracket_match.c
    if %errorlevel% == 0 (
        echo 编译成功！
        echo.
        echo 测试用例1: [(d+f)*02]
        echo 预期输出: yes
        echo 程序输出:
        echo [(d+f)*02] | bracket_match.exe
        echo.
        echo 测试用例2: [(2+3))
        echo 预期输出: no
        echo 程序输出:
        echo [(2+3)) | bracket_match.exe
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