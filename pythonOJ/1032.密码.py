def is_safe(m):
    if not (len(m)>=8 and len(m)<=16):
        return 'NO'
    a=0
    b=0
    c=0
    d=0
    for i in m:
        if ord(i)>=48 and ord(i)<=57:
            c=1
        elif ord(i)>=65 and ord(i)<=90:
            a=1
        elif ord(i)>=97 and ord(i)<=122:
            b=1
        else:
            d=1
        if a+b+c+d>=3:
            return 'YES'
    return 'NO'
n=int(input())
for i in range(0,n):
    print(is_safe(input()))
