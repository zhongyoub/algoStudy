#include "common.h"
#include <iostream>
using namespace std;

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

/*
求两个数的小者
*/
int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

/*求三个数最大值*/
int max3(int i, int j, int k)
{
	if (i >= j && i >= k)
		return i;
	return max3(j, k, i);
}

/*
实现两个矩阵相乘
矩阵a的行数M，列数N, B的列数K
*/
void maxtrixMultiply(int *a[],  int *b[])
{
	float matrix[M][K];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			matrix[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				matrix[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int m = 0; m < M; m++) {
		for (int s = 0; s < K; s++) {
			cout << matrix[m][s] << "\t";
		}
		cout << endl;
	}
}

/*
交换两个变量
*/
void swap(int a[], int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}