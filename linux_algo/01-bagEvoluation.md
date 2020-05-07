# 0-背包问题

问题描述：有N件物品和一个容量为C的包，第i件物品的重量为 w<sub>i</sub>,价值 v<sub>i</sub>，选择若干个物品装入包中，使的价值最高。

该问题存在多种变形:

* 如给定N个数，取若干个数，它们的和最接近M

* 捕鱼问题:20个桶，每个桶有10条鱼，用从同种捕鱼，捕的数量随机，且只能捕依次，则一共抓到180条鱼有多少种可能。


## 第一个问题——0-1背包问题
### 使用二维数组解
  该问题更抽象的概括为：
  给定正整数{(W<sub>i</sub>, v<sub>i</sub>)}<sub>1$\leq$i$\leq$n</sub>，给定正整数C,求解0-1规划问题:

  max $\sum_{i=0}^n$ x<sub>i</sub>v<sub>i</sub>
  <br>
 s.t. $\sum_{i}^n$ x<sub>i</sub>w<sub>i</sub> $\leq$ C, x<sub>i</sub> {0, 1}

 0-1背包问题的递推关系

P(i, W):在前i个物品中挑选总重量不超过W的物品，每种物品最多选个一个，是的总价值最大，这时的总价值记作m(i, W), 其中 1 $\leq$ i $\leq$ n

第i个物品，无外乎两种可能，选与不选。
* 不选，背包容量不变，该问题变为P(i-1,W)
* 选，背包容量变小，问题为P(i-1,W-w<sub>i</sub>)

最终则是比较这两种方案：
P(i, W)=max{m(i-1,W),m(i-1,W-w<sub>i</sub>)+v<sub>i</sub>}

$$m(i,W)=\left\{
    \begin{aligned}
    0 &&if && i=0\\
    0 &&if && W=0  \\
    max&& \{ m(i-1, W), m(i-1, W-w_{i})+v_{i}\}
    \end{aligned}
    \right.
    $$
所以编写代码时，需要定义m(0,W)， m(i,0) 
<br>
for i=1 to n <br>
&nbsp; for w=1 to C <br>
&nbsp; &nbsp; if $w_{i}$ > W <br>
&nbsp; &nbsp; &nbsp; &nbsp; m[i,W]=m[i-1,W] <br>
&nbsp; &nbsp; else   <br>
&nbsp; &nbsp;&nbsp; m[i,W]=max{m[i-1,W], $v_{i}$+m[i-1,W-$w_{i}$} <br>
return m[n, C]
<br>

### 使用一维数组解




## 第二个问题
给定N个数，取若干个数，和最接近M。 可以将M看为背包的容量,每单位重量对应每单位价值 <br>


m(i, M)记作在前i个数取得和不超过M。 <br>
考虑第i个数，分为两种情况，取与不取 <br>

* 不取，则容量不变,则为m(i-1,M) 
* 取，则容量变小，为m(i-1,M-$w_{i}$)
此时该问题同背包问题一样

## 第三个问题
分析：该问题是在20个桶中抓取180条鱼，每个桶能抓到鱼的条数为0-10。<br>

可以将该问题分别成子问题：假设在前i个桶中抓了k条鱼，那么在剩余20-i个桶中抓取180-k条。
<br>
该问题的对偶问题是抓取180条后，剩余20条分布在20个桶中，有几种分法，其中每个桶中最多放10条，最少0条。
<br>
* 最直接的方法是使用递归，为防止重复计算，一般设置一个备忘录。如果桶没了，鱼还有，则不符合要求返回0，如果桶有，鱼没了，也不符合要求，返回0

int  dp[21][21] //记录

int allocate(int bucketN, fishN) <br>
{                    
&nbsp;    if(bucketN==0 && fishN==0) <br>
&nbsp; &nbsp; &nbsp;        return 1;             
&nbsp;    if(bucketN<0 || fishN<0)   <br>
&nbsp; &nbsp; &nbsp;        return 0; <br>
&nbsp;    if(dp[bucketN][fishN]==0)  <br>
    {                                <br>
&nbsp; &nbsp; &nbsp;        for(int i=0;i<10;i++)  <br>
 &nbsp; &nbsp; &nbsp; &nbsp;           dp[bucketN][fishN]+=allocate(bucketN-i, fishN-i); <br>
    }  <br>
&nbsp;    return dp[bucketN][fishN]   <br>
}

* 该问题是DP，也可以使用非递归的方法实现。
<br>
定义dp[i][j]为前i个桶取j条鱼，一个桶装0-10条鱼是合法的<br>
dp[i][j]有11中情况：前i-1个桶取j-k(0 $\leq$ k $\leq$ 10)条的总和。<br>

f(i,j) = sum(f(i-1,j-k), 0 $\leq$ k $\leq$ 10)

