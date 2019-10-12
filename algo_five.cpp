#include "algo_five.h"
#include "common.h"

/*
��1�����л�ȡǰ100�����ֵ
1. ��������Ϊ array[N] (N = 1 ��)����������quicksort��ԭ���array�ֳ��������֣�
��߲��ֱ� array[N - 1] (array�е����һ��ֵ����pivot) ��
�ұ߲��ֱ�pivot С��Ȼ�󣬿��Եõ� array[array.length - 1] (�� pivot) �����������е�λ�ã������� k.
2. ��� k �� 99 ������������[0, k - 1]����ǰ 100 ���ֵ�� �������ݹ飩
3. ��� k �� 99 С�� ����������[k + 1, ..., N ]����ǰ 100 - (k + 1) ���ֵ���������ݹ飩
4. ��� k == 99, ��ô�����ǰ 100 ��ֵһ�������ġ����˳���
*/
int *getFirstHundred(int a[], int start, int end, int k)
{
	int switchPointer = 0;
	int pivot = a[end];  //�ָ��
	for (int i = start; i<=end; i++)
	{
		if (a[i] > pivot)
		{
			swap(a, i, switchPointer);
			switchPointer++;
		}
	}
	swap(a, end, switchPointer);  // ������ array��ߵ�ֵ��pivot��   �ұߵ�ֵ��pivotС
	if (switchPointer < k - 1)
		getFirstHundred(a, switchPointer + 1, end, k);
	else if (switchPointer == k)
		return a;
	else
		getFirstHundred(a, 0, switchPointer - 1, k);

}
