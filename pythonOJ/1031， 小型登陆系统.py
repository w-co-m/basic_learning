x=0
for i in range(0,3):
    admin=input()
    passward=input()
    if admin=='Pile' and passward=='MAKIKAWAYI':
        x=1
        print('SUCCESS')
        break
if x==0:
    print('FAILED')
