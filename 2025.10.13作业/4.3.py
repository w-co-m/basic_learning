a=int(input())
b=int(input())
x=a
y=b
while 1:
    if a>b:
        z=a
        a=b
        b=z
    c=b%a
    if c==0:
        break
    b=c
m=int(x*y/a)
print(f"最大公倍数是{m},最大公约数是{a}")
    
    
    
    
