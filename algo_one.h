#pragma once

/*
������������кͣ������������
*/
int max_sequence(int arr[], int n);

/*�����������ֵ*/
int max3(int i, int j, int k);
/*
���η���⣬������������к�Ҫô������������벿�֣�Ҫô�����������Ұ벿�֣�Ҫô����������벿��
*/
int max_sequence2(int a[], int l, int r);

/*
��� ���������к�ֻ��������λ��0��n-1��ĳ��λ�ý�β��
(1)dp[i] = max{A[i], dp[i-1]+A[i]}
(2)������ɨ�����У����temp_sum���ӣ���max���£����temp_sum<0���Ժ������û�����ã������һ�������п�ʼ
*/
int max_sequence3(int a[], int n);