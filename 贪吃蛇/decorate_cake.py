N = int(input())
a, b, c = map(int, input().split())

# 检查是否能装饰蛋糕
if a == 0 and b == 0 and c == 0:
    print("Error!")
else:
    # 计算每种水果最多能装饰多少个蛋糕
    max_by_tomato = N // a if a != 0 else N
    max_by_kiwi = N // b if b != 0 else N
    max_by_mango = N // c if c != 0 else N
    
    # 取最小值，即为最多能装饰的蛋糕数
    result = min(max_by_tomato, max_by_kiwi, max_by_mango)
    
    # 如果结果为0，输出Error!
    if result == 0:
        print("Error!")
    else:
        print(result)