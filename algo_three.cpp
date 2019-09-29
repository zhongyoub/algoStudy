#include "algo_three.h"
#include "common.h"
#include <iostream>
using namespace std;

/*
从左到右扫描，是否满足山脉性质，如果满足,则tempMax++, 不满足，则更新当前得到山脉的长度maxLen, 继续下一个
*/
int getMaxMoutain(int a[], int n)
{
	if (n < 3)
		return 0;
	int maxLen = 0;
	int up = 0, down = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int tempMax = 1;
		int tempUp = 0, tempDown = 0;
		if (a[i] < a[i + 1])
		{
			tempUp = i;                            //记录下标
			while (i < n - 1 && a[i] < a[i + 1])
			{
				i++;
				tempMax++;
			}
			while (i<n - 1 && a[i]>a[i + 1])
			{
				i++;
				tempMax++;
			}
			tempDown = i;                        //记录下标
			//退出while循环，不满足a[i]>a[i+1], 即a[i]<=a[i+1]更新maxlen
			if (a[i] <= a[i + 1])
			{
				if (tempMax > maxLen)
				{
					maxLen = tempMax;   
					up = tempUp;
					down = tempDown;
				}
			}
			i--;      //弥补for中的i++
		}
	}
	for (int i = up; i <= down; i++)
		cout << a[i] << "  ";
	cout << endl;
	return maxLen;
}

/*
用两个指针，用一个慢指针用来标记山脉的入口，用一个快指针，遍历后面的数据，
如果后面的数据符合山脉的要求，那么快指针就继续遍历，如果快指针遇到的数据不再满足山脉的数学要求，
那么首先判断慢指针和快指针之间是否满足一个山脉，如果满足，更新一下最大的山脉长度和快指针和慢指针的位置，再继续遍历
*/
int getMaxmoutian2(int A[], int n)
{
	if (n < 3)
		return 0;
	int fast = 1, slow = 0, maxLen = 0;
	int tag_less = 0, tag_more = 0;
	while (fast < n) {
		if (tag_less == 0 && tag_more == 0 && A[fast - 1] < A[fast])//处于山脉的前半段，开始山脉
		{
			fast++;
			tag_less = 1;
		}
		else if (tag_less == 1 && tag_more == 0 && A[fast - 1] < A[fast])
			fast++;
		else if (tag_less == 1 && tag_more == 0 && A[fast - 1] > A[fast])//遇到山峰
		{
			fast++;
			tag_more = 1;
		}
		else if (tag_less == 1 && tag_more == 1 && A[fast - 1] > A[fast])//遇到山脉的后半段
		{
			fast++;
		}
		else if (tag_less == 1 && tag_more == 1 && A[fast - 1] <= A[fast])//山脉结束
		{
			tag_less = 0;
			tag_more = 0;
			maxLen = max(maxLen, fast - slow);
			slow = fast - 1;
		}
		else {//不符合山脉的要求
			tag_less = 0;
			tag_more = 0;
			slow = fast;
			fast++;
		}
	}

	if (tag_less == 1 && tag_more == 1)
		maxLen = max(maxLen, fast - slow);
	return maxLen;
}