#1108 质因数分解
import math as m
def is_Prime(x):
    flag=1
    for i in range(2,int(m.sqrt(x))):
        if x%i==0:
            flag=0
    return flag
num=int(input())
lst=[]
flag=1
i=2
while(flag):
    if is_Prime(i) and is_Prime(num//i):
        print(num//i)
        flag=0


