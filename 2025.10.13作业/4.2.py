str=input()
letter=0
num=0
space=0
other=0
for i in str:
    if i.isalpha():
        letter+=1
    elif i.isdigit():
        num+=1
    elif i==" ":
        space+=1
    else:
        other+=1
print(f'有{letter}个字母,有{num}个数字,有{space}个空格,有{other}个其他')
        
