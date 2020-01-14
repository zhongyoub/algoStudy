# 进制转换
给定一个数字，转化为任意进制的数字

# 解题
设给定数字n, 设置的base为x,则
<br>
n=(d<sub>m</sub>d<sub>m-1</sub>...d<sub>1</sub>d<sub>0</sub>)<sub>x</sub>
=d<sub>m</sub> * x<sup>m</sup>+ ... +d<sub>1</sub> * x<sup>1</sup> +d<sub>0</sub> * x<sup>0</sup>

若记 n<sub>i</sub>=((d<sub>m</sub>d<sub>m-1</sub>...d<sub>i+1</sub>d<sub>i</sub>)<sub>x</sub>

则 
<br>
d<sub>i</sub>=n<sub>i</sub>%x   &ensp; 末尾数d<sub>i</sub>为除余
<br>
n<sub>i+1</sub>=n<sub>i</sub>/x 
<br>
使用栈存储d<sub>i</sub>,则末尾存在栈的最下面，首部存在最上面，栈输出则为转换后的值

