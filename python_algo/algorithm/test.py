import numpy as np
from collections import Counter

'''
统计列表中出现的数字并排序
dict.items()返回key-value键值对
sorted(iterable, key=None, reverse=False),利用key排序
'''
def statistics_sort():
    list1=["abcde","abcdef", "hihg","ihins","ihins"]
    d2=Counter(list1)
    sorted_x=sorted(d2.items(), key=lambda x:x[1], reverse=True)
    print(sorted_x)

def test1():
    arr=np.array([-0.76714003, -6.26455537, -9.94975019, 19.69365588, 23.86557445, -24.88972373 , 1.78041987, -8.30508621,  4.44075569,  0.25841457])
    print(np.square(arr))



if __name__ == "__main__":
    statistics_sort()