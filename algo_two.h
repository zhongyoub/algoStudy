#pragma once
#include <vector>
using namespace std;

/*
��100Ԫ����1Ԫ��2Ԫ��5Ԫ��10Ԫ,�ж����ֻ���
(1)������ȫ�����ı��壬�ݹ鷽�����õ�ǰ���ֱ�ֵ���Ͳ�������»�
*/
const int N = 100;
const int dimes[] = { 1,2,5,10 };   //�˴�������const


int coinChange1(int amount);
/*
amount: total money
kinds:  the kind of money
��Ϊ���������벻�������֣�coc(A, [C1, C2��Cn])=coc(A-C1, [C1, C2��Cn]) + coc(A, [C2, C3��Cn]);
*/
int coinExchangeRecursion(int amount, int cashlist[], int n);

int coinExchangeRecursion2(int n, int m); //�ݹ鷽ʽʵ�֣��������

/*
��̬�滮����
dp[i][j]��ǰi��Ӳ�Ҷһ���Ǯ��Ϊjʱ���ܵ������
��ʾѡ���i��a[i]�벻ѡ���i��a[i]
dp[i][j]=dp[i-1][j]                 if j<a[i]
dp[i][j]=dp[i-1][j]+dp[i][j-a[i]]   if j>=a[i]
num: total+1
dp[n][total+1]
*/
int coinExchange3(int total, int cashList[], int n, int *dp[], int num);


/*
����Ǯ x, Ӳ�ң�c1,c2..)����λ�ʹ��Ӳ�������٣�����������ܶһ��ɹ���return -1
*/
int coinExchange4(int amount, vector<int> &coins);