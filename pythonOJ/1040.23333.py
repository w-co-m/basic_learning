lst=input().split(" ")
n=int(lst[0])
k=int(lst[1])
x=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
result=''
while n>=1:
    result+=x[int(n%k)]
    n//=k
print(result[::-1])
