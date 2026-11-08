import random
name=input("请输入名字：")
lucky=1
random.seed(7)
for c in name:
    lucky+=ord(c)*random.randint(1,77)
print("幸运数字是:{}".format(lucky%777))
