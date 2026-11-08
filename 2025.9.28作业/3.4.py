n=int(input('请输入一个五位数：'))
n0=n//10000
n4=n%10
n1=(n//1000)%10
n3=(n//10)%10
if n0==n4:
    if n1==n3:
        print('这是一个回文数')
else:
    print('这不是一个回文数')

