#map()函数的作用
  #对列表或元组或集合中的元素进行历遍操作（避免使用for循环）
#基本语法
  #map(function,iterable)
  #function可以定义函数实现或者结合lambda
'''
def double(x):
    return x*2
lst=[1,2,3]
print(list(map(double,lst)))
print(list(map(lambda x:x*2,lst)))
'''
#map()可以迭代多个对象
'''
arr1=[1,2,3,4]
arr2=[100,200,300,400]
lst=list(map(lambda x,y:x*y,arr1,arr2))
print(lst)
'''


