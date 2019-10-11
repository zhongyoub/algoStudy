#include "algo_one.h"
#include "common.h"
#include <iostream>
using namespace std;


/*
最大连续子序列和，并输出子序列
*/
int max_sequence(int arr[], int n)
{
	int max = arr[0];
	int m1 = 0, m2 = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			if (sum > max)
			{
				max = sum;
				m1 = i;
				m2 = j;
			}
		}
	}
	for (int k = m1; k <= m2; k++)
		cout << arr[k] << " ";
	cout << endl;
	return max;
}


/*
分治法求解，最大连续子序列和要么出现在数组左半部分，要么出现在数组右半部分，要么横跨左右两半部分
*/
int max_sequence2(int a[], int l, int r)
{
	if (l > r) return 0;
	if (l == r) return a[l];
	int m = (l + r) / 2;

	/*求横跨左右的最大连续子序列左半部分*/
	int lmax = a[m], lsum = 0;
	for (int i = m; i >= l; i--) {
		lsum += a[i];
		if (lsum > lmax)
			lmax = lsum;
	}

	/*求横跨左右的最大连续子序列右半部分*/
	int rmax = a[m + 1], rsum = 0;
	for (int i = m + 1; i <= r; i++) {
		rsum += a[i];
		if (rsum > rmax)
			rmax = rsum;
	}
	return max3(lmax + rmax, max_sequence2(a, l, m), max_sequence2(a, m + 1, r)); //返回三者最大值
}

/*
最大 连续子序列和只可能是以位置0～n-1中某个位置结尾。
(1)dp[i] = max{A[i], dp[i-1]+A[i]}
(2)从左到右扫描序列，如果temp_sum增加，则max更新，如果temp_sum<0，对后面求和没有作用，则从下一个子序列开始
*/
int max_sequence3(int a[], int n)
{
	/*
	int maxsum, maxhere;
	maxsum = maxhere = a[0];   //初始化最大和a[0]
	for (int i = 1; i < n; i++)
	{
		if (maxhere <= 0)
			maxhere = a[i];
		else
			maxhere += a[i];
		if (maxhere > maxsum)
			maxsum = maxhere;
	}
	return maxsum;
	*/
	int max = 0, temp_sum = 0;
	for (int i = 0; i < n; i++)
	{
		temp_sum += a[i];
		if (temp_sum > max)
			max = temp_sum;
		else if (temp_sum < 0)
			temp_sum = 0;
	}
	return max;
}
