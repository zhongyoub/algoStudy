#include "algo_one.h"
#include "common.h"
#include <iostream>
using namespace std;


/*
������������кͣ������������
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
���η���⣬������������к�Ҫô������������벿�֣�Ҫô�����������Ұ벿�֣�Ҫô����������벿��
*/
int max_sequence2(int a[], int l, int r)
{
	if (l > r) return 0;
	if (l == r) return a[l];
	int m = (l + r) / 2;

	/*�������ҵ����������������벿��*/
	int lmax = a[m], lsum = 0;
	for (int i = m; i >= l; i--) {
		lsum += a[i];
		if (lsum > lmax)
			lmax = lsum;
	}

	/*�������ҵ���������������Ұ벿��*/
	int rmax = a[m + 1], rsum = 0;
	for (int i = m + 1; i <= r; i++) {
		rsum += a[i];
		if (rsum > rmax)
			rmax = rsum;
	}
	return max3(lmax + rmax, max_sequence2(a, l, m), max_sequence2(a, m + 1, r)); //�����������ֵ
}

/*
��� ���������к�ֻ��������λ��0��n-1��ĳ��λ�ý�β��
(1)dp[i] = max{A[i], dp[i-1]+A[i]}
(2)������ɨ�����У����temp_sum���ӣ���max���£����temp_sum<0���Ժ������û�����ã������һ�������п�ʼ
*/
int max_sequence3(int a[], int n)
{
	/*
	int maxsum, maxhere;
	maxsum = maxhere = a[0];   //��ʼ������a[0]
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
