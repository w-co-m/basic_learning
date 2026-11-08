#1104(3n + 1) 猜想
def is_oushu(x):
    if x%2==1:
        return 0
    else:
        return 1
N=int(input())
if N==1:
    print("OK")
while(N!=1):
    if is_oushu(N):
        N/=2
    else:
        N=N*3+1
    print(int(N))
    