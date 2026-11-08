def count_score(a,b):
    count=0
    if a==0:
        if b==2 or b==3:
            count+=1
        elif b==1 or b==4:
            count-=1
    elif a==1:
        if b==0 or b==3:
            count+=1
        elif b==2 or b==4:
            count-=1
    elif a==2:
        if b==1 or b==4:
            count+=1
        elif b==0 or b==3:
            count-=1
    elif a==3:
        if b==2 or b==4:
            count+=1
        elif b==0 or b==1:
            count-=1
    elif a==4:
        if b==0 or b==1:
            count+=1
        elif b==2 or b==3:
            count-=1
    return count
lst=input().split(" ")
lst=list(map(int,lst))
N=lst[0]
Na=lst[1]
Nb=lst[2]
lsta=list(map(int,input().split()))
lstb=list(map(int,input().split()))
counta=0
for i in range(N):
    na=i%Na
    nb=i%Nb
    counta+=count_score(lsta[na],lstb[nb])
countb=-counta
print(f"{counta} {countb}")



    
