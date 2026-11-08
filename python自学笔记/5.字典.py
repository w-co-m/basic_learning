#字典
#字典是以键值对的形式存储数据的
#字典以{}来表示:{key:value,key2:value,key3:value}
#基本使用方法

dic={'1+':'zjh','captain':'hlh'}
'''
val=dic['1+']     #把索引换成key
val2=dic['captain']
print(val,val2)
'''
#字典的key必须可哈希（即不可变）
#value可以是任何数据类型


#4.2 字典的增删改查
#字典的增改
'''
dic=dict()
dic['1+']='zjh'
dic['captain']='hlh'
print(dic)
#注意如果key出现重复，那么后一个value将覆盖前一个value
dic['1+']='jiabei'
print(dic)
#另一种增加方式
dic.setdefault('xd','xiandianzikejidaxue')
print(dic)
#这种方式不会覆盖value
dic.setdefault('1+','zjh')
'''
#字典的删除  dic.pop(key)
'''
dic={'1+':'zjh','captain':'hlh'}
dic.pop('1+')
print(dic)
'''
#字典的查询
'''
dic={'1+':'zjh','captain':'hlh'}
print(dic.get('1+'))
print(dic.get('10086+'))
'''
#4.3字典的循环和嵌套
#一.字典的循环
'''
dic={'1+':'zjh','captain':'hlh','pw':'jianyu','tianyouqing':'qingwa','beimen':'banana'}
'''
'''
#1.使用for来获取key
for key in dic:
    print(key,dic[key])
'''

'''
#2.把所有的key或value在一个列表中
print(list(dic.keys()))
print(list(dic.values()))
'''


#直接获取字典中的key和value
for key,value in dic.items():
    print(key)
    print(value)
    print(key,value)


'''
#字典的嵌套
pwld={"qingwa":{"zhiwei":"fuxiaozhang","car":"masld","hobby":"taichi"},
     'xiejun':{'zhiwei':'sb','car':'bsj','goal':{'duanqi':'qubeimenpc','changqi':'maidb'},'looklike':'banana'}}
iz=pwld['xiejun']['goal']['duanqi']
print(iz)
'''

#补充：字典的循环删除不能直接删除，应该先将要删除的放于空列表中（类似于列表的循环删除）



















