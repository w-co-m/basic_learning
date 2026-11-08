lst=[]
n=int(input())
for i in range(n):
    lst.append(int(input()))
lst=sorted(lst)
m=int(input())
for i in range(m):
    print(lst[int(input())])
