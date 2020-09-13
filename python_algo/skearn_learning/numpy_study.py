'''
numpy的使用学习
'''

import numpy as np 

def  test1():
    a=np.arange(20).reshape(10,2)
    print(a[:-5,1])     #前五行第一列
    print(a[-5:,1])     #后五行第一列

# np.newaxis扩展维数
def test2():
    b=np.array([1,2,3,4,5,6])
    print(b[np.newaxis])
    c=b[:,np.newaxis]    #c变为6行1列
    print(b.shape)
    print(c.shape)    

def test3():
    x=np.arange(60).reshape(3,4,5)
    print(x)
    print(x[:,1])    #这是一行
    print(x[:,1][:, np.newaxis, 2])  #索引第2列,返回一个矩阵,，这个np.newaxis可以在任何位置
    #将两列拼接
    print(np.hstack([x[:,1][:,np.newaxis],x[:,3][:,np.newaxis]]))

'''
使用numpy的函数创建数组或矩阵
'''
def test4():
    #使用zeros()创建一个填充0的数组
    a=np.zeros((2,4))
    print(a)
    #使用ones()创建一个填充1的数组
    b=np.ones((3,4))
    print(b)
    #使用empty()创建一个数组，初始内容随机
    c=np.empty((2,3))
    print(c)
    #使用full(创建一个给定值的n*n的数组
    d=np.full((3,3),3)
    print(d)
    #使用eye()可是创建对角线为1，其他为0的n*n矩阵
    e=np.eye(3,3)
    print(e)
    #linspace()返回指定范围内的等间隔的数组
    f=np.linspace(0,10,4)
    print(f)
    #随机范围（0，1）
    g=np.random.random((2,2))
    print(g)

'''
numpy的两个扁平化函数ravel(), flatten()
flatten()分配了新的内存，ravel()返回的是数组的视图
扁平化：将矩阵变成数组
'''
def test5():
    a=np.arange(20).reshape(4,5)
    print(a)
    b=a.ravel()
    c=a.flatten()
    print(b)
    print(c)
    b[1]=99   #修改b会导a也修改
    c[1]=111
    print(a)
    print(b)
    print(c)

'''
stack(), hstack(), vstack()
stack(arrays, axis=0):增加维度
hstack(tup):按列顺序将数组堆叠
vstack(tup):按行顺序将数组堆叠
'''
def test6():
    a=np.empty((3,4))
    print("增加一维，新维度的下标为0")
    b=np.stack(a,axis=0)
    print(b)
    print(b.shape)   #2行5列
    print("增加一维，新维度的下标为1")
    c=np.stack(a,axis=1)
    print(c)
    d=np.arange(12).reshape(3,4)
    e=np.stack(d, axis=1)
    print(e)

    print(np.hstack((c,e)))
    print(np.vstack((c,e)))



    

if __name__=='__main__':
    #test1()
    #test2()
    #test3()
    #test4()
    #test5()
    test6()