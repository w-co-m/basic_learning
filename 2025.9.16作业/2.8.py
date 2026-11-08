import turtle as t
t.colormode(255)
t.setup(1200,700,350,200)
t.pensize(5)
t.pencolor(190,190,190)
t.penup()
t.fd(-300)
t.seth(90)
t.fd(-300)
t.pd()
length=600
angle=90
while 1:
    for i in range(2):
        t.seth(angle)
        t.fd(length)
        angle-=90
    length-=30
    if length==0:
        break

   
    

