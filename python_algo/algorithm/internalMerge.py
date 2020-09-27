'''
区间合并问题：给出一个区间的集合，请合并所有重叠的区间
for  example:
input:  [[1,3],[2,6],[8,10],[15,18]]
output: [[1,6],[8,10],[15,18]]
explain: 区间 [1,3]和[2,6]重叠，将他们合并为[1,6]
'''

#!/usr/bin/python
#coding:utf-8


'''
按照区间的左端点排序，则在排好序的区间中，可以合并的区间一定是连续的
将列表中的区间按照左端点升序的方式排序，将第一个区间添加到result中，按顺序考察其他的区间：
（1）如果当前区间的左端点在数组result的最后一个区间的右端口之后，则不会重叠，则直接添加到result
（2）否则，重合，则将当前区间和最后区间右端点的较大值，更新为最后区间右端口的值
'''
def merge(internals):
    internals.sort(key=lambda x: x[0])
    result=[]
    result.append(intervals[0])
    intervals.remove(intervals[0])
    for interval in intervals:
        #如果为空，或者有重写，则直接添加
        if not interval or result[-1][1]<interval[0]:
            result.append(interval)
        else:
            #更新result中最后区间的右端点
            result[-1][-1]=max(interval[1],result[-1][-1])
    return result

if __name__ == "__main__":
    intervals=[[1,3],[2,6],[8,10],[15,18]]
    result=merge(intervals)
    print(result)
