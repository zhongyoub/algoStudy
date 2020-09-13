#!/usr/bin/python
# -*- coding: UTF-8 -*-

import numpy as np

def obj_function(x):
    return x[0]*x[1] + x[1]*(x[2]**3) + x[2] + x[3]**3 + 2*x[1] + x[2]**3 + 8*x[3] + x[3]**6 - 12

def loss(x):
    return (obj_function(x)-0)**2

def gradient_descense(x):
    alpha = 0.000000001
    # 梯度矢量
    gradients = np.zeros(x.shape) 
    # 逐个求取偏导数，放进梯度矢量
    for i in range(len(gradients)): 
        #初始化梯度步长向量
        delta_vector = np.zeros(x.shape)
        delta_vector[i] = alpha
        gradients[i] = (loss(x+delta_vector)-loss(x-delta_vector)) / (alpha*2)
    step = 0.001
    x = x - gradient * step
    return x

x = np.array([0.0, 0.0, 0.0, 0.0])
for i in range(50):
    x = gradient_descense(x)
    print ('x = {}, obj_function(x) = {:6f}'.format(x,obj_function(x)))
