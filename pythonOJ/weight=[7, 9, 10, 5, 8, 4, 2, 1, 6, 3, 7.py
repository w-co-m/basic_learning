weight=[7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
check=['1','0','X','9','8','7','6','5','4','3','2']
n=int(input())
result=[]
for i in range(n):
    sen=input()
    total=0
    for j in range(17):
        flag=1
        if  '0'<=sen[j]<='9':
            total+=int(sen[j])*weight[j]
        else:
            result.append(sen)
            flag=0
            break
    if flag:
        total%=11
        check_code=check[total]
        if check_code != sen[-1]:
            result.append(sen)
if not result:
    print("All passed")
else:
    for i in result:
        print(i)
