#/usr/bin/python -
#coding:utf-8
'''
给定一个字符串，求它的信息熵
信息熵：某一事件出现的概率乘以它的对数形式的结果，取负数即可，把一个集合中的所有和累加即得到信息熵
返回结果为保留两位小数
'''
import math 

#python2
def compute_entropy(input_str):
    str_list=str(input_str)
    str_len=len(str_list)
    str_single=list(set(str_list))
    num_list=[]
    for i in str_single:
        num_list.append(str_list.count(i))
    list_two=zip(str_single, num_list)
    entropy=0
    for j in range(len(list_two)):
        entropy+=(float(list_two[j][1]/str_len)) * math.log(float(list_two[j][1]/str_len),2)
    entropy=-entropy
    return '%.2'%entropy

#python3
def  compute_entropy2(string):
    str_list=list(string)
    n=len(str_list)
    str_list_single=list(set(str_list))
    num_list=[]
    for i in str_list_single:
        num_list.append(str_list.count(i))
    list_two=zip(str_list_single,num_list)
    entropy=0
    list_two=list(list_two)
    list_two_len=len(list_two)

    for j in range(len(list_two)):
        entropy+=-1*(float(list_two[j][1]/n))*math.log(float(list_two[j][1]/n),2)
    if len(str(entropy).split('.')[-1])>=7:
        return('%.7f' %entropy)
    else:
        return entropy

if __name__=='__main__':
    a='aabbcc'
    print(compute_entropy2(a))