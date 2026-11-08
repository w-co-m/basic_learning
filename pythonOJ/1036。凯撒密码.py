s=input()
x=int(input())
result=[]
x%=26
for i in s:
    m=ord(i)
    if m>=97 and m<=122:
        m+=x
        if m>122:
            m=m-26
    elif m>=65 and m<=90:
        m+=x
        if m>90:
            m=m-26
    result.append(chr(m))
result="".join(result)
print(result)
