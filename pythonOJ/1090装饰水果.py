#!/usr/bin/python3

num=int(input())
a,b,c=map(int,input().split())
if a==0 or b==0 or c==0:
    sen="Error!"
lst=[]
lst.append(num//a)
lst.append(num//b)
lst.append(num//c)
lst.sort()
if lst[0]==0:
    sen="Error!"
else:
    sen=lst[0]
print(sen)