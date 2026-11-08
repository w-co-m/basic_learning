N=int(input())
hang=(N+1)//2
for i in range(0,hang):
    stri=(N//2-i)*' '+(2*i+1)*'*'
    print(stri)
