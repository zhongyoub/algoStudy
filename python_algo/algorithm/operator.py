# /usr/bin/python3
# -*- coding: UTF-8 -*-
'''
将四个相同的数字(n)，按照加减乘除的方式运算，判断是否等于(m)
for example: 1+1+1*1=3
解题思路：使用Python中的eval()函数
'''

def isNumber(str):
    try:
        f=float(str)
        return True
    except ValueError:
        pass
    try:
        import unicodedata
        unicodedata.numeric(str)
        return True
    except (TypeError, ValueError):
        pass
    return False

def operator(n, m):
    flag=0
    if(not isNumber(n) or not isNumber(m)):
        print("please input number")
        return flag
    operator_list=['+','-','*','/']
    result=0
   
    for i in range(4):
        for j in range(4):
            for k in range(4):
                result=eval( str(n) + operator_list[i] + str(n)+ operator_list[j] + str(n) + operator_list[k] + str(n))
                if(result==m):
                    print(str(n)+ operator_list[i] + str(n) + operator_list[j] + str(n) + operator_list[k] + str(n))
                    flag=1
                    break
    return flag          


if __name__=='__main__':
    n=input()
    m=input()
    result=operator(n,m)
    print(result)