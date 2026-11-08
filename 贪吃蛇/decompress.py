def decompress_string(compressed):
    """
    解压缩字符串
    对于压缩后的字符串，将字符+数字的格式还原为原始字符串
    如果数字>=3，则重复该字符数字次
    如果没有数字或数字<3，则只输出一个字符
    """
    result = []
    i = 0
    
    while i < len(compressed):
        # 获取当前字符
        ch = compressed[i]
        i += 1
        
        # 读取连续的数字
        num_str = ""
        while i < len(compressed) and compressed[i].isdigit():
            num_str += compressed[i]
            i += 1
        
        # 转换数字字符串为整数
        if num_str:
            num = int(num_str)
            # 如果数字大于等于3，则重复字符
            if num >= 3:
                result.append(ch * num)
            else:
                # 否则只输出一个字符
                result.append(ch)
        else:
            # 没有数字，只输出一个字符
            result.append(ch)
    
    return "".join(result)

# 主程序
if __name__ == "__main__":
    # 读取输入
    compressed = input().strip()
    
    # 解压缩并输出结果
    decompressed = decompress_string(compressed)
    print(decompressed)