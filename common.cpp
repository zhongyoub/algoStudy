#include "common.h"


int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}


/*�����������ֵ*/
int max3(int i, int j, int k)
{
	if (i >= j && i >= k)
		return i;
	return max3(j, k, i);
}