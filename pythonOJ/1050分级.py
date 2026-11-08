m=int(input())
lst=list(map(int,input().split()))
L, R = map(int, input().split())
k=0
for i in range(1,m+2):
    Sum=sum(lst[:i-1])
    SUM=sum(lst[i-1:])
    if L<=Sum<=R and L<=SUM<=R:
        k=i
        break
print(k)
