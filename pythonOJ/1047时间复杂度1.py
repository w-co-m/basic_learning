import sys

def main():
    max_n = 10000
    mpf = [0] * (max_n + 1) 
    for i in range(2, max_n + 1):
        if mpf[i] == 0:  # i是质数，其最小质因子是自身
            mpf[i] = i
            # 标记i的倍数的最小质因子为i（从小到大遍历，确保是最小）
            for j in range(i * i, max_n + 1, i):
                if mpf[j] == 0:
                    mpf[j] = i
    
    # 步骤2：计算前缀和数组（prefix[n] = sum(g(x) for x in 2..n)）
    prefix = [0] * (max_n + 1)
    current_sum = 0
    for x in range(2, max_n + 1):
        if mpf[x] == x:  # x是质数，g(x) = x-2
            g = x - 2
        else:  # x是合数，g(x) = 最小质因子 - 1
            g = mpf[x] - 1
        current_sum += g
        prefix[x] = current_sum
    
    # 步骤3：处理多组输入（以EOF结束）
    for line in sys.stdin:
        n = int(line.strip())
        print(prefix[n])

if __name__ == "__main__":
    main()
