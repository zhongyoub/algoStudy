#include <iostream>
using namespace std;

/*
将n件无差别的物品分给k个人，求总的分法数并列出每种分法
解：k个数之和为n
dp[i][j]表示将整数i划分为j分的方案
*/
#define N 100000
#define K 10000

int main()
{
    int n,k;
    cout<<"please input the total number and the count of people";
    cin>>n>>k;
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
	return 0;

}