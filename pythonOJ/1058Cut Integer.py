def count_length(x):
    n=x
    count=0
    while n!=0:
        n//=10
        count+=1
    return count
def front(x):
    l=count_length(x)/2
    n=x//pow(10,l)
    return n
def behind(x):
    l=count_length(x)/2
    n=x%pow(10,l)
    return n
def main(num):
    muti=front(num)*behind(num)
    if muti==0 or num%muti!=0:
        return 'No'
    else:
        return 'Yes'
n=int(input())
for i in range(n):
    print(main(int(input())))
