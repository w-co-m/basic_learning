#try...except...语句
#基本语法：
'''
try:
    #可能有异常的代码
except ValueError#或者其他Error类型:
    #出现对应异常执行的代码
#可以有多个exceppt
else:
    #没有异常时执行的代码
finally:
    #无论是否发生异常都会执行 
'''

'''
try:
    a=int(input())
    b=int(input())
    result=a/b
    print(result)
except Exception as e:#用于打印异常
    print("发生异常：",e)
'''


