col,char=input().split(" ")
col=int(col)
if col%2==1:
    row=int(col/2)+1
else:
    row=int(col/2)
for i in range(row):
    print(char*col)
