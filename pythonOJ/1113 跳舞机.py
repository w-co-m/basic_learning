def get_grade(flag):
    global grade
    if flag==1:
        grade+=20
    elif flag==0 and grade>0:
        grade-=10

check=input()
my=input()
grade=0
for i in range(0,len(check)):
    if check[i]==my[i]:
        flag=1
    else:
        flag=0
    get_grade(flag)
print(grade)