#include "common.h"


int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}


/*求三个数最大值*/
int max3(int i, int j, int k)
{
	if (i >= j && i >= k)
		return i;
	return max3(j, k, i);
}