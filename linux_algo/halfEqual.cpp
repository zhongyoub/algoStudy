/*
给定一个数组
1. 是否存在将数组分层两部分，两个部分的和相同,不存在返回0
2. 如果两部分不同，和的差最小是多少
*/

/*
这个类似求解数组的一个子集，是的这个子集的元素和尽可能接近sum/2,类似0-1b背包问题
设dp[i][j]表示在前i个元素中，总和最接j的所有物品的总和，包括两种情况：
（1）第i个元素没有包含在其中， dp[i][j]=dp[i-1][j]
（2）第i个元素包含在其中, dp[i][j]=dp[i-1][j-vec[i]]+vec[i] (j>vec[i])
dp[i][j]=max(dp[i-1][j], dp[i-1][j-vec[i]]+vec[i])
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int diff(vector<int> & vec)
{
    int sum=0;
    int len=vec.size();
    for(int i=0;i<len;i++)
        sum+=vec[i];
    if(sum%2)
        return 0;

    // 初始化dp[0][0], dp[1][0]....dp[len][0]
    vector<vector<int>> dp;
    for(int i=0;i<=len;i++)
    {
        vector<int> tmp;
        for(int j=0;j<=sum/2;j++)
            tmp.push_back(0)
        dp.push_back(tmp);
    }   
    for(int i=1;i<=len;i++)
        for(int j=0;j<=sum/2;j++)
            if(j>=vec[i-1])
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-vec[i-1]]+vec[i-1]);
            else dp[i][j] = dp[i - 1][j];
    return sum-2*dp[len][sum/2];
}

//使用二位数组
int diff2(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int half=sum/2;
    int dp[n+1][half+1];
    for(int i=0;i<half+1;i++)
        dp[i][0]=0;
    for(int i=0;i<n+1;i++)
        dp[0][i]=0;
    for(int i=1; i<n+1;i++)
        for(int j=0; j<half+1;j++)
        {
            if(j>=arr[i])
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-arr[i-1]]+arr[i-1])
            else 
                dp[i][j]=dp[i-1][j];
        }
    return sum-2*dp[n][half];
}

int main()
{
    vector<int> vec = { 1,2,3 ,4,5};
 
    cout << diff(vec) << endl;
    return 0;
}