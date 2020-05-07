/*
从给定的N个正整数中选取若干个数之和最接近M
(1)输出选取的子序列
(2)找出所有可能的组合
其中N<=10, M<=100
*/
 
#include <iostream>
#include <list>
using namespace std;

int state[11][101];   
int dp[101];        //存储子问题的解
int value[11];

list<int> seq;     //用于找出所有可能的组合

void findSeq(int sum, int index)
{
    if(sum<=0||index<0)
        return;
    if(sum==value[index])
    {
        seq.reverse();
        cout<<value[index];
        for(list<int>::iterator iter=seq.begin();iter !=seq.end();++iter)
        {
            cout<<*iter;
        }
        cout<<endl;
        seq.reverse();
    }
    seq.push_back(value[index]); 
    findSeq(sum-value[index], index-1);
    seq.pop_back();
    findSeq(sum, index-1);
}

/*
使用一维数组01背包
其中，state[11][101]记录路径
*/
int allocate1(int value[], int n, int N, int M)
{
    for(int i=0;i<N;i++)
    {
        for(int j=M;j>=value[i];--j)
        {
            int tmp=dp[j-value[i]]+value[i];
            if(tmp>dp[j])
            {
                dp[j]=tmp;
                state[i][j]=1;
            }
        }
    }
    return dp[M];
}

/*
state[i][j]:定义前i个数中选择k个数之和为j
第一个数的下表从1开始计算。
i=0，state[0][M]=0
M=0, state[i][0]=0
*/
int allocate2(int value[], int n, int N, int M)
{
    for(int i=0;i<=N;i++)
        state[i][0]=0;
    for(int j=0;j<=M;j++)
        state[0][j]=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(value[i]>j)
            {
                state[i][j]=state[i-1][j];
            }
            else
            {
                int tmp=state[i-1][j-value[i]]+value[i];
                state[i][j]=(tmp>state[i-1][j]) ? tmp: state[i-1][j];   // max{state[i-1][j], state[i-1,j-vi]+vi}
            }
        }
    }
    return state[N][M];
}
/*
如果第一个下标从0开始计算，则
i=0, state[0][M]= M>value[0]? value[0]: 0
M=0, state[i][0]=0;
*/
int allocate3(int value[], int n, int N, int M)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i>0)
            {
                state[i][j]=state[i-1][j];
                if(j>=value[i])
                {
                    int tmp=state[i-1][j-value[i]]+value[i];
                    state[i][j]=tmp>state[i][j] ? tmp: state[i][j];
                }
            }
            else
            {
                if(j>=value[0])
                    state[0][j]=value[0];
            }
        }
    }
    return state[N-1][M];   //返回值为最接近M的值
}

/*
每个桶中10条，20个桶取180条
定义f(i,j)为前i个桶中取j条鱼的方法数
f(i,j)=sum(f(i-1,j-k), 0<=k<=10)
*/
int dp_fish[21][200];       //前i个桶取j条鱼的方法数
int allocate(int bucketN, int fishN)
{
	for(int i=0; i<=10; i++)
		dp_fish[1][i]=1;       //每个桶中可以取0-10，分别对应一种方法
	for(int i=2; i<=bucketN; i++)
	{
		for(int j=0; j<=fishN; j++)
		{
			for(int k=0; k<=10 && j-k>0; k++)
				dp_fish[i][j]+=dp_fish[i-1][j-k];
		}
	}
	return dp_fish[bucketN][fishN];
}


int main(int argc, char **argv)
{
    int N, M;
    int i, j;
    cout<<"please input the N and the M"<<endl;
    cin>>N>>M;
    cout<<"please input the value"<<endl;
    for(i=0;i<N;i++)
        cin>>value[i];
    int result;
    result=allocate1(value,11,N,M);
    //result=allocate2(value,11,N,M);
    //result=allocate2(value,11, N, M);
    cout<<result<<endl;

    //输出方案
    i=N;
    j=M;
    while(i-->=0)
    {
        if(state[i][j]==1)
            cout<<value[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
            cout<<state[i][j]<<" ";
        cout<<endl;
    }
    //所有可能的组合
    findSeq(M, N-1);
}
