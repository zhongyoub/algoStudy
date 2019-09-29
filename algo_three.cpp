#include "algo_three.h"
#include "common.h"
#include <iostream>
using namespace std;

/*
������ɨ�裬�Ƿ�����ɽ�����ʣ��������,��tempMax++, �����㣬����µ�ǰ�õ�ɽ���ĳ���maxLen, ������һ��
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
			tempUp = i;                            //��¼�±�
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
			tempDown = i;                        //��¼�±�
			//�˳�whileѭ����������a[i]>a[i+1], ��a[i]<=a[i+1]����maxlen
			if (a[i] <= a[i + 1])
			{
				if (tempMax > maxLen)
				{
					maxLen = tempMax;   
					up = tempUp;
					down = tempDown;
				}
			}
			i--;      //�ֲ�for�е�i++
		}
	}
	for (int i = up; i <= down; i++)
		cout << a[i] << "  ";
	cout << endl;
	return maxLen;
}

/*
������ָ�룬��һ����ָ���������ɽ������ڣ���һ����ָ�룬������������ݣ�
�����������ݷ���ɽ����Ҫ����ô��ָ��ͼ��������������ָ�����������ݲ�������ɽ������ѧҪ��
��ô�����ж���ָ��Ϳ�ָ��֮���Ƿ�����һ��ɽ����������㣬����һ������ɽ�����ȺͿ�ָ�����ָ���λ�ã��ټ�������
*/
int getMaxmoutian2(int A[], int n)
{
	if (n < 3)
		return 0;
	int fast = 1, slow = 0, maxLen = 0;
	int tag_less = 0, tag_more = 0;
	while (fast < n) {
		if (tag_less == 0 && tag_more == 0 && A[fast - 1] < A[fast])//����ɽ����ǰ��Σ���ʼɽ��
		{
			fast++;
			tag_less = 1;
		}
		else if (tag_less == 1 && tag_more == 0 && A[fast - 1] < A[fast])
			fast++;
		else if (tag_less == 1 && tag_more == 0 && A[fast - 1] > A[fast])//����ɽ��
		{
			fast++;
			tag_more = 1;
		}
		else if (tag_less == 1 && tag_more == 1 && A[fast - 1] > A[fast])//����ɽ���ĺ���
		{
			fast++;
		}
		else if (tag_less == 1 && tag_more == 1 && A[fast - 1] <= A[fast])//ɽ������
		{
			tag_less = 0;
			tag_more = 0;
			maxLen = max(maxLen, fast - slow);
			slow = fast - 1;
		}
		else {//������ɽ����Ҫ��
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