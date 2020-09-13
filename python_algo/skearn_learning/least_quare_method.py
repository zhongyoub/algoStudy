'''
最小二乘法多项式曲线拟合
X^*X*A=X*Y,求A
[ 1 x1 x1^2 x1^3 .... x1^k
  1 x2 x2^2 x2^3 .... x2^k
 
  1 xn xn^2 xn^3 .... xn^k
]
'''

import matplotlib.pyplot as plt 
import math 
import numpy 
import random 

fig=plt.figure()
ax=fig.add_subplot(111)


def matrixMul(A, B):
    if len(A[0]) == len(B):
        res = [[0] * len(B[0]) for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(B[0])):
                for k in range(len(B)):
                    res[i][j] += A[i][k] * B[k][j]
        return res
    return ('输入矩阵有误！')

#阶数为9
order=9

#生产曲线上各个点
x=numpy.arange(-1,1,0.02)
y=[((a*a-1)*(a*a-1)*(a*a-1)+0.5)*numpy.sin(a*2) for a in x]

#生成的曲线上的各个点偏移一下，并放入到xa,ya中去
i=0
xa=[]
ya=[]
for xx in x:
	yy=y[i]
	d=float(random.randint(60,140))/100
	#ax.plot([xx*d],[yy*d],color='m',linestyle='',marker='.')
	i+=1
	xa.append(xx*d)
	ya.append(yy*d)
 
'''
for i in range(0,5):
	xx=float(random.randint(-100,100))/100
	yy=float(random.randint(-60,60))/100
	xa.append(xx)
	ya.append(yy)
'''
 
ax.plot(xa,ya,color='m',linestyle='',marker='.')

#进行曲线拟合
'''
矩阵相乘 X^T * X
'''
matA=[]
for i in range(0,order+1):   # X^T 的行数
    matA1=[]
    for j in range(0,order+1):  # X 的列数
        tx=0.0
        for k in range(0, len(xa)):   
            dx=1.0 
            for l in range(0,j+i):
                dx=dx*xa[k]
            tx+=dx
        matA1.append(tx)
    matA.append(matA1)
#print(len(xa))
#print(matA[0][0])
matA=numpy.array(matA)


'''
x=numpy.ones(order)
maxA=[]
for i in x:
    maxA.append(i)
for j in xa:
    maxA.append(j)
print(numpy.array(maxA).reshape(order, order+1))
'''

'''
X^T * Y
'''
matB=[]
for i in range(0,order+1):
	ty=0.0
	for k in range(0,len(xa)):
		dy=1.0
		for l in range(0,i):
			dy=dy*xa[k]
		ty+=ya[k]*dy
	matB.append(ty)
 
matB=numpy.array(matB)


'''
AX=b，求解矩阵方程
'''
matAA=numpy.linalg.solve(matA,matB)
 
#画出拟合后的曲线
#print(matAA)
xxa= numpy.arange(-1,1.06,0.01)
yya=[]
for i in range(0,len(xxa)):
	yy=0.0
	for j in range(0,order+1):
		dy=1.0
		for k in range(0,j):
			dy*=xxa[i]
		dy*=matAA[j]
		yy+=dy
	yya.append(yy)
ax.plot(xxa,yya,color='g',linestyle='-',marker='')
 
ax.legend()
plt.show()
