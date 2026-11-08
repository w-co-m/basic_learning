def Format(x):
    while len(x)<3:
        x='0'+x
    return x
def rep(num):
    global A
    global B
    global re
    if A<=num and num<=B:
        return Format(str(re))
    else:
        return Format(str(num))
initialization=list(map(int,input().split()))
M=initialization[0]
N=initialization[1]
A=initialization[2]
B=initialization[3]
re=initialization[4]
result=[]
for i in range(0,M):
    lst=[]
    lst1=list(map(int,input().split()))
    for j in range(0,N):
        lst.append(rep(lst1[j]))
    print(' '.join(lst))



























