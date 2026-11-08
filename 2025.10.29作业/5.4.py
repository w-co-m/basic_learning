import   math as  m
def isPrime(n):
    if   n<2:
        return  False
    else:
        for  i  in   range(2,int(m.sqrt(n))):
            if n%i==0:
                return  False
        return True
def  PrimeList(N):
    lst=[]
    for j in range (2,N):
        if isPrime(j):
            lst.append(j)
    result=" ".join(str(x) for x in lst)
    print(result)
PrimeList(int(input()))
