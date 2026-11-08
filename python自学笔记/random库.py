#random 库的使用
import random as r
#一.基础函数
#1.random.seed() 设置种子
'''
r.seed(10)  #固定种子为10（每次输出结果固定）
for i in range(3):
    print(r.random())
r.seed()    #默认使用系统时间
for i in range(3):
    print(r.random())
#可以通过引入time库来以现在时间为种子
'''
#2.random.random() 生成[0.0,1.0)的随机浮点数
'''
print(r.random())
'''
#二.拓展函数
#1.random.randint(a,b)  生成[a,b]的整数
'''
print(r.randint(1,10))
'''
#2.random.randrange(start,stop,step)   生成[start,stop)之间的整数，step为步长
'''
print(r.randrange(10,100,10))
'''
#3.random.uniform(a,b)   生成[a,b]之间的浮点数
'''
print(r.uniform(5,15))
'''
#4.random.choice(seq)    从序列中随机选一个元素
'''
print(r.choice("KOBE"))
'''
#5.random.choices(seq,weights=None/cum_weight=None,k)  从序列中抽取k个允许重复元素
'''
print(r.choices(['wkw','dnw','zuiqiangde'],weights=[1,2,1],k=2))       #权重控制
print(r.choices(['wkw','dnw','zuiqiangde'],cum_weights=[1,3,4],k=2))   #累计权重
#上述两种等效
#没有weights=None/cum_weight=None即权重相同
'''
#6.random.sample(population,k)   从序列中抽取k个不重复元素
'''
print(r.sample(['wkw','dnw','zuiqiangde'],k=2))
'''
#7.random.shuffle(seq)   打乱可变序列（列表）
'''
lst=[1,2,3,4,5,6,7,8]
r.shuffle(lst)
print(lst)
'''
#三.特殊分布函数
#1.random.normalvariate(mu,sigema)
'''
print(r.normalvariate(0,1))
'''
#四.实例
'''
num=int(input())
seed=int(input())
r.seed(seed)
hits=0
for i in range(num):
    x,y=r.random(),r.random()
    square=pow(pow(x,2)+pow(y,2),0.5)
    if square<=1.0:
        hits+=1
pi=4*hits/num
print(f"圆周率是{pi:.6f}")
'''









