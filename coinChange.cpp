/*
换零钱：给定k种面值的硬币，面值分别为c1, c2....，每种硬币的数量无限，在给定一个总金额mount，问有多少种组合方式
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
		vala = cc(money, coin_type - 1, 0);    //不包含coin_value[coin_type-1]类的硬币
		valb = cc(money - coin_value[coin_type-1], coin_type, 1);  //包含coin_value[coin_type-1]类的硬币
		val = vala + valb;
		if (vala == 0) 
			coin_count[coin_type] += valb;
		else           
			coin_count[coin_type] = valb;
		if (money >= 0)
			matrix[money * 4 + coin_type] = val;    //matrix[money*4+coin_type]=dp[money][coin_type], 这里有四类硬币
	}
	//    cout<<"("<< setw(4) <<money<<","<< setw(4) <<coin_value[coin_type]<<", ";
	//    cout<<setw(4) << val <<", "<<(lr==0? "left" :"right") <<")"<<endl;
	return val;
}

/*
用个二维数组存储换硬币个数，横坐标是金钱，纵坐标是纸币。用 v[i][j] 表示。

如果 i == 0 或者 j == 0 ，那么当然是0了。
如果 i == 1 也就是说只用 1 元纸币，那么所以金额都是 1 种表示的方式。
如果 i == 2，也就说用 1 元或者 5 元。那就要分 3 种情况了
j < 5 ,金额小于 5 ，但起码有 1 元的换零方式，所以 v[i][j] = v[i-1][j]了。
j >= 5 ,说明换零的方式中有5 元纸币，所以 v[i][j] = v[i-1][j]  + v[i][j-5]
如果 i== 3, 也是相类似的。
*/
int count(int money) {
	vector<int> a = {1, 5, 10, 20, 50};

  	int v[a.size()][money + 1];
  	for (int i = 0; i < a.size(); i++) {
    	for (int j = 0; j < money + 1; j++) {
      		if (i == 0) {
        		v[i][j] = 1;
      		} else {
        		v[i][j] = v[i - 1][j];
        		if (j >= a[i]) {
          			v[i][j] += v[i][j - a[i]];
        }
      }
    }
  }
  return v[a.size() - 1][money];
}


/*
使用二位数组dp[i][j]表示硬币个数,其中横坐标i表示硬币面额coins[i]，纵坐标表示钱的总数，计算使用最少的硬币数的方案
(1)如果j==0，dp[i][j]=0;
(2)如果i==0，表示使用最小面额的，dp[i][j]=j/coins[i]
(3)如果j<coins[i],则dp[i][j]=dp[i-1][j]
(4)如果j>=coins[i],则dp[i][j]=min(dp[i-1][j], dp[i][j-coins[i]]+1)
*/
int coinChange(int money)
{
	vector<int>coins={1,2,5,10};
	int dp[a.size()][money+1];
	for(int i=0;i<a.size();i++)
		for(int j=0;j<money+1;j++)
		{
			if(j==0)
			{
				dp[i][j]==0;
				continue;
			}
			if(i==0)
				dp[i][j]=j/coins[i];
			else
			{
				if(j>conis[i])
					dp[i][j]=min(dp[i-1][j], dp[i][j-coins[i]]+1);
				else 
					dp[i][j]=dp[i-1][j];
			}
		}
	return dp[a.size{}-1][money+1];
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
