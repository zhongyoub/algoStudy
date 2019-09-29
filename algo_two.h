#pragma once

/*
将100元换成1元，2元，5元，10元,有多少种换法
(1)这是完全背包的变体，递归方法是用当前这种币值换和不用情况下换
*/
const int N = 100;
const int dimes[] = { 1,2,5,10 };   //此处必须是const

/*
amount: total money
kinds:  the kind of money
分为包含该种与不包含该种：coc(A, [C1, C2…Cn])=coc(A-C1, [C1, C2…Cn]) + coc(A, [C2, C3…Cn]);
*/
int coinExchangeRecursion(int amount, int cashlist[], int n);

int coinExchangeRecursion2(int n, int m); //递归方式实现，更好理解

/*
动态规划方法
dp[i][j]：前i个硬币兑换的钱数为j时的总的组合数
表示选择第i个a[i]与不选择第i个a[i]
dp[i][j]=dp[i-1][j]                 if j<a[i]
dp[i][j]=dp[i-1][j]+dp[i][j-a[i]]   if j>=a[i]
num: total+1
dp[n][total+1]
*/
int coinExchange3(int total, int cashList[], int n, int *dp[], int num);


/*
给定钱 x, 硬币（c1,c2..)，如果换使的硬币数最少，或是如果不能兑换成功，return -1
*/