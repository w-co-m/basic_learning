import math as m
def is_prime(x):
    if x==2:
        return True
    else:
        for i in range(2,int(m.sqrt(x))+1):
            if x%i==0:
                return False
        return True
n=int(input())
lst=[]
for i in range(2,n+1):
    if is_prime(i):
        lst.append(i)
print(lst[-2:])
