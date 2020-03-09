/*
将n件无差别的物品分给k个人，求总的分法数并列出每种分法
解：该题可以转化为k个数之和为n,并且需要考虑顺序，其中可以包含0
(1)蛮力法，则需要循环k次，每个循环中需要n次迭代，则时间复杂度为O(n^k)

(2)n=7,k=3,则1,1,5；1,5,1；5,1,1为不同的分法
  1）考虑分的第1份，分的数目不超过n,
  2)从剩下的数n-i中分第2分(递归)，需要分的份数为k-1,分的数目不超过n-i
  3)直到k==1结束

(3)用d[i][j]表示将整数i划分为j份的方案，则
    d[i][j]=d[i][j-1]+d[i-j][1]+d[i-j][2]+d[i-]
*/
#include <iostream>
using namespace std;


#define Max 1000

//得到分法
int departNUmber(int n, int k, int now)
{
    //now表示当前至少从多少开始分，第一个从1开始
    if(k==1)
        return 1;
    else
    {
        int count=0;
        //f(n,k,now)=f(n-1,k-1,1)+f(n-2,k-2,2)+...+f(1,k-1,n)
        for(int i=now;i<n;++i)
            count=count+departNUmber(n-i,k-1,i);
        return count;
    }
}
// n:总数，k:份数，start:从start开始分类，数组condition[max]:存储分类的情况
// index:数组下表，从0开始
int printAllConditions(int n, int k, int start, int condition[Max], int index)
{
    if(k==1)
    {
        condition[index]=n;
        for(int i=0;i<index;i++)
            cout<<condition[i]<<" ";
        cout<<endl;
        return 1;
    }
    else
    {
        int sum=0;
        for(int i=start;i<n;i++)
        {
            condition[index]=i;
            sum=sum+printAllConditions(n-i, k-1, i, condition, index+1);
        }
        return sum;
    }
}

int main()
{
    int n,k;
    int conditions[Max];
    cout<<"请输入总数n和份数k"<<endl;
    cin>>n>>k;
    cout<<departNUmber(n,k,1)<<endl;
    cout<<printAllConditions(n,k,1,conditions,0);
    /*
    int dp[N][K];
    memset(dp,0,sizoef(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<k;j++)
        {
            if(i>=j)
                dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
        }
    }
    cout << "共有" << dp[n][k] << "种分法" << endl;
    */
	return 0;

}