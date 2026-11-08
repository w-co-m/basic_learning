n = int(input())
a = list(map(int, input().split()))[:n]  
counts = [0] * 11 
res = 0 

for x in a:
   
    res += sum(counts[x+1:])
    counts[x] += 1  

print(res)
