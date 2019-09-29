#include "algo_two.h"
#include <iostream>
using namespace std;

/*
������
*/
int coinChange1(int amount)
{
	int m = 0;
	for (int i = 0; i <= amount / 1; i++)
		for (int j = 0; j <= (amount - i * 1) / 2; j++)
			for (int k = 0; k <= (amount - i * 1 - j * 2) / 5; k++)
				for (int l = 0; l <= (amount - i * 1 - j * 2 - k * 5) / 10; l++)
					if (amount == i + j * 2 + k * 5 + l * 10)
					{
						++m;
						cout << "1 yuan:" << i << ",     2 yuan:" << j << ", 5 yuan:" << k << ", 10 yuan:" << l << endl;
					}
	return m;
}

/*
amount: total money
kinds:  the kind of money
��Ϊ���������벻�������֣�coc(A, [C1, C2��Cn])=coc(A-C1, [C1, C2��Cn]) + coc(A, [C2, C3��Cn]);
*/
int coinExchangeRecursion(int amount, int cashlist[], int n)
{
	if (amount == 0)       //����
		return 1;
	else if (amount < 0)   // 0Ԫ
		return 0;
	// ֻ��һ��Ǯ
	if (n == 1)
	{
		if (amount % cashlist[n - 1] == 0)    //��������
			return 1;
		else
			return 0;
	}
	return coinExchangeRecursion(amount, cashlist, n - 1) + coinExchangeRecursion(amount - cashlist[n - 1], cashlist, n);
}

int coinExchangeRecursion2(int n, int m) //�ݹ鷽ʽʵ�֣��������
{
	if (n == 0)   //�����ݹ������
		return 1;
	if (n < 0 || m == 0)
		return 0;
	//��Ϊ�������:��ȡ��ǰ��ֵ����� + û�л�ȡ��ǰ��ֵ�����
	return (coinExchangeRecursion2(n, (m - 1)) + coinExchangeRecursion2(n - dimes[m - 1], m));
}
/*
��̬�滮����
dp[i][j]��ǰi��Ӳ�Ҷһ���Ǯ��Ϊjʱ���ܵ������
��ʾѡ���i��a[i]�벻ѡ���i��a[i]
dp[i][j]=dp[i-1][j]                 if j<a[i]
dp[i][j]=dp[i-1][j]+dp[i][j-a[i]]   if j>=a[i]
num: total+1
dp[n][total+1]
*/
int coinExchange3(int total, int cashList[], int n, int *dp[], int num)
{
	if (n < 0)
		return 0;
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			if (j >= cashList[i])
				dp[i][j] = dp[i - 1][j] + dp[i][j - cashList[i]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n - 1][num];
}


/*
����Ǯ x, Ӳ�ң�c1,c2..)�������ʹ��Ӳ�������٣�����������ܶһ��ɹ���return -1
*/