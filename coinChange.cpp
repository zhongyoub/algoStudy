/*
给定一些可用的硬币值，如1，2，5，19，又给了一个钱数，最少用几个硬币换算
*/
#include<iomanip>
#include<iostream>
using namespace std;

int coin_value[] = { 1, 2, 5, 10 };
int coin_count[] = { 0, 0, 0, 0 };
int entry_count;
int* matrix;
int cc(int money, int coin_type, int lr)
{
	int val = 0;
	int vala = 0;
	int valb = 0;
	entry_count++;
	//    cout<<"("<< setw(4) <<money<<","<< setw(4) <<coin_value[coin_type]<<")  ==> ";
	if (lr == 0)
	{
		int a = sizeof(coin_count);
		memset(coin_count, 0, sizeof(coin_count));
	}
	if (money == 0)
	{
		val = 1;
	}
	else if ((money < 0) || (coin_type == 0))
	{
		val = 0;
	}
	//    else if (matrix[money*6+coin_type] >=0)
	//    {
	//        val = matrix[money*6+coin_type];
	//    }
	else
	{
		vala = cc(money, coin_type - 1, 0);
		valb = cc(money - coin_value[coin_type-1], coin_type, 1);
		val = vala + valb;
		if (vala == 0) 
			coin_count[coin_type] += valb;
		else           
			coin_count[coin_type] = valb;
		if (money >= 0)
			matrix[money * 4 + coin_type] = val;
	}

	//    cout<<"("<< setw(4) <<money<<","<< setw(4) <<coin_value[coin_type]<<", ";
	//    cout<<setw(4) << val <<", "<<(lr==0? "left" :"right") <<")"<<endl;
	return val;
}

int main()
{
	int money = 100;
	matrix = new int[(money + 1) * sizeof(coin_value) / sizeof(int)];
	memset(matrix, -1, (money + 1) * sizeof(coin_value));
	entry_count = 0;
	cout << "method = " << cc(money, 4, 0);
	cout << ", calls= " << entry_count << endl;
	delete[] matrix;
	system("pause");
	return 0;
}
