    #初始化
import pygame as pg
pg.init()
import random as ran
#建立窗口
W=1000
H=800
window=pg.display.set_mode((W,H))
pg.display.set_caption('贪吃蛇')
#设置地图
class Point:
    def __init__(self,row=0,col=0):    #构造函数，默认原点为（0,0）
      self.row=row
      self.col=col
def rect(point,color):#定义绘画
    sw=W/COL
    sh=H/ROW
    left=point.col*sw
    top=point.row*sh
    pg.draw.rect(window,color,(left,top,sw,sh))
    pass


    

ROW=40
COL=50
#初始化蛇和食物
head=Point(row=int(ROW/2),col=int(COL/2))
head_color=(0,128,128)
food_color=(255,0,0)
food=Point(row=ran.randint(1,ROW-2),col=ran.randint(1,COL-2))
body=[Point(row=head.row,col=head.col+1),
      Point(row=head.row,col=head.col+2),
      Point(row=head.row,col=head.col+3),
   
       ]
body_color=(0,100,255)                                             

#设置初始方向
direct='left'

#退出窗口
quit=True
while quit:
    #主循环
    #设置退出程序
  
    for event in pg.event.get():
        if event.type==pg.QUIT:
            quit=False
            
        #定义按键作用
        elif  event.type==pg.KEYDOWN:
            
            if event.key==119:
                if direct=='down':
                    pass
                else:
                    direct='up'
            elif  event.key==97:
                if direct=='right':
                    pass
                else:
                   direct='left'
            elif  event.key==115:
                if direct=='up':
                    pass
                else:
                    direct='down'
            elif  event.key==100:
                if direct=='left':
                    pass
                else:
                    direct='right'
    #控制撞墙   
    if head.row==0:
        head.row=ROW
    elif head.row==ROW:
        head.row=0
    if head.col==COL:
        head.col=0
    elif head.col==0:
        head.col=COL
    
    



            
    pg.time.Clock().tick(20)#设置帧率
    #画出来
    pg.draw.rect(window,(255,255,255),(0,0,W,H))#背景
    #画蛇
    rect(head,head_color)
    for i  in body:
        rect(i,body_color)
    #画食物
    rect(food,food_color)
    #吃食物
    eat=(head.row==food.row and head.col==food.col)
    if eat:
        food=Point(row=ran.randint(1,ROW-2),col=ran.randint(1,COL-2))
    #处理蛇身
    body.insert(0, Point(row=head.row,col=head.col))
    if not eat:
        body.pop()
    
    #控制蛇头移动
    if direct=='left':
        head.col-=1
    elif direct=='right':
        head.col+=1
    elif direct=='down':
        head.row+=1
    elif direct=='up':
        head.row-=1

    for j in body:
        if j.row==head.row and j.col==head.col:
            quit=False
   


    pg.display.flip()
 


#退出
pg.quit()

