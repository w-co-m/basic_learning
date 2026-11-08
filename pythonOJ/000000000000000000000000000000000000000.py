num = int(input())
a, b, c = map(int, input().split())
if a == 0 or b == 0 or c == 0:
    print("Error!")
else:
    res1 = num // a
    res2 = num // b
    res3 = num // c
    min_res = min(res1, res2, res3)
    print("Error!" if min_res == 0 else min_res)