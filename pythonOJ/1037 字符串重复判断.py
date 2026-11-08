import ast as a
chars=[]
lst=a.literal_eval(input())
for i in lst[0]:
    m=1
    temp=''
    for j in range(1,len(lst)):
        if i not in lst[j]:
            m=0
        else:
            temp = lst[j].replace(i,'',1)
            lst[j] = temp
        
    if m==1:
        chars.append(i)
sort_chars=sorted(chars)
result='"'+"".join(sort_chars)+'"'
print(result)      
    
