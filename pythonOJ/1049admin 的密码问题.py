def f(x):
    a=[]
    for i in x:
        if i=='1':
            a.append('@')
        elif i=='0':
            a.append('%')
        elif i=='l':
            a.append('L')
        elif i=='O':
            a.append('o')
        else:
            a.append(i)
    return ''.join(a)
N=int(input())
lst=[]
result=[]
count=0
for i in range(N):
    admin,password=input().split(' ')
    new_str=f(password)
    if new_str!=password:
        count+=1
        result.append(admin+' '+new_str)
if count!=0:
    print(count)
    for i in result:
        print(i)
else:
    if N!=1:
        print(f"There are {N} accounts and no account is modified")
    else:
         print(f"There is 1 account and no account is modified")


    
