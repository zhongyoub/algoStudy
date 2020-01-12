#include "algo_five.h"
#include "common.h"

/*
在1亿数中获取前100个最大值
1. 假设数组为 array[N] (N = 1 亿)，首先利用quicksort的原理把array分成两个部分，
左边部分比 array[N - 1] (array中的最后一个值，即pivot) 大，
右边部分比pivot 小。然后，可以得到 array[array.length - 1] (即 pivot) 在整个数组中的位置，假设是 k.
2. 如果 k 比 99 大，我们在数组[0, k - 1]里找前 100 最大值。 （继续递归）
3. 如果 k 比 99 小， 我们在数组[k + 1, ..., N ]里找前 100 - (k + 1) 最大值。（继续递归）
4. 如果 k == 99, 那么数组的前 100 个值一定是最大的。（退出）
*/
int *getFirstHundred(int a[], int start, int end, int k)
{
	int switchPointer = 0;
	int pivot = a[end];  //分割点
	for (int i = start; i<=end; i++)
	{
		if (a[i] > pivot)
		{
			swap(a, i, switchPointer);
			switchPointer++;
		}
	}
	swap(a, end, switchPointer);  // 交换后 array左边的值比pivot大   右边的值比pivot小
	if (switchPointer < k - 1)
		getFirstHundred(a, switchPointer + 1, end, k);
	else if (switchPointer == k)
		return a;
	else
		getFirstHundred(a, 0, switchPointer - 1, k);

}
