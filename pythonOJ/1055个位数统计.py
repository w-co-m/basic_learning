from collections import Counter
lst=[]
n=int(input())
while n!=0:
    x=n%10
    lst.append(x)
    n//=10
num_count=Counter(lst)
for num in sorted(num_count.keys()):
    print(f"{num}:{num_count[num]}")
