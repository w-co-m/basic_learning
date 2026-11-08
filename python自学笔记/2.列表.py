#列表
#在python中用[]来表示列表，元素用,隔开
#1.列表中也有索引和切片（类似字符串）
#2.可以用for循坏遍历
'''
lst=['jaky','zjh','yijiaQleite','jiabei']
for item in lst:
    print(item)
'''
#3.可以用len()获得列表的长度
#===================================
#4.列表的增删改查
#4.1列表的增加
'''
                               #append()追加
lst=[]
lst.append('jaky')
lst.append('zjh')
lst.append('jiabei')
print(lst)
                                #insert()插入
lst.insert(0,'yijiaQleite')
lst.insert(2,'wxd')
print(lst)
                             #extend()合并列表
lst.extend(['zc','马也','弓长'])
print(lst)
'''
#4.2列表的删减
'''
                          #pop()删除给出索引的对应元素，并返回该元素
lst=['wkw','大脑王','mc','brainking']
ret=lst.pop(-1)
print(lst)
print(ret)
                         #remove()直接删除某个元素
lst.remove('wkw')
print(lst)
'''
#4.3修改与查询列表
'''
lst=['wkw','大脑王','mc','brainking']
lst[2]='数学天才'   #直接用索引进行修改
print(lst)
print(lst[3])        #直接用索引进行查询
'''
#列表的排序
'''
lst=[11,23,455,566,3254,523,533,21,0]
lst.sort()  #升序排序
print(lst)
lst.sort(reverse=True)  #降序排序
print(lst)
'''



























