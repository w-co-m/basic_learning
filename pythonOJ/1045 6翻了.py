pa=input()
result=[]
count=0
for i in pa:
    if i=='6':
        count+=1
    else:
        if count<=3:
            result.append("6"*count)
        elif count<=9:
            result.append("9")
        elif count>9:
            result.append("27")
        count=0
        result.append(i)
if count<=3:
        result.append("6"*count)
elif count<=9:
        result.append("9")
elif count>9:
        result.append("27")
s="".join(result)
print(s)
