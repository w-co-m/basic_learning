n=int(input())
count_0=0
count_5=0
lst=input().split(" ")
for i in lst:
    if int(i)==5:
        count_5+=1
count_0=n-count_5
m=count_5//9
if count_0==0:
    print(-1)
elif m==0:
    print(0)
else:
    m*=9
    result=int("5"*m+"0"*count_0)
    print(result)
    
