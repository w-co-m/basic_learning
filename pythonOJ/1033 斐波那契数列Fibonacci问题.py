lst=[1,1]
for i in range(2,50):
    lst.append(lst[-1]+lst[-2])
n=int(input())
print(lst[n])
