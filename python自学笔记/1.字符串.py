#1.字符串的格式化
#%s 字符串占位（万能）   %d 整数占位  %f 小数占位 后加%（……，……，）
#{}占位    后加  .format(  ,   ,   ,  ,)
#f-string   在字符串前加f后直接在{}中加变量名
'''
name="maba"
print(f"{name},out")
'''
#=====================================================================
#2.索引和切片
#索引—按照位置提取元素
#  变量名[元素序号]  #第一位记作0  #负数代表倒数第几位（-1就是倒数第一位）
#切片—从一个字符串中提取一部分内容
#  变量名[元素索引1：元素索引2]  #切片取不到end #start为开头/end为结尾 可以省略
#[   :   :   ]第二个：后表示步长，步长为负则倒着切
#语法：变量[start:end:step]
'''
news="科比的直升机坠毁"
print(news[0])
print(news[2:6])
print(news[:6])
print(news[3:])
print(news[::-1])
print(news[::2])
'''
#=========================================================================
#3.字符串的常规操作
#字符串的操作一般不会对原字符串产生影响，一般会返回一个新的字符串

#3.1字符串的大小写转化
#eg
'''
s="python"
s1=s.capitalize()
print(s1)
'''
#首字母大写
'''
s="i have a dream"
s1=s.title()
print(s1)
'''
#所有字母变成小写字母
'''
s="MAN WHAT CAN I SAY"
s1=s.lower()
print(s1)
'''
#所有字母变成大写(可用于忽略大小写)
'''
s="man what can i say"
s1=s.upper()
print(s1)
'''
#==============================================
#3.2替换与切割（*）
#strip()
#其前后空白符（空格，/t,/n）
'''
s="    my name is maba   "
print(s)
s1=s.strip()
print(s1)
'''
#字符串的替换  replace(old,new)
'''
s="my name is maba"
s1=s.replace("maba","冰红茶")
print(s)
print(s1)
'''
#运用：去空格(爬虫去空格)
'''
s="man what can i say"
s1=s.replace(" ","")
print(s)
print(s1)
'''
#字符串切割 split(用什么切割)（用什么切，就会损失掉什么）（切割后的结果会放在列表里）
'''
a="python_java_c_c#_kobe"
list1=a.split("_")
list2=a.split("_java_")
print(list1)
print(list2)
'''
#重点：replace()  split()   strip()
#==========================================================
#3.3查找与判断
#查找
#find与index查找
'''
s="man what can i say man"
s1=s.find("man")   #结果数字是几说明在第几位出现  只找第一次出现
s2=s.find("say")
s3=s.find("kobe")  #若结果为-1则没有出现
s4=s.index("say")
print(s1)
print(s2)
print(s3)
print(s4)
s5+s.index("kobe") #没有就报错
'''
#in查找 （in的第二种用法）
'''
k="helicopter down kobe up"  #输出True or False
print("kobe" in k)
print("kobe" not in k)
print("maba" in k)
print("maba" not in k)
'''
#判断
#判断开头结尾(.startswith()   .endswith())
'''
name=input("请输入你的名字：")
if name.startswith("张"):
    print(1)
else:
    print(0)
'''
#判断字符串是否由整数组成
'''
money=input("请输入你的余额：")
if money.isdigit():
    print(1)
else:
    print(0)
'''
#=============================================
#3.4补充与总结
'''
s="hello"      #len()计算长度
print(len(s))   
'''
#列表变字符串
'''
lst=['kobe','maba','牢大']
s="_".join(lst)
s1="".join(lst)
print(s)
print(s1)
'''
#总结
'''
1.f"{   变量    }"  格式化字符串
2.切片与索引
  索引：从零开始[]
  切片：s[start:end:step]
3.相关操作
  upper() 忽略大小写
  strip() 去掉字符串左右两端的空白
  replace() 字符串的替换
  split()  对字符串进行切割
  join()   拼接一个列表中的内容
  startswith() endswith()
  len()
  isdigit()
  '''












