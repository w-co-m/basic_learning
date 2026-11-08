#!/usr/bin/python3
n=int(input())
lst=[]
for i in range(0,n):
    lst.append(int(input()))
count=0
for i  in range(1,n):
    for j in range(0,i):
        if lst[i]==lst[j]:
            count=i+1
            break
    if count!=0:
        break
print(count!=0)
if count!=0:
    print(count)
