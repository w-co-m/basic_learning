n=int(input())
lst=[]
for i in range(n):
    lst.append(input())
for i in lst:
    if(len(i)==11):
        print('6'+i[6:])
    else:
        print("Halation - I can't join it!")
