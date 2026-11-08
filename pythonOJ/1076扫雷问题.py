def get_num(lst,i,j):
    global row
    global col
    count=0
    for k in range(0,3):
        for s in range(0,3):
            if i+k-1>=0 and j+s-1>=0 and i+k-1<row and j+s-1<col:
                if lst[i+k-1][j+s-1]=='*':
                    count+=1
    return count
situation=[]
row,col=input().split()
row=int(row)
col=int(col)
for i in range(0,row):
    situation.append(input())
result=[]
for i in range(0,row):
    string=''
    for j in range(0,col):
        if situation[i][j]=='*':
            string+='*'
        else:
            string+=str(get_num(situation,i,j))
    result.append(string)
for i in range(0,row):
    print(result[i])
            
        
    
