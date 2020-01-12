#include "algo_two.h"
#include "common.h"
#include <iostream>

/*
100元换成不同中的零钱，求换法
*/
/*
暴力法
*/
int coinChange1(int amount)
{
	int m = 0;
	for (int i = 0; i <= amount / 1; i++)
		for (int j = 0; j <= (amount - i * 1) / 2; j++)
			for (int k = 0; k <= (amount - i * 1 - j * 2) / 5; k++)
				for (int l = 0; l <= (amount - i * 1 - j * 2 - k * 5) / 10; l++)
					if (amount == i + j * 2 + k * 5 + l * 10)
					{
						++m;
						cout << "1 yuan:" << i << ",     2 yuan:" << j << ", 5 yuan:" << k << ", 10 yuan:" << l << endl;
					}
	return m;
}

/*
amount: total money
kinds:  the kind of money
分为包含该种与不包含该种：coc(A, [C1, C2…Cn])=coc(A-C1, [C1, C2…Cn]) + coc(A, [C2, C3…Cn]);
*/
int coinExchangeRecursion(int amount, int cashlist[], int n)
{
	if (amount == 0)       //负数
		return 1;
	else if (amount < 0)   // 0元
		return 0;
	// 只有一种钱
	if (n == 1)
	{
		if (amount % cashlist[n - 1] == 0)    //可以整数
			return 1;
		else
			return 0;
	}
	return coinExchangeRecursion(amount, cashlist, n - 1) + coinExchangeRecursion(amount - cashlist[n - 1], cashlist, n);
}

int coinExchangeRecursion2(int n, int m) //递归方式实现，更好理解
{
	if (n == 0)   //跳出递归的条件
		return 1;
	if (n < 0 || m == 0)
		return 0;
	//分为两种情况:换取当前面值的情况 + 没有换取当前面值的情况
	return (coinExchangeRecursion2(n, (m - 1)) + coinExchangeRecursion2(n - dimes[m - 1], m));
}
/*
动态规划方法
dp[i][j]：前i个硬币兑换的钱数为j时的总的组合数
表示选择第i个a[i]与不选择第i个a[i]
dp[i][j]=dp[i-1][j]                 if j<a[i]
dp[i][j]=dp[i-1][j]+dp[i][j-a[i]]   if j>=a[i]
num: total+1
dp[n][total+1]
*/
int coinExchange3(int total, int cashList[], int n, int *dp[], int num)
{
	if (n < 0)
		return 0;
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			if (j >= cashList[i])
				dp[i][j] = dp[i - 1][j] + dp[i][j - cashList[i]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n - 1][num];
}


/*
给定钱x, 硬币（c1,c2..)，如果换使的硬币数最少，或是如果不能兑换成功，return -1
 Write a function to compute the fewest number of coins 
 that you need to make up that amount. If that amount of 
 money cannot be made up by any combination of the coins, return -1.
 dp[i]表示总数为i的最少数目的换钱方法
 思路：从coins中遍历，如果硬币值小于i,则使用dp[i-coins[j]+1,最长使用1元的硬币i种
 dp[i]=min(dp[i],dp[i-coin[j]]+1)    
*/
int coinExchange4(int amount, vector<int> &coins)
{
	if (amount == 0)
		return 0;
	vector<int> dp(amount + 1, amount + 1);  //大小为 amount+1，初始值为 amount+1
	dp[0] = 0;
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j<coins.size(); j++)
			if (coins[j] <= i)
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
	}
	return (dp[amount] > amount) ? -1 : dp[amount];
}