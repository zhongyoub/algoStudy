# 问题

给一数组，计算最少经过多少次转换可以转换为波动数组，波动数组定义：V<sub>n</sub><min(V<sub>n-1</sub>,V<sub>n+1</sub>)或V<sub>n/</sub>>max(V<sub>n-1</sub>,V<sub>n+1<sub>)，
转换含义为两数对调
例：1,2,3,4,5,6,7 经过2次
1,7,3,4,5,6,2
1,7,3,5,4,6,2
 
1. ：给数组，输出任一转换后的波动数组；
2. ：给数组，输出最少转换次数及转换后的波动数组。


   

## 解题思路
1. 这个实际是让数组呈现波峰波谷的方式排列，有两种：
   1. 大小大小...排列
   2. 小大小大...排列
   <br>
   
   刚开始 data[0], 然后判断data[0]和data[1]的大小，如果data[0]<data[1],则满足。不用交换，如果data[1]<data[2],则需要交换。因为data[2]>data[1]>data[0],所以此时data[2]位于波峰。
   ![avatar](data:image/jpeg;base64,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)
   此时可以看到，数组中奇序号的数在波谷，偶序号的数在波峰，因此需要考虑序号奇偶的情况下和前一个数字进行比较
   
2. 