import pygame as pg
import tkinter as tk
from tkinter import ttk
import pyautogui as pa
import random as r



#输入所有背景参数
def result_input():
    inputs={}
    win=tk.Toplevel(root)
    win.geometry('600x400')
    win.title('请确定创世参数(未修改则按默认值创建)')
    params=[(0,'是否创建有边界世界(需要则改输入1)','boundary'),
            (0,'辅助网格是否存在(存在则改输入1)','lattice'),
            (40,'细胞大小（普朗克长度）','cell_size'),
            (60,'帧率','f_rate'),
            (16,'长按时重复按键间隔(毫秒)','repeat'),
            (200,'开启连按所需长按时长(毫秒)','delay'),
            (800,'世界长度','wh'),
            (600,'世界宽度','wv')]
    
    for i,(m,labeltext,name) in enumerate(params):
        ttk.Label(win,text=labeltext).grid(row=i,column=0,padx=5,pady=5,sticky='w')

        entry=ttk.Entry(win)
        entry.insert(0,str(m))
        entry.grid(row=i,column=1,padx=5,pady=5)
        inputs[name]=(entry,m)
        
    def confirm():
        global results
        results={}
        for name,(entry,m) in inputs.items():
            n=entry.get().strip()              #去除首尾空格，防误输入,同时转为int
            results[name]=int(n) if n else m
        win.destroy()
    button=ttk.Button(win,text='OK',command=confirm)
    button.grid(row=len(params),column=0,columnspan=2,pady=10)
    while win.winfo_exists():
        root.update()           #更新并处理输入
        root.update_idletasks()         #更新显示
    


#加工除cell分布之外所有背景参数(以继承之前的cell分布,但window范围外外的会丢失)
def process():
    global rows,cols,cells             #不然重新赋值会被认成局部变量
    window=pg.display.set_mode((wh,wv))
    pg.display.set_caption('world1')
    #保存先前数据
    temporary=[]
    for i in range(rows):
        for j in range(cols):
            if cells[i][j]==1:
                temporary.append((i,j))
    #更新数据
    rows=wv//cell_size
    cols=wh//cell_size
    cells=[[0 for _ in range(cols)]for _ in range(rows)]
    for (i,j) in temporary:
        if i<rows and j<cols:
            cells[i][j]=1
        
    pg.key.set_repeat(delay,repeat)             #支持长按

    globals().update(locals())          #全部需全局化，所以在末尾再来一次



#批量精确生成/毁灭cell(如有需求)
def cell_input():
    #输入行
    s=pa.prompt('请输入需改变cell的行号，以" "分隔','行号')
    row_input=list(map(int,s.split(' ')))
    
    #分别输入列并change cell
    inputs={}
    win=tk.Toplevel(root)
    win.title('请输入每行内cell列始末列号的元组(例:(2，4))，以" "分隔各元组')
    t=0
    for t,i in enumerate(row_input):
        ttk.Label(win,text=f'第{str(i)}行:').grid(row=t,column=0,padx=5,pady=5,sticky='w')

        entry=ttk.Entry(win)
        entry.grid(row=t,column=1,padx=5,pady=5)
        inputs[i]=entry

    #解析字符串为元组(输入预处理)
    def parse(s):
        js=tuple(map(int,s.strip('()').split(',')))
        return js
        
    #按ok后数据处理
    def confirm():
        for i,entry in inputs.items():
            jsl=list(map(parse,entry.get().split(' ')))
            for js in jsl:
                for j in range(js[0],js[1]+1):
                    change(i,j)
        win.destroy()
    buttom=ttk.Button(win,text='OK',command=confirm)
    buttom.grid(row=t+1,column=0,columnspan=2,pady=10)

    #设置宽度确定，高度自适应的窗口
    win.update()           #渲染控件
    win.geometry(f'800x{buttom.winfo_y()+buttom.winfo_height()+20}')
    while win.winfo_exists():
        root.update()           #更新并处理输入
        root.update_idletasks()         #更新显示
        
        
    
#画辅助方格（如有需求）  
def drawh():
    for i in range(0,wh,cell_size):
        pg.draw.line(window,'white',(i,0),(i,wv))
def drawv():
    for i in range(0,wv,cell_size):
        pg.draw.line(window,'white',(0,i),(wh,i))



#清空活cell
def empty(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            a[i][j]=0



#数局部活cell数
def counter(n,i,j):
    count=0
    for k in range(i-1,i+2):
        for t in range(j-1,j+2):
            #有界
            if boundary==0:
                if k==-1:
                    k=rows-1
                elif k==rows:
                    k=0
                if t==-1:
                    t=cols-1
                elif t==cols:
                    t=0
                count+=cells[k][t]
            #有限无界
            else:
                if k==-1 or k==rows or t==-1 or t==cols:
                    count+=0
                else:
                    count+=cells[k][t]
    return count

#按b3s23更新cell分布
def cell_update():
    cells2=[[0 for _ in range(cols)]for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            count=counter(cells[i][j],i,j)
            if cells[i][j]==1:
                if count!=3 and count!=4:
                    cells2[i][j]=0
                else:
                    cells2[i][j]=1
            if cells[i][j]==0:
                if count==3:
                    cells2[i][j]=1
                else:
                    cells2[i][j]=0
    for i in range(rows):
        for j in range(cols):
            cells[i][j]=cells2[i][j]
#改变cell状态
def change(i,j):
    if cells[i][j]==0:
        cells[i][j]=1
    else:
        cells[i][j]=0



#画活cell
def draw():
    a=cell_size
    for i in range(rows):
        for j in range(cols):
            if cells[i][j]==1:
                pg.draw.rect(window,'green',(j*a,i*a,a,a))



#指令列表
def instruction():
    win=tk.Toplevel(root)
    win.title('指令列表')
    ins='''***  press'i':显示指令列表(想关闭点'OK')(instructions)  ***\n
           mouseleft:生成/毁灭一个cell\n
           mouseright:修改参数\n
           press'enter':短按:运行一步/长按:连续运行\n
           press'e':清空活cell(empty)\n
           press'm':大量精确生成/毁灭cell(mutiple)\n
           press'r':随机以某一概率在全世界改变cell生死状态(random)'''
    tk.Label(win,text=ins,padx=5,pady=5,justify='left').grid(sticky='w')         #注意，Label里传的是控件内边距
    tk.Button(win,text='OK',command=win.destroy).grid(pady=5)   #接受destroy函数名,但不立刻执行,故无()



pg.init()
root=tk.Tk()            #创建唯一全局主窗口(不然指令列表的主窗口会和其它主窗口冲突)
root.withdraw()

#输入所有参数
result_input()
locals().update(results)

rows=0      #赋初值0以跳过第一次保存数据循环
#加工参数
process()

#准备设定帧率
clock=pg.time.Clock()

#第一次显示指令列表(新手友好)
instruction()

#主循环
Running=True
while Running:
    #处理event
    for ev in pg.event.get():
        #退出
        if ev.type==pg.QUIT:
            Running=False
            break
        #按键盘
        elif ev.type==pg.KEYDOWN:
            if ev.key==pg.K_RETURN:
                cell_update()
            elif ev.key==pg.K_e:
                empty(cells)
            elif ev.key==pg.K_m:
                cell_input()
            elif ev.key==pg.K_r:
                density=pa.prompt('请输入一个(0,1)间的浮点数表示预期密度(改变的cell数占总cell数之比)','密度')
                if density=='':             #防误按
                    pass
                else:
                    for i in range(rows):
                        for j in range(cols):
                            if r.random()<=float(density):
                                change(i,j)
            elif ev.key==pg.K_i:
                instruction()
        #按鼠标
        elif ev.type==pg.MOUSEBUTTONDOWN:
            x,y=pg.mouse.get_pos()
            if ev.button==pg.BUTTON_LEFT:
                i=y//cell_size
                j=x//cell_size
                change(i,j)
                print(f'change a cell at ({x},{y}),cell[{i}][{j}]')
            elif ev.button==pg.BUTTON_RIGHT:
                result_input()
                locals().update(results)
                process()
    root.update()           #更新指令列表窗口显示
    
    #画图
    window.fill((0,0,0))
    if lattice==1:
        drawh()
        drawv()
    draw()

    pg.display.update()
    clock.tick(f_rate)

pg.quit()
