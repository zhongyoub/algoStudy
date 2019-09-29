#include "algo_three.h"
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
			tempUp = i;
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
		cout << a[i] << " ";
	cout << endl;
}


int getMaxmoutian2(int a[], int n)
{
	return 0;
}