'''
使用最小二乘法拟合数据
使用多项式拟合目标函数 y=sin(2*np.pi*x)
'''
import numpy as np
import scipy as sp
from scipy.optimize import leastsq
import matplotlib.pyplot as plt 


# 目标函数
def real_func(x):
    return np.sin(2*np.pi*x)

    
#多项式函数
def fit_func(p,x):
    '''
    `poly1d([1, 2, 3])` returns an object that represents  
    :math:`x^2 + 2x + 3`, whereas `poly1d([1, 2, 3], True)` returns  
    one that represents :math:`(x-1)(x-2)(x-3) = x^3 - 6x^2 + 11x -6`  
    '''
    f=np.poly1d(p)  
    return f(x)

#残差
def residuals_func(p,x,y):
    ret=fit_func(p,x)-y
    #print('ret:',ret)
    return ret

x=np.linspace(0,1,10)
x_points=np.linspace(0,1,1000)
y_=real_func(x)

#加上正太分布噪音
y=[np.random.normal(0, 0.1)+y1 for y1 in y_ ]

#拟合,M为多项式的次数
def  fitting(M=0):
    #随机初始化多项式次数
    p_init=np.random.rand(M+1)
    #最小二乘法
    p_lsq=leastsq(residuals_func,p_init,args=(x,y))
    print('Fitting Parameters:',p_lsq[0])

    #可视化
    plt.plot(x_points, real_func(x_points),label='real')
    plt.plot(x_points, fit_func(p_lsq[0], x_points), label='fit')
    plt.plot(x, y, 'bo', label='noise')
    plt.legend()
    plt.show()
    return p_lsq

#M=0
p_lsq=fitting(M=9)


#M=9时，出现过拟合，添加正则化项，使用L2范数正则化 0.5 * regularization * w^2
regularization=0.001
def residuals_func_regularization(p, x, y):
    ret=fit_func(p,x)-y
    #print('before:',ret)
    #ret=ret**2+0.5* regularization * np.square(p)
    #ret=np.append(ret, np.sqrt(0.5* regularization * np.square(p)))
    #print("p:",p)
    #print('w:',0.5* regularization * np.square(p))
    ret=np.sqrt(ret**2+0.5* regularization * np.square(p))
    #print('after:',ret)
    return ret 

'''
def leastsq(func, x0, args=(), Dfun=None, full_output=0, col_deriv=0, ftol=1.49012e-8, xtol=1.49012e-8, gtol=0.0, maxfev=0, epsfcn=None, factor=100, diag=None)
Minimize the sum of squares of a set of equations.

    x = arg min(sum(func(y)**2,axis=0)) 
    函数中已经是平方和最小，所以func() 
'''

p_init=np.random.rand(9+1);
print('p_init:',p_init)
p_lsq_regularization=leastsq(residuals_func_regularization, p_init, args=(x,y))
plt.plot(x_points, real_func(x_points), label='real')
plt.plot(x_points, fit_func(p_lsq[0], x_points), label='fitted curve')
plt.plot(
    x_points,
    fit_func(p_lsq_regularization[0], x_points),
    label='regularization')
plt.plot(x, y, 'bo', label='noise')
plt.legend()
plt.show()







    
