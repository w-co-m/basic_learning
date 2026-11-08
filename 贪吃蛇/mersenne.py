def calculate_mersenne(p):
    # 计算2^p - 1的位数
    # 使用log10(2^p) = p * log10(2)来计算位数
    import math
    digits = int(p * math.log10(2)) + 1
    
    # 计算2^p - 1的最后500位数字
    # 使用模幂运算来避免大数计算
    mod = 10**500
    last_500_digits = pow(2, p, mod) - 1
    if last_500_digits < 0:
        last_500_digits += mod
    
    # 将数字转换为字符串并补零到500位
    last_500_str = str(last_500_digits).zfill(500)
    
    # 计算最高位数字
    # 使用2^p的首位数字，然后考虑减1的影响
    # log10(2^p) = p * log10(2) = integer_part + fractional_part
    # 2^p = 10^(integer_part + fractional_part) = 10^integer_part * 10^fractional_part
    # 首位数字是int(10^fractional_part)
    fractional_part = p * math.log10(2) - int(p * math.log10(2))
    first_digit = int(10 ** fractional_part)
    
    # 对于2^p - 1，如果2^p不是10的幂，则首位数字不变
    # 如果2^p是10的幂，则2^p - 1的首位数字是9
    # 但在实际中，2^p很少是10的幂，所以我们使用近似方法
    
    return digits, last_500_str, first_digit

def main():
    # 读取输入
    p = int(input())
    
    # 计算结果
    digits, last_500_str, first_digit = calculate_mersenne(p)
    
    # 输出位数
    print(digits)
    
    # 输出最后500位数字，每行50位
    for i in range(0, 500, 50):
        print(last_500_str[i:i+50])
    
    # 输出最高位数字
    print(first_digit)

if __name__ == "__main__":
    main()