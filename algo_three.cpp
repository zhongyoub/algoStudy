#include "algo_three.h"
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
		cout << a[i] << " ";
	cout << endl;
}


int getMaxmoutian2(int a[], int n)
{
	return 0;
}