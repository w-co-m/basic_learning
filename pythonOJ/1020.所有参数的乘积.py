#!/usr/bin/python3
def  multi(*x):
    count=1
    u=1
    for i in x:
        try:
            i+=0
            u*=i
            count+=1
        except TypeError:
            return "Invalid arg %d"%count
    return u
print(eval(input()))
