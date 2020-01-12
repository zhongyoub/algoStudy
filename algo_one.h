#pragma once

/*
最大连续子序列和，并输出子序列
*/
int max_sequence(int arr[], int n);

/*求三个数最大值*/
int max3(int i, int j, int k);
/*
分治法求解，最大连续子序列和要么出现在数组左半部分，要么出现在数组右半部分，要么横跨左右两半部分
*/
int max_sequence2(int a[], int l, int r);

/*
最大 连续子序列和只可能是以位置0～n-1中某个位置结尾。
(1)dp[i] = max{A[i], dp[i-1]+A[i]}
(2)从左到右扫描序列，如果temp_sum增加，则max更新，如果temp_sum<0，对后面求和没有作用，则从下一个子序列开始
*/
int max_sequence3(int a[], int n);