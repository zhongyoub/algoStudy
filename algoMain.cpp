#include "algo_one.h"
#include "algo_two.h"
#include "algo_three.h"
#include "algo_four.h"
#include "common.h"
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int a[] = { 2,0,1,4,7,3,2,1,5 };
	int num = 0;
//	num = getMaxMoutain(a, 8);
//	struct Node head, first, second;
//	head.data = 10, first.data = 5, second.data= 15;
//	head.next = &first, first.next = &second, second.next = NULL;
//	num = getTailk2(&head, 3);

	vector<int> coins(3);
	coins.push_back(1);
	coins.push_back(5);
	coins.push_back(2);
	num = coinExchange4(11, coins);
	cout << num << endl;
	system("pause");
	return 0;
}