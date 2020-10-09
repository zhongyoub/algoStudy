
#!/usr/bin/python
#coding:utf-8
'''
蒙特卡洛算法：一种以概率统计理论为指导的一类方法，使用随机数来解决计算问题的方法
'''
from random import *
from math import *

#计算圆周率PI 

def count_pi(times):
    counts=0 
    for i in range(times):
        x=uniform(-1,1)
        y=uniform(-1,1)
        if(x*x+y*y<=1):
            counts+=1 
    pi=counts*4.0/times
    print(pi)


if __name__=='__main__':
    count_pi(100000)